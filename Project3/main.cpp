#include<iostream>
#include<cstdlib>
#include"CData_Processor.h"
#include"Data_Structure.h"
#include"CSearch_Book.h"
#include"CLogIn_Out.h"
#include"CLibrary.h"
#include"CBook.h"
#include"CSort.h"
using namespace std;

int main(void){
	CLibrary lib;
	CData_Processor D_pro;
	CSearch_Book searcher;
	CReader reader("2015210983","kelvin", "392357160@qq.com", "18146567626","bupt123");
	CBook books;
	CLogin_Out user_log;

	lib.Load_Book_From_File();
	vector<string> title_vec;
	vector<string> auth_vec;
	vector<string> pub_vec;
	vector<string> cid_vec;
	books.Visit_Book_Title_In_Book_Vec_File(lib, title_vec);
	books.Visit_Auth_Name_In_Book_Vec_File(lib,auth_vec);
	books.Visit_Pub_Dep_In_Book_Vec_File(lib,pub_vec);
	books.Visit_cID_In_Book_Vec_File(lib,cid_vec);
	Book * book_vec = books.Get_Book_Vec();
	//cout << auth_vec.size() << endl;
	//cout << pub_vec.size() << endl;
	D_pro.Init_Classify_Tree(lib);
	for (int i = 0; i < auth_vec.size(); ++i){
		D_pro.Classify_Book_By_Title(lib, title_vec[i]);
		D_pro.Classify_Book_By_Auth_Name(lib, auth_vec[i]);
		D_pro.Classify_Book_By_Pud_Dep(lib, pub_vec[i]);
		D_pro.Classify_Book_By_C_ID(lib, cid_vec[i]);
	}
	/*lib.push_reader_into_reader_vec(reader);
	reader.write_Readers_Info_Into_File(lib);*/
	lib.load_Readers_Info_From_File();
	cout << "尊敬的用户，您好，请先登录" << endl;
	user_log.choose_User_Type();
	if (user_log.get_User_Type() == 1)
		user_log.admin_Login();
	if (user_log.get_User_Type() == 2)
		user_log.reader_Login(lib);
	if (user_log.get_User_Type() == 3){
		CReader * new_reader = new CReader;
		new_reader->sign_Up_As_A_New_Reader(lib);
		delete new_reader;
		new_reader = nullptr;
		reader.write_Readers_Info_Into_File(lib);
		user_log.reader_Login(lib);
	}
	if (user_log.check_Admin_Login_State() || user_log.check_Reader_Login_State())
		system("cls");
	else
		cout << "用户名或密码有误" << endl;
	cout << "==========================欢迎使用图书馆信息管理系统：==========================" << endl;
	cout << "                              1.查询图书" << endl;
	cout << "                              2.借阅图书" << endl;
	cout << "                              3.归还图书" << endl;
	cout << "                              4.个人信息查询" << endl;
	cout << "                              5.续借图书" << endl;
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
	case 2:{
		cout << "请输入您需要的借阅方式" << endl;
		cout << "================================借阅方式====================================" << endl;
		cout << "                              1.使用书目编号借阅" << endl;
		cout << "                              2.使用标题借阅" << endl;
		cout << "                              3.使用作者借阅" << endl;
		cout << "                              4.使用出版社借阅" << endl;
		cout << "                              5.使用分类号借阅" << endl;
		cout << "请做出选择：" << endl;
		int borrow_method = 0;
		cin >> borrow_method;
		switch (borrow_method){
		case 1:{
			cout << "您选择的是按书目编号借阅" << endl;
			cout << "请输入您需要借阅的书目编号" << endl;
			Book_ID bid;
			cin >> bid;
			reader.borrow_Book_By_bID(lib, searcher, bid);
			break;
		}
		case 2:{
			cout << "您选择的是按标题借阅" << endl;
			cout << "请输入您需要借阅的书籍的标题" << endl;
			Book_Title title;
			cin >> title;
			reader.borrow_Book_By_Title(lib, searcher, title);
			break;
		}
		case 3:{
			cout << "您选择的是按作者借阅" << endl;
			cout << "请输入您需要借阅的书籍的作者" << endl;
			Auth_Name a_name;
			cin >> a_name;
			reader.borrow_Book_By_Auth(lib, searcher, a_name);
			break;
		}
		case 4:{
			cout << "您选择的是按出版社借阅" << endl;
			cout << "请输入您需要借阅的书籍的出版社" << endl;
			Pub_Dep p_dep;
			cin >> p_dep;
			reader.borrow_Book_By_pub_Dep(lib, searcher, p_dep);
			break;
		}
		case 5:{
			cout << "您选择的是按分类号借阅" << endl;
			cout << "请输入您需要借阅的书籍的分类号" << endl;
			Classify_ID cid;
			cin >> cid;
			reader.borrow_Book_By_cID(lib, searcher, cid);
			break;
		}
		default:{
			cout << "请检查您的输入" << endl;
		}
		}
			break;
	}
	case 3:{
		cout << "请输入您需要归还图书的书目编号" << endl;
		Book_ID bid;
		cin >> bid;
		reader.give_Back_Book(searcher, bid);
		break;
	}
	case 4:{
		cout << "请选择您需要的选项" << endl;
		cout << reader.get_Reader_Name() << ",你好" << endl;
		cout << "================================个人信息查询====================================" << endl;
		cout << "                              1.查询已借阅图书" << endl;
		cout << "                              2.修改预留邮箱" << endl;
		cout << "                              3.修改预留手机号码" << endl;
		cout << "                              4.修改用户名" << endl;
		cout << "                              5.修改密码" << endl;
		cout << "请做出选择：" << endl;
		int reader_method = 0;
		cin >> reader_method;
		switch (reader_method){
		case 1:{
			reader.show_All_Borrowed_Books();
			break;
		}
		case 2:{
			reader.change_Reader_Email_Addr();
			break;
		}
		case 3:{
			reader.change_Reader_Phone_Num();
			break;
		}
		case 4:{
			reader.change_Reader_Name();
			break;
		}
		case 5:{
			reader.change_Reader_Password();
			break;
		}
		default:{
			cout << "请检查您的输入" << endl;
		}
		}
		break;
	}
	case 0:{
		user_log.~CLogin_Out();
		if (user_log.check_Admin_Login_State() == false || user_log.check_Reader_Login_State() == false)
			cout << "注销成功，感谢您的使用" << endl;
		else
			cout << "注销失败" << endl;
		break;
	}
	}
}