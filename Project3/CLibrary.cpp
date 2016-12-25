//------------------------------------------------
//Title: CLibrary.cpp
//Type: Source file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<fstream>
#include<sstream>
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
	}
	return true;
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

bool CLibrary::Load_Book_From_File(){
	ifstream fin("Book_Info.txt", ios_base::in);
	//考虑到一次把所有书读进一个大数组会造成崩溃，所以开一个100个string的数组循环写入，既保障了效率，也使程序不会崩溃
	string tmp[100];
	if (!fin.is_open()){
		cout << "无法打开图书信息文件" << endl;
		return false;
	}
	else{
		int count = 0;//计数变量，用于舍弃表头
		while (getline(fin, tmp[count%100]) && tmp[count%100].size() > 0){
				istringstream str(tmp[count % 100]);
				string tmp[8];
				int i = 0;
				for (string item; str >> item; i++)
					tmp[i] = item;
				Book * new_Book = new Book;
				new_Book->B_Id = stoi(tmp[0]);
				new_Book->B_Tit = tmp[1];
				new_Book->A_Name = tmp[2];
				new_Book->C_Id = tmp[3];
				new_Book->P_Dep = tmp[4];
				new_Book->B_Pri = stof(tmp[5]);
				new_Book->P_Tim = tmp[6];
				new_Book->b_Time = 30;
				new_Book->isBorrow = false;
				new_Book->B_surplus = 1;
				new_Book->isBorrow = (bool)(stoi(tmp[7]));
				Library.push_back((*new_Book));
				delete new_Book;
				count++;
		}
		fin.close();
		//test
		/*for (auto pos = Library.begin(); pos != Library.end(); ++pos){
			cout << pos->A_Name << endl << pos->B_Id << endl << pos->C_Id << endl << pos->P_Dep << endl << pos->B_Pri << endl;
		}*/
	}
	return true;
}