//------------------------------------------------
//Title: CLibrary.h
//Type: Header file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<list>
#include<string>
#include"Data_Structure.h"
using namespace std;

#ifndef CLIBRARY_H_
#define CLIBRARY_H_

class CLibrary{
private:
	list<Book> Library;
	const string default_Path;//the default path of the configuration file
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