//------------------------------------------------
//Title: CLibrary.h
//Type: Header file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------
#ifndef CLIBRARY_H_
#define CLIBRARY_H_

#include<iostream>
#include<list>
#include<string>
#include"Data_Structure.h"
#include"CBook.h"
#include"CSort.h"
#include"CSearch_Book.h"
#include"CData_Processor.h"
using namespace std;

//*************************************
/*A forward declare of CBook,
	for CBook::Add_Book_Into_List
		is a friend function of the CLibrary*/
/*CData_Process is same as CBook,so is CSort and CSearch_Book*/
//*************************************
class CData_Processor;
class CBook;
class CSort;
class CSearch_Book;
class CLibrary{
	friend class CBook;
	friend class CSort;
	friend class CSearch_Book;
	friend class CData_Processor;
private:
	list<Book> Library;
	const string default_Path;//the default path of the configuration file
	Classify_Tree classify_Tree;
public:
	CLibrary();
	bool Set_And_Save_Info(); //To Input the info of the library,like name,date and etc.
	bool Load_Info(const string & file_path);//Load infomation from configuration file
	bool Show_Info(const string &, const string &, const string &);//Show all info and let user check them.
	bool Change_Info();//Change the info
	bool Show_Info_From_File();
	/*bool Change_Path(const string & usr_Path_Name);*///Change the default path of the configuration file
};

#endif