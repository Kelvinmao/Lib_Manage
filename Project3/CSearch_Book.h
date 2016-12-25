//------------------------------------------------
//Title: CSearch_Book.h
//Type: Header file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------
#ifndef CSEARCH_BOOK_H_
#define CSEARCH_BOOK_H_
#include<list>
#include"CReader.h"
#include"CLibrary.h"
#include"Data_Structure.h"
using namespace std;

class CReader;
//This class should be the friend class of the CLibrary,because I'll use the classify_Tree!
//Defination of Search_Book class
class CSearch_Book{
	friend class CReader;
private:
	int cache_Max;//The max amount of the element in the cache
	vector<Book> Cache;//To restore high-freq searching element(将高频查找的书籍进行缓存)
	vector<Book> result;//return the result of searching
	vector<list<Book>::iterator> iter_Vec;//The vector contains the iterator of the book in the CLibrary::Library.
	vector<Book *> ptr_Vec;//The vector contains the pointer of the book in the classyfy tree.
public:
	CSearch_Book(){};
	//*******************************************************************************************
	//Title,Auth_name,Pub_Dep,CId,Book_Id can be search in the classify_Tree,to prove performance
	//*******************************************************************************************
	bool Search_By_Title(CLibrary & lib,const string & title);
	bool Search_By_Auth_Name(CLibrary & lib,const string & auth_Name);
	bool Search_By_Pub_Dep(CLibrary & lib,const string & pub_Dep);
	bool Search_By_CId(CLibrary & lib,const string & c_ID);
	bool Search_By_Book_Id(CLibrary & lib,const Book_ID & book_ID);
	//*******************************************************************************************
	//These methods,when 'time' or 'price' and etc occurs in the signature,should give chances of 
	//choosing the low_bound and high_bound
	//Attention!!!! To check the domain is valid or not!
	//*******************************************************************************************
	bool Search_By_Pub_Time(const CLibrary & lib, const Pub_Tim & time_Low, const Pub_Tim & time_High);
	bool Search_By_book_Price(const CLibrary & lib, const Book_Price & price_Low, const Book_Price & price_High);
	bool Add_Book_Into_Cache(CLibrary & lib);
	bool Set_Max_Cache();//Set the max amount of elements in the cache.
	bool Read_From_Cache_File();
	bool Write_Cache_Into_File();
	bool Show_Search_Result();
	friend ofstream & operator <<(ofstream & fout,const Book & book);
};

#endif