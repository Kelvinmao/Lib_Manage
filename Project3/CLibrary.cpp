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
	cout << "��ӭʹ��ͼ�����Ϣ����ϵͳ" << endl;
	ifstream fin("Lib_Info.txt",ios_base::in);
	if (fin.peek()==EOF)
		cout << "��⵽���ǵ�һ��ʹ�ñ�ϵͳ�����Ƚ��������Ϣ��¼��" << endl;
}

bool CLibrary::Show_Info(const string & lib_name, const string & date, const string & admin_name){
	cout << "��ȷ����������" << endl;
	cout << "ͼ�����:" << lib_name << endl;
	cout << "��������:" << date << endl;
	cout << "����Ա�û���:" << admin_name << endl;
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
		cout << "δ�ܳɹ��������ļ�" << endl;
		return false;
	}
	if (fin.peek()==EOF){
		cout << "������ͼ�����:" << endl;
		cin >> lib_Name;
		cout << "�����봴������" << endl;
		cin >> date;
		cout << "���������Ա�û���" << endl;
		cin >> admin_Name;
		cout << "���������Ա����" << endl;
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
		cout << "δ�ܳɹ��������ļ�" << endl;
		return false;
	}
	while (getline(fin, tmp) && tmp.size() > 0)
		fout << tmp << endl;
	fout.close();
	fin.close();
	cout << "�ⲿ�����ļ��������" << endl;
	system("pause");
	return true;
}

bool CLibrary::Change_Info(){
	ifstream fin("Lib_Info.txt");
	vector<string> info;
	string tmp;
	cout << "������Ҫ���ĵ���Ŀ,���ϵ�������Ϊ1~4����������ֵ" << endl;
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
		cout << "�������������Ƿ���ȷ" << endl;
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
	cout << "�����ļ�����Ϊ:" << endl;
	while (fin >> str)
		cout << str << endl;
	return true;
}

bool CLibrary::Load_Book_From_File(){
	ifstream fin("Book_Info.txt", ios_base::in);
	//���ǵ�һ�ΰ����������һ�����������ɱ��������Կ�һ��100��string������ѭ��д�룬�ȱ�����Ч�ʣ�Ҳʹ���򲻻����
	string tmp[100];
	if (!fin.is_open()){
		cout << "�޷���ͼ����Ϣ�ļ�" << endl;
		return false;
	}
	else{
		int count = 0;//��������������������ͷ
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