//------------------------------------------------
//Title: CAckTime.h
//Type: Header file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------
#include <iostream>
#include <ctime>
using namespace std;
typedef struct time {
	int tm_sec;     /* seconds after the minute - [0,59] */
	int tm_min;     /* minutes after the hour - [0,59] */
	int tm_hour;    /* hours since midnight - [0,23] */
	int tm_mday;    /* day of the month - [1,31] */
	int tm_mon;     /* months since January - [0,11] */
	int tm_year;    /* years since 1900 */
	int tm_wday;    /* days since Sunday - [0,6] */
	int tm_yday;    /* days since January 1 - [0,365] */
	int tm_isdst;   /* daylight savings time flag */
}tm;

class CAckTime{
private:
	const tm * m_Tm_Ptr;
public:
	void dsptime(const tm *); //输出时间。
};


int main(void)
{
	time_t nowtime;
	nowtime = time(NULL); //获取日历时间
	cout << nowtime << endl;  //输出nowtime

	struct tm *local, *gm;
	local = localtime(&nowtime);  //获取当前系统时间
	dsptime(local);
	gm = gmtime(&nowtime);  //获取格林尼治时间
	dsptime(gm);

	return 0;
}
void dsptime(const struct tm * ptm)
{
	char *pxq[] = { "日", "一", "二", "三", "四", "五", "六" };
	cout << ptm->tm_year + 1900 << "年" << ptm->tm_mon + 1 << "月" << ptm->tm_mday << "日 ";
	cout << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec << " ";
	cout << " 星期" << pxq[ptm->tm_wday] << " 当年的第" << ptm->tm_yday << "天 " << endl;
}



