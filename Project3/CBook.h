//------------------------------------------------
//Title: CBook.h
//Type: Header file
//Data: 2016-12-08
//Written By: KelvinMao
//------------------------------------------------
#ifndef CBOOK_H_
#define CBOOK_H_

#include<string>
#include"CData_Processor.h"
#include"Data_Structure.h"
#include"CLibrary.h"
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
	int book_num;//一次加入的书的数目
public:
	//constructor used to new a struct Book
	CBook(){}
	explicit CBook(int & book_Num);
	bool Input_Info(); 
	bool Add_Book_Into_List(CLibrary & lib);
	vector<string> & Visit_Book_Title_In_Book_Vec(vector<string> & book_title);
	vector<string> & Visit_Book_Title_In_Book_Vec_File(const CLibrary & lib, vector<string> & book_title);

	vector<string> & Visit_Auth_Name_In_Book_Vec(vector<string> & auth_vec);
	vector<string> & Visit_Auth_Name_In_Book_Vec_File(const CLibrary & lib, vector<string> & auth_vec);

	vector<string> & Visit_Pub_Dep_In_Book_Vec(vector<string> & Pub_vec);
	vector<string> & Visit_Pub_Dep_In_Book_Vec_File(const CLibrary & lib, vector<string> & Pub_vec);

	vector<string> & Visit_cID_In_Book_Vec(vector<string> & cID_vec);
	vector<string> & Visit_cID_In_Book_Vec_File(const CLibrary & lib, vector<string> & cID_vec);

	Book * Get_Book_Vec(){ return m_pBook; }
	~CBook(){ delete[] m_pBook; }
};

#endif