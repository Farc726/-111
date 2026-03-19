#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>//包含输入输出头文件
#include"menu.h"
#include"model.h"
#include"card_service.h"
#include"tool.h"

void ShowMenu() {
	printf("------菜单------\n");
	printf("1.添加卡\n");
	printf("2.查询卡\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.查询统计\n");
	printf("8.注销卡\n");
	printf("0.退出\n");
}
void HandleMenuSelection(int nselection) {
	switch (nselection) {
	case 1: printf("添加卡\n"); 
		add();
		break;
	case 2: printf("查询卡\n");
		query();
		break;
	case 3: printf("上机\n"); break;
	case 4: printf("下机\n"); break;
	case 5: printf("充值\n"); break;
	case 6: printf("退费\n"); break;
	case 7: printf("查询统计\n"); break;
	case 8: printf("注销卡\n"); break;
	case 0: printf("退出\n"); break;
	default: printf("输入的菜单序号错误！"); break;
	}
}
//添加卡
void add() {
	Card card;
	int nNameSize=0;
	int nPwdSize = 0;
	char aName[32] = {'\0'}	;
	char aPwd[20] = { '\0' };
	//附加 之后再看看哪里错了
	//struct tm* starttime=localtime(&card.tStart);//开卡时间
	//struct tm* endtime=localtime(&card.tEnd);//截止时间
	//endtime->tm_year = starttime->tm_year + 1;//根据开卡时间 计算截止时间
	//card.tEnd = mktime(endtime);//
	printf("--------添加卡--------\n");
	
	printf("请输入卡号：");
	scanf("%s",aName);
	printf("请输入密码：");
	scanf("%s",aPwd);

//判断卡号密码的长度
	nNameSize = getSize(aName);
	nPwdSize = getSize(aPwd);
	if (nNameSize > 18 || nPwdSize > 8) {
		printf("卡号超过目标长度！");
		return;
	}
	else {
		strcpy(card.aName, aName);
		strcpy(card.aPwd,aPwd);
	}

	printf("请输入开卡金额：");
	scanf_s("%f",&card.fBalance);
	card.fTotalUse = card.fBalance;
	card.nUseCount = 0;
	card.nStatus = 0;
	card.nDel = 0;

	card.tStart = card.tEnd = card.tLastTime = time(NULL);
	addCard(card);
	printf("-----添加的卡信息如下：-----\n");
	printf("卡号\t密码\t卡状态\t余额\n");
	printf("%s\t%s\t%d\t%0.f\n", card.aName, card.aPwd, card.nStatus, card.fBalance);
}

//计算长度
int getSize(const char* pInfo) {
	//计算指针变量pInfo 所指向的字符串的长度
	int nSize = 0;
	while (*(pInfo + nSize) != '\0') {
		nSize++;
	}
	//return 字符串的长度
	return nSize;
}

void query() {
	char aName[18] = { 0 };
	char aTime[20] = { 0 };
	Card* pCard = NULL;
	printf("请输入查询的卡号：");
	scanf("%s",aName);
	pCard = queryCard(aName);
	if (pCard == NULL) {
		printf("未找到该卡号，请先添加此卡！");
		return;
	}
	//将时间转化为字符串
	timeToString(pCard->tLastTime, aTime);
	//显示
	printf("查询到的卡信息如下\n");
	printf("卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");
	printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n",pCard->aName,pCard->nStatus,pCard->fBalance,pCard->fTotalUse,pCard->nUseCount,aTime);
}
