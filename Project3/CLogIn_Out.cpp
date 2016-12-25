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
	cout << "��ѡ�������û�����:" << endl;
	cout << "1.����Ա" << endl << "2.�û�" << endl;
	cin >> user_Type;
	return true;
}

bool CLogin_Out::admin_Login(){
	string admin_Name;
	string admin_Password;
	string admin_Info[4];
	ifstream fin("Lib_Info.txt", ios_base::in);
	cout << "�����������û���" << endl;
	cin >> admin_Name;
	cout << "��������������" << endl;
	password.inputPassword();
	admin_Password = password.getPassword();
	int count = 0;
	while (getline(fin, admin_Info[count]) && admin_Info[count].size() > 0)	++count;
	if (admin_Info[2] == admin_Name && admin_Info[3] == admin_Password)
		admin_flag = true;
	return true;
}

bool CLogin_Out::admin_Logout(){
	if (admin_flag == false){
		cout << "����δ��¼" << endl;
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
	cout << "�����������û���" << endl;
	cin >> reader_name;
	cout << "����������" << endl;
	password.inputPassword();
	reader_password = password.getPassword();
	vector<CReader>::iterator c_iter= lib.readers_Vec.begin();
	for (c_iter; c_iter != lib.readers_Vec.end(); ++c_iter){
		if (c_iter->get_Reader_Name() == reader_name && c_iter->get_Reader_Password() == reader_password)
			reader_flag = true;
	}
	return true;
}

//������������ٿ��ǿ���
bool CLogin_Out::reader_Logout(const CLibrary & lib){
	return true;
}

