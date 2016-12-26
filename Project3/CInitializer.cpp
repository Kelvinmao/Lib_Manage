//------------------------------------------------
//Title: CInitializer.cpp
//Type: Source file
//Data: 2016-12-26
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include"Data_Structure.h"
#include"CData_Processor.h"
#include"CSearch_Book.h"
#include"CInitializer.h"
#include"CLibrary.h"
#include"CReader.h"
#include"CBook.h"
using namespace std;

bool CInitializer::Initialize(
	CData_Processor & Data_processor,
	CSearch_Book & Book_Searcher,
	CLibrary & library,
	CReader & reader,
	CBook & book,
	vector<string> & title,
	vector<string> & auth,
	vector<string> & pub,
	vector<string> & cid)
{
	library.Load_Book_From_File();
	book.Visit_Book_Title_In_Book_Vec_File(library, title);
	book.Visit_Auth_Name_In_Book_Vec_File(library, auth);
	book.Visit_Pub_Dep_In_Book_Vec_File(library, pub);
	book.Visit_cID_In_Book_Vec_File(library, cid);
	Book * book_vec = book.Get_Book_Vec();
	Data_processor.Init_Classify_Tree(library);
	for (int i = 0; i < auth.size(); ++i){
		Data_processor.Classify_Book_By_Title(library, title[i]);
		Data_processor.Classify_Book_By_Auth_Name(library, auth[i]);
		Data_processor.Classify_Book_By_Pud_Dep(library, pub[i]);
		Data_processor.Classify_Book_By_C_ID(library, cid[i]);
	}
}