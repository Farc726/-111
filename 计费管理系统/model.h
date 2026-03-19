#pragma once
#include<time.h>


/*定义卡信息结构体*/
typedef struct card {
	char aName[18];//卡号
	char aPwd[8];//密码

	/*定义基本类型的数据变量*/
	int nStatus; //卡状态（0-未上机；1-正在上机；2-已注销；3-失效）
	float fTotalUse;//累计金额
	int nUseCount;//使用次数
	float fBalance;//余额
	int nDel;//删除标识（0-未删除，1-已删除）

	/*定义保存时间类型的变量*/
	time_t tStart;//开卡时间
	time_t tEnd;//截止时间
	time_t tLastTime;//最后使用时间
}Card;
Card card;