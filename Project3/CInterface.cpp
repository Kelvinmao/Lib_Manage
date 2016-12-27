//------------------------------------------------
//Title: CInterface.cpp
//Type: Source file
//Data: 2016-12-27
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include"Data_Structure.h"
#include"CSearch_Book.h"
#include"CInterface.h"
#include"CLogIn_Out.h"
#include"CLibrary.h"
#define ADMIN 1
#define READER 0
using namespace std;


class CSearch_Book;
class CLogIn_Out;

int CInterface::judge_The_User_Type(const CLogin_Out & login){
	if (login.user_Type == 1)
		return ADMIN;
	if (login.user_Type == 2)
		return READER;
	else
		return;
}

bool CInterface::show_Admin_Interface(CSearch_Book & searcher,CLibrary & lib){
	cout << "==========================��ӭʹ��ͼ��ݺ�̨����ϵͳ��==========================" << endl;
	cout << "                              1.��ѯͼ��" << endl;
	cout << "                              2.ͼ�����" << endl;
	cout << "                              3.�û�����" << endl;
	cout << "                              4.��־��ѯ" << endl;
	cout << "                              0.�˳���¼" << endl;
	cout << "������ѡ��" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice){
	case 1:{
		int sear_Method = 0;
		cout << "����������Ҫ�Ĳ�ѯ��ʽ" << endl;
		cout << "================================��ѯ��ʽ====================================" << endl;
		cout << "                              1.ʹ����Ŀ��Ų�ѯ" << endl;
		cout << "                              2.ʹ�ñ����ѯ" << endl;
		cout << "                              3.ʹ�����߲�ѯ" << endl;
		cout << "                              4.ʹ�ó������ѯ" << endl;
		cout << "                              5.ʹ�÷���Ų�ѯ" << endl;
		cout << "                              6.ʹ�ó���ʱ�䷶Χ���в�ѯ" << endl;
		cout << "                              7.ʹ�ü۸�Χ���в�ѯ" << endl;
		cout << "������ѡ��" << endl;
		cin >> sear_Method;
		switch (sear_Method){
		case 1:{
			cout << "��ѡ����ǰ���Ŀ��Ų�ѯ" << endl;
			Book_ID bid = 0;
			cout << "���������������Ŀ���" << endl;
			cin >> bid;
			searcher.Search_By_Book_Id(lib, bid);
			searcher.Show_Search_Result();
			break;
		}
		case 2:{
			cout << "��ѡ����ǰ������ѯ" << endl;
			cout << "�������������ͼ�����" << endl;
			Book_Title b_title;
			cin >> b_title;
			searcher.Search_By_Title(lib, b_title);
			searcher.Show_Search_Result();
			break;
		}
		case 3:{
			cout << "��ѡ����ǰ����߲�ѯ" << endl;
			cout << "�����������������" << endl;
			Auth_Name auth_name;
			cin >> auth_name;
			searcher.Search_By_Auth_Name(lib, auth_name);
			searcher.Show_Search_Result();
			break;
		}
		case 4:{
			cout << "��ѡ����ǰ��������ѯ" << endl;
			cout << "������������ĳ�����" << endl;
			Pub_Dep pub_name;
			cin >> pub_name;
			searcher.Search_By_Pub_Dep(lib, pub_name);
			searcher.Show_Search_Result();
			break;
		}
		case 5:{
			cout << "��ѡ����ǰ�����Ų�ѯ" << endl;
			cout << "�������������ͼ��ķ����" << endl;
			Classify_ID cid;
			cin >> cid;
			searcher.Search_By_CId(lib, cid);
			searcher.Show_Search_Result();
			break;
		}
		case 6:{
			Pub_Tim time_l;
			Pub_Tim time_h;
			cout << "��ѡ�����ʹ�ó���ʱ�䷶Χ���в�ѯ" << endl;
			cout << "��������ָ�����������ʱ��" << endl;
			cin >> time_l;
			cout << "��������ָ�����������ʱ��" << endl;
			cin >> time_h;
			searcher.Search_By_Pub_Time(lib, time_l, time_h);
			searcher.Show_Search_Result();
			break;
		}
		case 7:{
			Book_Price price_l;
			Book_Price price_h;
			cout << "��ѡ�����ʹ�ü۸�Χ���в�ѯ" << endl;
			cout << "��������ָ������ͼ۸�" << endl;
			cin >> price_l;
			cout << "��������ָ������߼۸�" << endl;
			cin >> price_h;
			searcher.Search_By_book_Price(lib, price_l, price_h);
			searcher.Show_Search_Result();
			break;
		}
		default:{
			cout << "������������" << endl;
		}
		}
		break;
	}
	}
}