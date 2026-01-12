#ifndef _PID_H
#define _PID_H

typedef struct
{
    float SetValue;  // 目标值/参考值
    float ActValue;  // 实际反馈值
	float ActValue_1;// 实际值备份
    float KP;        // 比例系数
    float KI;        // 积分系数
    float KD;        // 微分系数
    float ek;        // 当前偏差
    float ek_1;      // 上一次偏差
    float ek_2;      // 上上次偏差
    float ek_sum;    // 偏差累计和
    float Sum_max;   // 积分累加最大值
    float Sum_min;   // 积分累加最小值
    float PIDmax;    // PID输出上限
    float PIDmin;    // PID输出下限
    float PIDout;    // PID最终输出值
}PID;

extern PID Deviation;
extern PID Angle;
extern PID Speed;
extern float KP2;
extern float Error;
extern float Speed_L,Speed_R;

float PID_Control_Pos(PID* pid);  //位置式PID
float PID_Control_Inc(PID* pid);  //增量式PID
void PID_Init(void);
void Deviation_PID_Count();       //偏移PID计算
void Speed_PID_Count();           //速度PID计算
void Angle_PID_Count();           //角速度PID计算

#endif