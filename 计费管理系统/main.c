#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"menu.h"
void ShowMenu();
int main() {
	printf("计费管理系统\n");

	int nselection=-1;

	do {
//输出菜单(调用menu.c中的函数)
		ShowMenu();
//提示选择菜单编号
		printf("请选择菜单项编号（0~8）:");
//循环输入编号
		scanf_s("%d", &nselection);
//处理用户选项（调用menu.c中的函数）
		HandleMenuSelection(nselection);
	} while (nselection!=0);
	return 0;
}