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
		cout << "请输入" << "第" << index + 1 << "本书的最长借阅时间" << endl;
		cin >> m_pBook[index].b_Time;
		m_pBook[index].isBorrow = false;
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

vector<string> & CBook::Visit_Book_Title_In_Book_Vec(vector<string> & book_title){
	int index = 0;
	for (index; index < book_num; ++index)
		book_title.push_back(m_pBook[index].A_Name);
	//vector<string>::iterator i_pos = unique(book_title.begin(), book_title.end());
	//book_title.resize(distance(book_title.begin(), i_pos));
	return book_title;
}

vector<string> & CBook::Visit_Book_Title_In_Book_Vec_File(const CLibrary & lib, vector<string> & book_title){
	int index = 0;
	for (auto pos = lib.Library.begin(); pos != lib.Library.end(); ++pos)
		book_title.push_back(pos->B_Tit);
	//vector<string>::iterator i_pos = unique(book_title.begin(), book_title.end());
	//book_title.resize(distance(book_title.begin(), i_pos));
	return book_title;
}


vector<string> & CBook::Visit_Auth_Name_In_Book_Vec(vector<string> & auth_vec){
	int index = 0;
	for (index; index < book_num; ++index)
		auth_vec.push_back(m_pBook[index].A_Name);
	//vector<string>::iterator i_pos = unique(auth_vec.begin(), auth_vec.end());
	//auth_vec.resize(distance(auth_vec.begin(), i_pos));
	return auth_vec;
}

vector<string> & CBook::Visit_Auth_Name_In_Book_Vec_File(const CLibrary & lib,vector<string> & auth_vec){
	int index = 0;
	for (auto pos = lib.Library.begin(); pos != lib.Library.end();++pos)
		auth_vec.push_back(pos->A_Name);
	//vector<string>::iterator i_pos = unique(auth_vec.begin(), auth_vec.end());
	//auth_vec.resize(distance(auth_vec.begin(), i_pos));
	return auth_vec;
}

vector<string> & CBook::Visit_Pub_Dep_In_Book_Vec(vector<string> & Pub_vec){
	int index = 0;
	for (index; index < book_num; ++index)
		Pub_vec.push_back(m_pBook[index].P_Dep);
	//vector<string>::iterator i_pos = unique(Pub_vec.begin(), Pub_vec.end());
	//Pub_vec.resize(distance(Pub_vec.begin(), i_pos));
	return Pub_vec;
}

vector<string> & CBook::Visit_Pub_Dep_In_Book_Vec_File(const CLibrary & lib, vector<string> & Pub_vec){
	int index = 0;
	for (auto pos = lib.Library.begin(); pos != lib.Library.end(); ++pos)
		Pub_vec.push_back(pos->P_Dep);
	//vector<string>::iterator i_pos = unique(Pub_vec.begin(), Pub_vec.end());
	//Pub_vec.resize(distance(Pub_vec.begin(), i_pos));
	return Pub_vec;
}

vector<string> & CBook::Visit_cID_In_Book_Vec(vector<string> & cid_vec){
	int index = 0;
	for (index; index < book_num; ++index)
		cid_vec.push_back(m_pBook[index].C_Id);
	//vector<string>::iterator i_pos = unique(cid_vec.begin(), cid_vec.end());
	//cid_vec.resize(distance(cid_vec.begin(), i_pos));
	return cid_vec;
}

vector<string> & CBook::Visit_cID_In_Book_Vec_File(const CLibrary & lib, vector<string> & cID_vec){
	int index = 0;
	for (auto pos = lib.Library.begin(); pos != lib.Library.end(); ++pos)
		cID_vec.push_back(pos->C_Id);
	//vector<string>::iterator i_pos = unique(cID_vec.begin(), cID_vec.end());
	//cID_vec.resize(distance(cID_vec.begin(), i_pos));
	return cID_vec;
}