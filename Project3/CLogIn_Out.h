//------------------------------------------------
//Title: CLogIn_Out.h
//Type: Header file
//Data: 2016-12-25
//Written By: KelvinMao
//------------------------------------------------

#ifndef CLOGINOUT_H_
#define COGINOUT_H_

#include<iostream>
#include"Data_Structure.h"
#include"CLibrary.h"
using namespace std;

class CLibrary;
class CLogin_Out{
private:
	int user_Type;
	bool admin_flag;
	bool reader_flag;
public:
	CLogin_Out(){ admin_flag = false; reader_flag = false; }
	bool choose_User_Type();
	int get_User_Type(){ return user_Type; }
	bool admin_Login();
	bool admin_Logout();
	bool reader_Login(CLibrary & lib);
	bool reader_Logout(const CLibrary & lib);
	bool check_Admin_Login_State(){ return admin_flag; }
	bool check_Reader_Login_State(){ return reader_flag; }
	~CLogin_Out(){ admin_flag = false; reader_flag = false; }
};

#endif