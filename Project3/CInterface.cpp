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
	cout << "==========================欢迎使用图书馆后台管理系统：==========================" << endl;
	cout << "                              1.查询图书" << endl;
	cout << "                              2.图书管理" << endl;
	cout << "                              3.用户管理" << endl;
	cout << "                              4.日志查询" << endl;
	cout << "                              0.退出登录" << endl;
	cout << "请做出选择：" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice){
	case 1:{
		int sear_Method = 0;
		cout << "请输入您需要的查询方式" << endl;
		cout << "================================查询方式====================================" << endl;
		cout << "                              1.使用书目编号查询" << endl;
		cout << "                              2.使用标题查询" << endl;
		cout << "                              3.使用作者查询" << endl;
		cout << "                              4.使用出版社查询" << endl;
		cout << "                              5.使用分类号查询" << endl;
		cout << "                              6.使用出版时间范围进行查询" << endl;
		cout << "                              7.使用价格范围进行查询" << endl;
		cout << "请做出选择：" << endl;
		cin >> sear_Method;
		switch (sear_Method){
		case 1:{
			cout << "您选择的是按书目编号查询" << endl;
			Book_ID bid = 0;
			cout << "请输入您所需的书目编号" << endl;
			cin >> bid;
			searcher.Search_By_Book_Id(lib, bid);
			searcher.Show_Search_Result();
			break;
		}
		case 2:{
			cout << "您选择的是按标题查询" << endl;
			cout << "请输入您所需的图书标题" << endl;
			Book_Title b_title;
			cin >> b_title;
			searcher.Search_By_Title(lib, b_title);
			searcher.Show_Search_Result();
			break;
		}
		case 3:{
			cout << "您选择的是按作者查询" << endl;
			cout << "请输入您所需的作者" << endl;
			Auth_Name auth_name;
			cin >> auth_name;
			searcher.Search_By_Auth_Name(lib, auth_name);
			searcher.Show_Search_Result();
			break;
		}
		case 4:{
			cout << "您选择的是按出版社查询" << endl;
			cout << "请输入您所需的出版社" << endl;
			Pub_Dep pub_name;
			cin >> pub_name;
			searcher.Search_By_Pub_Dep(lib, pub_name);
			searcher.Show_Search_Result();
			break;
		}
		case 5:{
			cout << "您选择的是按分类号查询" << endl;
			cout << "请输入您所需的图书的分类号" << endl;
			Classify_ID cid;
			cin >> cid;
			searcher.Search_By_CId(lib, cid);
			searcher.Show_Search_Result();
			break;
		}
		case 6:{
			Pub_Tim time_l;
			Pub_Tim time_h;
			cout << "您选择的是使用出版时间范围进行查询" << endl;
			cout << "请输入您指定的最早出版时间" << endl;
			cin >> time_l;
			cout << "请输入您指定的最晚出版时间" << endl;
			cin >> time_h;
			searcher.Search_By_Pub_Time(lib, time_l, time_h);
			searcher.Show_Search_Result();
			break;
		}
		case 7:{
			Book_Price price_l;
			Book_Price price_h;
			cout << "您选择的是使用价格范围进行查询" << endl;
			cout << "请输入您指定的最低价格" << endl;
			cin >> price_l;
			cout << "请输入您指定的最高价格" << endl;
			cin >> price_h;
			searcher.Search_By_book_Price(lib, price_l, price_h);
			searcher.Show_Search_Result();
			break;
		}
		default:{
			cout << "您的输入有误" << endl;
		}
		}
		break;
	}
	}
}