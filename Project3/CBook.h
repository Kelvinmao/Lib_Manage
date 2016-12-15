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
#include"CData_Processor.h"
using namespace std;
class CLibrary;
/****************************************************************************************/
//Modified at 2016-12-14,to make CData_Processor::Classify methods can visit the m_pBook
//so,I add CData_Processor to be the friend class of the CBook
/****************************************************************************************/
class CData_Processor;
class CBook{
	friend class CData_Processor;
private:
	Book * m_pBook;
	int book_num;
public:
	//constructor used to new a struct Book
	explicit CBook(int & book_Num);
	bool Input_Info(); 
	bool Add_Book_Into_List(CLibrary & lib);
	bool operator==(const CBook & book);
	~CBook(){ delete[] m_pBook; }
};

#endif