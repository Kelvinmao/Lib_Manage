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
	cout << "1.����Ա" << endl << "2.�û�" <<endl<<"3.���û�ע��"<< endl;
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
		cout << "ͼ�����Ϣ�ļ���ʧ��" << endl;
		return false;
	}
	cout << "�����������û���" << endl;
	cin >> admin_Name;
	char tmp = getchar();
	/*cout << "��������������" << endl;*/
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
	char tmp = getchar();
	/*cout << "����������" << endl;*/
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

