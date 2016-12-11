//------------------------------------------------
//Title: CSearch_Book.h
//Type: Header file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------
#ifndef CSEARCH_BOOK_H_
#define CSEARCH_BOOK_H_

#include"Data_Structure.h"
#include<list>
using namespace std;


//Defination of Search_Book class
class CSearch_Book{
private:
	list<Book> Cache;//To restore high-freq searching element(将高频查找的书籍进行缓存)
public:
	CSearch_Book(){};
	bool Search_By_Title(const list<Book> & lib);
	bool Search_By_Auth_Name(const list<Book> & lib);
	bool Search_By_Pub_Dep(const list<Book> & lib);
	bool Search_By_Book_Id(const list<Book> & lib);
	bool Search_By_CId(const list<Book> & lib);
	//*******************************************************************************************
	//These methods,when 'time' or 'price' and etc occurs in the signature,should give chances of 
	//choosing the low_bound and high_bound
	//Attention!!!! To check the domain is valid or not!
	//*******************************************************************************************
	bool Search_By_Pub_Time(const list<Book> & lib, const string & time_Low, const string & time_High);
	bool Search_By_book_Price(const list<Book> & lib, const string & price_Low, const string & price_High);
};

#endif