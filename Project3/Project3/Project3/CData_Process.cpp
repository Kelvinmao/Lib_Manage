//------------------------------------------------
//Title: CData_Process.cpp
//Type: Source file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<fstream>
#include<ctime>
#include"CData_Process.h"
using namespace std;

CData_Processor::CData_Processor(){
	//��λ�ȡʱ��Ĵ�����Ҫ�޸�
	ofstream fout("log.txt");
	/*const struct tm * local=nullptr;
	char * time = asctime(local);
	string str(time);
	fout << time<<" ";*/
	fout << "CData_Processer's Constructor" << endl;
}

bool CData_Processor::Input_Info(Book & book){
	//input the info of a struct book
	cout << "��������Ŀ���" << endl;
	cin >> book.B_Id;
	cin.get();
	cout << "������������" << endl;
	getline(cin,book.A_Name);
	cout << "����������"<<endl;
	getline(cin, book.B_Tit);
	cout << "����������" << endl;
	getline(cin, book.C_Id);
	cout << "���������������" << endl;
	getline(cin, book.P_Dep);
	cout << "�����뱾��۸�" << endl;
	cin >> book.B_Pri;
	return true;
}

bool CData_Processor::Constru_The_Header(const string & file_name){
	ofstream fout(file_name);
	if (!fout.is_open()){
		cout << "�޷����鼮��Ϣ�ļ�������·��������" << endl;
		return false;
	}
	fout << "ͼ����      ";
	fout << "����      " ;
	fout << "������      ";
	fout << "�����      ";
	fout << "��������      ";
	fout << "����۸�      ";
	return true;
}

//Save the struct book into the file,and the default file path has already confirmed
bool CData_Processor::Save_Info_To_File(const list<Book> & Book_list,const string & File_Path){
	ofstream fout(File_Path,ios_base::app);
	if (!fout.is_open()){
		cout << "�޷��ҵ�ͼ����Ϣ�ļ�������·��������" << endl;
		return false;
	}
	
}