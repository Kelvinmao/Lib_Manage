//------------------------------------------------
//Title: CBook.h
//Type: Header file
//Data: 2016-12-08
//Written By: KelvinMao
//------------------------------------------------
#ifndef CBOOK_H_
#define CBOOK_H_

#include"Data_Structure.h"
#include"CLibrary.h"
using namespace std;

class CBook{
private:
	Book * m_pBook;
	int book_num;
public:
	//constructor used to new a struct Book
	explicit CBook(int & book_Num);
	bool Input_Info(); 
	bool Add_Book_Into_List(CLibrary & lib);
};

#endif