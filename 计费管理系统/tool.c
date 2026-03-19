#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
//只是工具 用于时间转化(将time_t类型转化为字符串，字符串格式为“年-月-日 时：分”)
void timeToString(time_t t, char* pBuf) {
	struct tm* pTimeInfo;
	pTimeInfo = localtime(&t);
	strftime(pBuf, 20, "%Y-%m-%d %H:%M", pTimeInfo);
}