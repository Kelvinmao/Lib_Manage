//------------------------------------------------
//Title: CLogIn_Out.cpp
//Type: Source file
//Data: 2016-12-25
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<fstream>
#include<sstream>
#include"Data_Structure.h"
#include"CLogIn_Out.h"
#include"CPassword.h"
#include"CLibrary.h"
#include"CReader.h"
using namespace std;

class CReader;
Password password;
bool CLogin_Out::choose_User_Type(){
	cout << "请选择您的用户类型:" << endl;
	cout << "1.管理员" << endl << "2.用户" <<endl<<"3.新用户注册"<< endl;
	cin >> user_Type;
	char tmp;
	tmp = getchar();
	return true;
}

bool CLogin_Out::admin_Login(){
	string admin_Name;
	string admin_Password;
	string admin_Info[4];
	ifstream fin("Lib_Info.txt", ios_base::in);
	if (!fin.is_open()){
		cout << "图书馆信息文件打开失败" << endl;
		return false;
	}
	cout << "请输入您的用户名" << endl;
	cin >> admin_Name;
	char tmp = getchar();
	/*cout << "请输入您的密码" << endl;*/
	password.inputPassword();
	admin_Password = password.getPassword();
	int count = 0;
	/*for (int i = 0; i < 4; i++)
		cout << admin_Info[i];*/
	for (int i = 0; i < 4 && admin_Info[i].size()>0; ++i)
		getline(fin, admin_Info[i]);
	if (admin_Info[2] == admin_Name && admin_Info[3] == admin_Password)
		admin_flag = true;
	fin.close();
	return true;
}

bool CLogin_Out::admin_Logout(){
	if (admin_flag == false){
		cout << "您还未登录" << endl;
		return false;
	}
	else{
		admin_flag = false;
	}
	return false;
}

bool CLogin_Out::reader_Login(CLibrary & lib){
	string reader_name;
	string reader_password;
	cout << "请输入您的用户名" << endl;
	cin >> reader_name;
	char tmp = getchar();
	/*cout << "请输入密码" << endl;*/
	password.inputPassword();
	reader_password = password.getPassword();
	vector<CReader>::iterator c_iter= lib.readers_Vec.begin();
	for (c_iter; c_iter != lib.readers_Vec.end(); ++c_iter){
		if (c_iter->get_Reader_Name() == reader_name && c_iter->get_Reader_Password() == reader_password)
			reader_flag = true;
	}
	return true;
}

//这个方法让我再考虑考虑
bool CLogin_Out::reader_Logout(const CLibrary & lib){
	return true;
}

