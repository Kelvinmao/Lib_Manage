//------------------------------------------------
//Title: CSearch_Book.h
//Type: Header file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------
#ifndef CSEARCH_BOOK_H_
#define CSEARCH_BOOK_H_

#include<list>
#include"CLibrary.h"
#include"Data_Structure.h"
using namespace std;

//This class should be the friend class of the CLibrary,because I'll use the classify_Tree!
//Defination of Search_Book class
class CSearch_Book{
private:
	list<Book> Cache;//To restore high-freq searching element(����Ƶ���ҵ��鼮���л���)
	vector<Book> result;//return the result of searching
public:
	CSearch_Book(){};
	//*******************************************************************************************
	//Title,Auth_name,Pub_Dep,CId,Book_Id can be search in the classify_Tree,to prove performance
	//*******************************************************************************************
	bool Search_By_Title(const CLibrary & lib,const string & title);
	bool Search_By_Auth_Name(const CLibrary & lib,const string & auth_Name);
	bool Search_By_Pub_Dep(const CLibrary & lib,const string & pub_Dep);
	bool Search_By_CId(const CLibrary & lib,const string & c_ID);
	bool Search_By_Book_Id(const list<Book> & lib,const string & book_ID);
	//*******************************************************************************************
	//These methods,when 'time' or 'price' and etc occurs in the signature,should give chances of 
	//choosing the low_bound and high_bound
	//Attention!!!! To check the domain is valid or not!
	//*******************************************************************************************
	bool Search_By_Pub_Time(const list<Book> & lib, const string & time_Low, const string & time_High);
	bool Search_By_book_Price(const list<Book> & lib, const string & price_Low, const string & price_High);
	bool Add_Book_Into_Cache(const Book & book);
};

#endif