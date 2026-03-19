#ifndef MENU_H//<标识符>
#define MENU_H//<程序段一>

//显示菜单的函数声明
void ShowMenu();
//处理菜单选择的函数声明
void HandleMenuSelection(int nselection);
//添加卡函数声明
void add();
int getSize(const char* pInfo);
void query();
#endif // !MENU_H
//如果标识符没有定义 那么执行程序段一定义MENU.H 如果已经定义则结束，不会再编译menu.h文件

