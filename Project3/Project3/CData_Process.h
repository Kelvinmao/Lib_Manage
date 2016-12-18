//------------------------------------------------
//Title: CData_Process.h
//Type: Header file
//Data: 2016-12-08
//Written By: KelvinMao
//------------------------------------------------
#ifndef DATA_PROCESS_H_
#define DATA_PROCESS_H_

#include<iostream>
#include<algorithm>
#include<list>
#include"Data_Structure.h"
#include"CLibrary.h"
using namespace std;

//Defination of Data_Processor class
class CLibrary;
class CData_Processor{
public:
	CData_Processor();
	bool Constru_The_Header(const string & file_name = "Book_Info.txt");
	/************************************************************************************/
	//modified at 12/11,I don't think the Input_Info should be a member function of the
	//CData_Process,so I commented it, and create a new class named CBook
	//bool Input_Info(Book & book);// Ignore it!
	/************************************************************************************/
	bool Del_Info(const string & book_title);
	bool Change_Info(const string & book_title);
	/********************************************************************************************/
	/*To write the info successfully, you should make class CData_Processor be the friend of the
	class CLibrary.*/
	bool Save_Info_To_File(list<Book> & ls=CLibrary::Library,const string & file_name="Book_Info.txt");
};
#endif