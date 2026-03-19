#include<stdio.h>
#include<stdio.h>
#include"model.h"
#include"global.h"
Card aCard[50];
int nCount = 0;

int addCard(Card card) {
	aCard[nCount] = card;
	nCount++;
	return TRUE;
}
Card* queryCard(const char* pName) {
	//在结构体数组中查询卡号相同的卡信息
	for (int i = 0; i < nCount; i++) {
		if (strcmp(pName, aCard[i].aName) == 0) {
			//如果查到卡号相同的卡信息，则返回该卡信息的地址
			return &aCard[i];
		}
		
	 }
	
	return NULL;
}
