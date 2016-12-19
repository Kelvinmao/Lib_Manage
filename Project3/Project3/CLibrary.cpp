//------------------------------------------------
//Title: CLibrary.cpp
//Type: Source file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<fstream>
#include<string>
#include"CLibrary.h"
using namespace std;

CLibrary::CLibrary(){
	cout << "欢迎使用图书馆信息管理系统" << endl;
	ifstream fin("Lib_Info.txt",ios_base::in);
	if (fin.peek()==EOF)
		cout << "检测到您是第一次使用本系统，请先进行相关信息的录入" << endl;
}

bool CLibrary::Show_Info(const string & lib_name, const string & date, const string & admin_name){
	cout << "请确认您的输入" << endl;
	cout << "图书馆名:" << lib_name << endl;
	cout << "创建日期:" << date << endl;
	cout << "管理员用户名:" << admin_name << endl;
	return true;
}

bool CLibrary::Set_And_Save_Info(){
	string lib_Name;
	string date;
	string admin_Name;
	string admin_Pass;
	ofstream fout("Lib_Info.txt", ios_base::app);
	ifstream fin("Lib_Info.txt");
	if (!fout.is_open()){
		cout << "未能成功打开配置文件" << endl;
		return false;
	}
	if (fin.peek()==EOF){
		cout << "请输入图书馆名:" << endl;
		cin >> lib_Name;
		cout << "请输入创建日期" << endl;
		cin >> date;
		cout << "请输入管理员用户名" << endl;
		cin >> admin_Name;
		cout << "请输入管理员密码" << endl;
		cin >> admin_Pass;
		Show_Info(lib_Name, date, admin_Name);

		//Write into the file
		fout << lib_Name << endl;
		fout << date << endl;
		fout << admin_Name << endl;
		fout << admin_Pass << endl;
		fout.close();
		system("pause");
		return true;
	}
}

bool CLibrary::Load_Info(const string & file_Path){
	ifstream fin(file_Path);
	ofstream fout("Lib_Info.txt");
	string tmp;
	if (!fin.is_open()){
		cout << "未能成功打开配置文件" << endl;
		return false;
	}
	while (getline(fin, tmp) && tmp.size() > 0)
		fout << tmp << endl;
	fout.close();
	fin.close();
	cout << "外部配置文件导入完成" << endl;
	system("pause");
	return true;
}

bool CLibrary::Change_Info(){
	ifstream fin("Lib_Info.txt");
	vector<string> info;
	string tmp;
	cout << "请输入要更改的项目,从上到下依次为1~4。并输入新值" << endl;
	int item = 0;
	string new_value;
	cin >> item;
	cin >> new_value;
	while (getline(fin, tmp))
		info.push_back(tmp);
	switch (item)
	{
	case 1:
		info[0] = new_value;
		break;
	case 2:
		info[1] = new_value;
		break;
	case 3:
		info[2] = new_value;
		break;
	case 4:
		info[3] = new_value;
		break;
	default:
		cout << "请检查您的输入是否正确" << endl;
	}
	fin.close();
	ofstream fout("Lib_Info.txt");
	for (vector<string>::iterator pos = info.begin(); pos != info.end(); pos++)
		fout << (*pos) << endl;
	fout.close();
	return true;
}

bool CLibrary::Show_Info_From_File(){
	ifstream fin("Lib_Info.txt");
	string str;
	cout << "配置文件内容为:" << endl;
	while (fin >> str)
		cout << str << endl;
	return true;
}

//****************************************************************
//这个方法让我再斟酌一下要不要加，配置文件的存储位置可以由用户指定似乎有些不妥
//bool CLibrary::Change_Path(const string & usr_File_Path){
//	if (usr_File_Path.empty()){
//		cout << "路径不能为空，请重新输入" << endl;
//	}
//	
//}
//****************************************************************