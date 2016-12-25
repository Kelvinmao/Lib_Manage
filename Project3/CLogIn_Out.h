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
	vector<string> admin_Info;
public:
	CLogin_Out(){ admin_flag = false; reader_flag = false; }
	bool choose_User_Type();
	int get_User_Type(){ return user_Type; }
	bool admin_Login();
	bool admin_Logout();
	bool reader_Login(CLibrary & lib);
	bool reader_Logout(const CLibrary & lib);
};

#endif