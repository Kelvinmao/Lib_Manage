//------------------------------------------------
//Title: CData_Process.h
//Type: Header file
//Data: 2016-12-08
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<algorithm>
#include<list>
#include"Data_Structure.h"

using namespace std;

ofstream fout;
//Defination of Data_Processer class
class CData_Processer{
private:
	list<struct Book> library;
public:
	CData_Processer(){};
	bool Input_Info(struct Book & book, const string * str_arr);
	bool Del_Info(const string & book_title);
	bool Change_Info(const string & book_title);
};

//Defination of Search_Book class
class CSearch_Book{
private:
	list<struct Book> Cache;//To restore high-freq searching element(将高频查找的书籍进行缓存)
public:
	CSearch_Book(){};
	bool Search_By_Title(const list<struct Book> & lib);
	bool Search_By_Auth_Name(const list<struct Book> & lib);
	bool Search_By_Pub_Dep(const list<struct Book> & lib);
	bool Search_By_Book_Id(const list<struct Book> & lib);
	bool Search_By_CId(const list<struct Book> & lib);
	//*******************************************************************************************
	//These methods,when 'time' or 'price' and etc occurs in the signature,should give chances of 
	//choosing the low_bound and high_bound
	//Attention!!!! To check the domain is valid or not!
	//*******************************************************************************************
	bool Search_By_Pub_Time(const list<struct Book> & lib,const string & time_Low,const string & time_High);
	bool Search_By_book_Price(const list<struct Book> & lib,const string & price_Low,const string & price_High);
};