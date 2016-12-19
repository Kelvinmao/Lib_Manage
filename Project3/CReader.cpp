//------------------------------------------------
//Title: CReader.cpp
//Type: Source file
//Data: 2016-12-19
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<vector>
#include<list>
#include"Finder_Structures.h"
#include"Data_Structure.h"
#include"CSearch_Book.h"
#include"CLibrary.h"
#include"CReader.h"
using namespace std;

class CSearch_Book;
class CLibrary;
//book is from CSearch_Book::result
bool CReader::borrow_Book_By_Title(CLibrary & lib,const CSearch_Book & sear_Book,const Book_Title & book_Tit){
	vector<Book>::const_iterator pos;
	finder_Tit book_tit(book_Tit);
	pos = find_if(sear_Book.result.begin(), sear_Book.result.end(), book_tit);
	if (pos == sear_Book.result.end()){
		cout << "查询结果中不存在您指定的标题，请检查后重新输入" << endl;
		return false;
	}
	else{
		lib.Library.remove((*pos));
		cout << "借阅成功，请注意归还日期" << endl;
		return true;
	}
	return false;
}

bool CReader::borrow_Book_By_Auth(CLibrary & lib, const CSearch_Book & sear_Book, const Auth_Name & a_name){
	vector<Book>::const_iterator pos;
	finder_auth_Name auth_name(a_name);
	pos = find_if(sear_Book.result.begin(), sear_Book.result.end(), auth_name);
	if (pos == sear_Book.result.end()){
		cout << "查询结果中不存在您指定的作者，请检查后重新输入" << endl;
		return false;
	}
	else{
		lib.Library.remove((*pos));
		cout << "借阅成功，请注意归还日期" << endl;
		return true;
	}
	return false;
}

bool CReader::borrow_Book_By_bID(CLibrary & lib, const CSearch_Book & sear_Book, const Book_ID & bid){
	vector<Book>::const_iterator pos;
	finder_book_id book_id(bid);
	pos = find_if(sear_Book.result.begin(), sear_Book.result.end(), book_id);
	if (pos == sear_Book.result.end()){
		cout << "查询结果中不存在您指定的书目编号，请检查后重新输入" << endl;
		return false;
	}
	else{
		lib.Library.remove((*pos));
		cout << "借阅成功，请注意归还日期" << endl;
		return true;
	}
	return false;
}

bool CReader::borrow_Book_By_Pub_Time(CLibrary & lib, const CSearch_Book & sear_Book, const Pub_Tim & p_time){
	vector<Book>::const_iterator pos;
	finder_pub_time pub_time(p_time);
	pos = find_if(sear_Book.result.begin(), sear_Book.result.end(), pub_time);
	if (pos == sear_Book.result.end()){
		cout << "查询结果中不存在您指定的出版日期，请检查后重新输入" << endl;
		return false;
	}
	else{
		lib.Library.remove((*pos));
		cout << "借阅成功，请注意归还日期" << endl;
		return true;
	}
	return false;
}

