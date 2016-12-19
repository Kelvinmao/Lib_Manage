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

#ifndef DATA_PROCESS_H_
#define DATA_PROCESS_H_

//Defination of Data_Processor class
class CData_Processor{
public:
	CData_Processor();
	bool Constru_The_Header(const string & file_name = "Book_Info.txt");
	bool Input_Info(Book & book);
	bool Del_Info(const string & book_title);
	bool Change_Info(const string & book_title);
	bool Save_Info_To_File(const list<Book> &, const string & file_name="Book_Info.txt");
};
#endif