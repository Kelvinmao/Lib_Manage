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
	void dsptime(const tm *); //���ʱ�䡣
};


int main(void)
{
	time_t nowtime;
	nowtime = time(NULL); //��ȡ����ʱ��
	cout << nowtime << endl;  //���nowtime

	struct tm *local, *gm;
	local = localtime(&nowtime);  //��ȡ��ǰϵͳʱ��
	dsptime(local);
	gm = gmtime(&nowtime);  //��ȡ��������ʱ��
	dsptime(gm);

	return 0;
}
void dsptime(const struct tm * ptm)
{
	char *pxq[] = { "��", "һ", "��", "��", "��", "��", "��" };
	cout << ptm->tm_year + 1900 << "��" << ptm->tm_mon + 1 << "��" << ptm->tm_mday << "�� ";
	cout << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec << " ";
	cout << " ����" << pxq[ptm->tm_wday] << " ����ĵ�" << ptm->tm_yday << "�� " << endl;
}



