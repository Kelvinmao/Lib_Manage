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
		cout << "请输入"<<"第"<<index+1<<"本书的书目编号" << endl;
		cin >> m_pBook[index].B_Id;
		cin.get();
		cout << "请输入"<<"第"<<index+1<<"本书的作者名" << endl;
		getline(cin, m_pBook[index].A_Name);
		cout << "请输入"<<"第"<<index+1<<"本书的书名" << endl;
		getline(cin, m_pBook[index].B_Tit);
		cout << "请输入"<<"第"<<index+1<<"本书的分类号" << endl;
		getline(cin, m_pBook[index].C_Id);
		cout << "请输入"<<"第"<<index+1<<"本书的出版社名称" << endl;
		getline(cin, m_pBook[index].P_Dep);
		cout << "请输入"<<"第"<<index+1<<"本书的价格" << endl;
		cin >> m_pBook[index].B_Pri;
		cout << "请输入" << "第" << index + 1 << "本书的出版日期" << endl;
		cin >> m_pBook[index].P_Tim;
	}
	return true;
}

//This method is a friend function of the class CLibrary,so you can use it to modify "list<Book> Library"
//Fucking this!!!!
//为啥必须声明成友元类？我声明成友元函数就不行！！！！
bool CBook::Add_Book_Into_List(CLibrary & lib){
	int index = 0;
	for (index = 0; index < book_num; ++index)
		lib.Library.push_back(m_pBook[index]);
	return true;
}
