//------------------------------------------------
//Title: CBook.cpp
//Type: Source file
//Data: 2016-12-11
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include"Data_Structure.h"
#include"CBook.h"
#include"CLibrary.h"
using namespace std;

class CLibrary;
CBook::CBook(int & book_Num){
	book_num = book_Num;
	m_pBook = new Book[book_Num];
}

bool CBook::Input_Info(){
	//input the info of a struct book
	int index = 0;
	for (index = 0; index < book_num; ++index){
		cout << "��������Ŀ���" << endl;
		cin >> m_pBook[index].B_Id;
		cin.get();
		cout << "������������" << endl;
		getline(cin, m_pBook[index].A_Name);
		cout << "����������" << endl;
		getline(cin, m_pBook[index].B_Tit);
		cout << "����������" << endl;
		getline(cin, m_pBook[index].C_Id);
		cout << "���������������" << endl;
		getline(cin, m_pBook[index].P_Dep);
		cout << "�����뱾��۸�" << endl;
		cin >> m_pBook[index].B_Pri;
	}
	return true;
}

//This method is a friend function of the class CLibrary,so you can use it to modify "list<Book> Library"
//Fucking this!!!!
//Ϊɶ������������Ԫ�ࣿ����������Ԫ�����Ͳ��У�������holy shit������
bool CBook::Add_Book_Into_List(CLibrary & lib){
	int index = 0;
	for (index = 0; index < book_num; ++index)
		lib.Library.push_back(m_pBook[index]);
	return true;
}

