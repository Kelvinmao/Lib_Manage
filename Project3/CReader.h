//------------------------------------------------
//Title: CReader.h
//Type: Header file
//Data: 2016-12-19
//Written By: KelvinMao
//------------------------------------------------
#ifndef CREADER_H_
#define CREADER_H_

#include"Data_Structure.h"
#include"CSearch_Book.h"
#include"CLibrary.h"
using namespace std;

class CLibrary;
class CSearch_Book;
//Defination of reader
class CReader{
	friend class CLibrary;
private:
	int book_Amount;
	float own_Mon;
	string r_Name;//The name of the reader
	string r_ID;
	string r_password;//The password of the reader
	string comm_Addr;//reader's email address
	string phone_Num;//reader's phone number
	list<Book> borrowed_Book;//A list contains a reader's all borrowed book
public:
	CReader() :r_ID(""), r_Name(""), comm_Addr(""), phone_Num(""), r_password(""){};
	CReader(const string & rid, const string & name, const string & comm, const string & phone, const string & r_pass) :r_ID(rid),r_Name(name), comm_Addr(comm), phone_Num(phone),r_password(r_pass){}
	bool sign_Up_As_A_New_Reader(CLibrary & lib);
	/*These following functions borrow book from the Classify Tree,so I process this procedure carefully
	//so the code has so many "if-else"
	*/
	/************************************************************************************************************************************************************************************/
	bool borrow_Book_By_Title(CLibrary & lib, CSearch_Book & sear_Book, const Book_Title & book_Tit);//reader use this interface to borrow a book,by offering the book title
	bool borrow_Book_By_cID(CLibrary & lib, CSearch_Book & sear_Book, const Classify_ID & cid);//reader use this interface to borrow a book,by offering the classify id
	bool borrow_Book_By_Auth(CLibrary & lib, CSearch_Book & sear_Book, const Auth_Name & a_name);//reader use this interface to borrow a book,by offering the auth_name
	bool borrow_Book_By_pub_Dep(CLibrary & lib, CSearch_Book & sear_Book, const Pub_Dep & p_dep);//reader use this interface to borrow a book,by offering the publish department
	/************************************************************************************************************************************************************************************/
	bool borrow_Book_By_bID(CLibrary & lib, CSearch_Book & sear_Book, const Book_ID & bid);//reader use this interface to borrow a book,by offering the book id
	//"bool borrow_Book_By_Pub_Time" seems useless
	//bool borrow_Book_By_Pub_Time(CLibrary & lib, CSearch_Book & sear_Book, const Pub_Tim & p_time, const int & order_id);//reader use this interface to borrow a book,by offering the pub_time
	bool renew_Book(const Book_ID & bid,CLibrary & lib,CSearch_Book & sear_Book);//~to renew a book
	/*If now no book available,when this book is available in the future,
	//give a massage or email to reader that this book is available
	*/
	bool give_Back_Book(CSearch_Book & sear_Book,const Book_ID & bid);
	bool show_All_Borrowed_Books();
	bool notice_The_Dead_Line();//Send a email to reader,notice him or her to give back the book
	bool write_Readers_Info_Into_File(const CLibrary & lib);//Write readers' infomation into file
	bool read_Readers_Info_From_File(CLibrary & lib);//Read readers' infomation from file
	bool read_Names_From_File(CLibrary & lib);
	bool write_Reader_Name_Into_File();
	bool book_Info_Mailed_To_Reader();
	bool book_Info_Messageed_To_Reader();
	bool change_Reader_Name();
	bool change_Reader_ID();
	bool change_Reader_Email_Addr();
	bool change_Reader_Phone_Num();
	bool change_Reader_Password();
	const string & get_Reader_Name(){ return r_Name; }
	const string & get_Reader_Password(){ return r_password; }
};
#endif