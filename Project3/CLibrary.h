//------------------------------------------------
//Title: CLibrary.h
//Type: Header file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------
#ifndef CLIBRARY_H_
#define CLIBRARY_H_
#include<iostream>
#include<string>
#include<list>
#include"CData_Processor.h"
#include"Data_Structure.h"
#include"CSearch_Book.h"
#include"CReader.h"
#include"CBook.h"
#include"CSort.h"
using namespace std;

//*************************************
/*A forward declare of CBook,
	for CBook::Add_Book_Into_List
		is a friend function of the CLibrary*/
/*CData_Process is same as CBook,so is CSort and CSearch_Book*/
//*************************************
class CData_Processor;
class CSearch_Book;
class CReader;
class CBook;
class CSort;
class CLibrary{
	friend class CBook;
	friend class CSort;
	friend class CReader;
	friend class CLogin_Out;
	friend class CSearch_Book;
	friend class CData_Processor;
private:
	list<Book> Library;
	const string default_Path;//the default path of the configuration file
	list<Book> Tit_Branch;
	list<Book> Auth_Branch;
	list<Book> cID_Branch;
	list<Book> Pub_Dep_Branch;
	Classify_Tree classify_Tree;
	vector<string> reader_Names;//This vector contains all the reader's name
	vector<CReader> readers_Vec;
public:
	CLibrary();
	bool Set_And_Save_Info(); //To Input the info of the library,like name,date and etc.
	bool Load_Info(const string & file_path);//Load infomation from configuration file
	bool Show_Info(const string &, const string &, const string &);//Show all info and let user check them.
	bool Change_Info();//Change the info
	bool Show_Info_From_File();
	/*bool Change_Path(const string & usr_Path_Name);*///Change the default path of the configuration file
	bool Load_Book_From_File();
};

#endif