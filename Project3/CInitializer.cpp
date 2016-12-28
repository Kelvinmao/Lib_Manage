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
#include"CLogIn_Out.h"
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
	library.load_Readers_Info_From_File();
	return true;
}

bool CInitializer::login(CLogin_Out & user_log, CReader & reader, CLibrary & lib){
	cout << "尊敬的用户，您好，请先登录" << endl;
	user_log.choose_User_Type();
	if (user_log.get_User_Type() == 1)
		user_log.admin_Login();
	if (user_log.get_User_Type() == 2)
		user_log.reader_Login(lib);
	if (user_log.get_User_Type() == 3){
		CReader * new_reader = new CReader;
		new_reader->sign_Up_As_A_New_Reader(lib); 
		lib.push_Reader_Into_ReaderVec((*new_reader));
		lib.push_New_Reader_Into_NewReaderVec((*new_reader));
		user_log.cur_Reader = (*new_reader);
		delete new_reader;
		new_reader = nullptr;
		reader.write_Readers_Info_Into_File(lib);
		user_log.set_Reader_Login_State();
		const int type = 2;
		user_log.set_User_Type(type);
		return true;
	}
	if (user_log.check_Admin_Login_State() || user_log.check_Reader_Login_State()){
		system("cls");
		return true;
	}
	else{
		cout << "用户名或密码有误" << endl;
		return false;
	}
}