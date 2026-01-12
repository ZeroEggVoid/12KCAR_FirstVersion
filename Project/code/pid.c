#include "headfile.h"
PID Speed={0};                //速度PID控制器
PID Deviation={0};            //偏移量PID	纠偏
PID Angle={0};                //角速度PID控制器
float Speed_L=0,Speed_R=0;    //左轮速度、右轮速度
float Error=0;                //偏移误差值
float KD2=0;                  //偏移PID备用微分系数
float KP2=0;                  //偏移PID备用比例系数
float Difference_Speed=0;     //左右轮速度差值

//PID控制器参数初始化函数，配置所有PID的P/I/D系数及输出限幅
void PID_Init(void)
{
	Speed.KP=1;        //速度PID比例系数
    Speed.KI=0;        //速度PID积分系数
    Speed.KD=8;        //速度PID微分系数
    Speed.PIDmax=3000; //速度PID输出最大值限制
	Speed.PIDmin=-500; //速度PID输出最小值限制
	
	Deviation.KP=470;	//偏移PID比例系数
    Deviation.KI=0;    //偏移PID积分系数
    Deviation.KD=670;  //偏移PID微分系数
	Deviation.PIDmax=800;//偏移PID输出最大值限制
	
	Angle.KP=8;        //角速度PID比例系数
    Angle.KI=0.1;      //角速度PID积分系数
    Angle.KD=0;        //角速度PID微分系数
	Angle.PIDmax=6000; //角速度PID输出上限
	Angle.PIDmin=-6000;//角速度PID输出下限
}

//增量式PID算法实现函数
float PID_Control_Inc(PID* pid)  //增量式PID
{
    float inc;
    pid->ek = pid->SetValue - pid->ActValue;  //计算当前偏差 = 目标值 - 实际值
    //增量式PID核心计算公式：Δu(k)=Kp[e(k)-e(k-1)] + Ki*e(k) + Kd[e(k)-2e(k-1)+e(k-2)]
    inc = pid->KP * (pid->ek - pid->ek_1) + pid->KI * pid->ek+pid->KD*(pid->ek-2*pid->ek_1+pid->ek_2);//增量式
    pid->ek_2 = pid->ek_1;  //保存上上次偏差，迭代更新
    pid->ek_1 = pid->ek;    //保存上次偏差，迭代更新
    return inc;             //返回本次PID增量值
}

//位置式PID算法实现函数
float PID_Control_Pos(PID* pid)  //位置式PID
{
    float Pos ;
    pid->ek = pid->SetValue - pid->ActValue;  //计算当前偏差 = 目标值 - 实际值
    pid->ek_sum += pid->ek;                   //累计偏差值，积分项累加
    //位置式PID核心计算公式：u(k)=Kp*e(k)+Ki*Σe(k)+Kd[e(k)-e(k-1)]
    Pos = pid->KP * pid->ek + pid->KI * pid->ek_sum + pid->KD * (pid->ek - pid->ek_1);
    pid->ek_1 = pid->ek;    //保存上次偏差，迭代更新
    return Pos;             //返回本次PID位置输出值
}

//偏移量PID计算函数-直行纠偏控制
void Deviation_PID_Count()  //偏移PID计算
{		
	
   Error=Error_Count();     //获取当前偏移误差量
   Deviation.ActValue =Error;//将偏移误差赋值给PID实际反馈值，模拟量时注意换算，负号为反转
   Deviation.SetValue =  0;//偏移PID目标值：无偏移，保持直行

    //偏移PID最终输出 = 非线性补偿项 + 位置式PID输出值
    Deviation.PIDout=
		KP2*fabs(-Error)*(-Error)
	+
    PID_Control_Pos(&Deviation)
//    -0.15*imu660ra_gyro_z/16.4 //位置式PID增加陀螺仪的Z轴角速度，抑制自转
    ;
    //PID输出上限限幅，防止纠偏过度
	if(Deviation.PIDout > Deviation.PIDmax)
	{Deviation.PIDout =Deviation.PIDmax;}
     
}

//速度PID计算函数-左右轮速度闭环控制
void Speed_PID_Count()
{
	Speed_L=encoder_L_get();  //获取左轮编码器采集的速度值
	Speed_R=encoder_R_get();  //获取右轮编码器采集的速度值
    Speed.ActValue=(float)(Speed_L+Speed_R)*0.5; //速度PID实际值=左右轮平均速度
    Speed.SetValue=Expected_Speed;  //速度PID目标值=预设期望速度
    Speed.ek=Speed.SetValue-Speed.ActValue;  //计算当前速度偏差值
	Speed.ek_sum+=Speed.ek;  //速度偏差累加，积分项计算
    //速度PID输出增量计算，累加到原输出值上
    Speed.PIDout+=(Speed.ek*Speed.KP+(Speed.ek-Speed.ek_1)*Speed.KD)+Speed.KI*Speed.ek_sum;
	//偏差值迭代更新，供下一次计算使用
	Speed.ek_2=Speed.ek_1;
	Speed.ek_1=Speed.ek;
    //速度输出下限限幅，目标转速非零时防止电机堵转，预留占空比
    if((Speed.PIDout < Speed.PIDmin)&&(Target_Rate !=0))   
    Speed.PIDout = Speed.PIDmin;
    //速度输出上限限幅，防止输出过大
    if(Speed.PIDout> Speed.PIDmax )
    Speed.PIDout = Speed.PIDmax;    
}

//角速度PID计算函数-最终输出PWM控制量
void Angle_PID_Count()  //角速度-PWM
{	
    Angle.SetValue 	=  Deviation.PIDout;  //角速度PID目标值=偏移PID的纠偏输出值
	Angle.ActValue	=	gyroz;  //角速度PID实际值=陀螺仪Z轴角速度反馈值
    Angle.PIDout+=PID_Control_Inc(&Angle);  //累加增量PID值，更新最终输出
    //角速度输出上限限幅
	if(Angle.PIDout > Angle.PIDmax)
	{Angle.PIDout =Angle.PIDmax;}
    //角速度输出下限限幅
     if(Angle.PIDout <Angle.PIDmin)
	{ Angle.PIDout =Angle.PIDmin;}
}