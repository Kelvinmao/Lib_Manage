//------------------------------------------------
//Title: CData_Processor.h
//Type: Header file
//Data: 2016-12-08
//Written By: KelvinMao
//------------------------------------------------
#ifndef DATA_PROCESSOR_H_
#define DATA_PROCESSOR_H_

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
	CData_Processor(){}
	bool Constru_The_Header(const string & file_name = "Book_Info.txt");
	/************************************************************************************/
	//modified at 12/11,I don't think the Input_Info should be a member function of the
	//CData_Process,so I commented it, and create a new class named CBook
	/************************************************************************************/
	//bool Input_Info(Book & book);// Ignore it!
	bool Del_Info(const string & book_title);
	bool Change_Info(const string & book_title);
	/********************************************************************************************/
	/*To write the info successfully, you should make class CData_Processor be the friend of the
	class CLibrary.*/
	bool Save_Info_To_File(CLibrary & lib,const string & file_name="Book_Info.txt");
	/*Append following methods to classify books by some attributes on 2016-12-13*/
	bool Init_Classify_Tree(CLibrary & lib);//Initialize the classify tree
	bool Classify_Book_By_Title(const CLibrary & lib, const string & book_Title, Book & book);
	bool Classify_Book_By_Auth_Name(const CLibrary & lib, const string & auth_Name, Book & book);
	bool Classify_Book_By_C_ID(const CLibrary & lib, const string & classify_Id, Book & book);
	bool Classify_Book_By_Pud_Dep(const CLibrary & lib, const string & pub_Dep, Book & book);
	//Maybe it's neccessry to add a method for write the classify_Tree to File
	//TODO:Consider a proper format for the Classify_Tree in file
	bool Write_Classify_Tree_To_File(const CLibrary & lib, const string & file_Path);
};

#endif