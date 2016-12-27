//------------------------------------------------
//Title: CInterface.h
//Type: Header file
//Data: 2016-12-27
//Written By: KelvinMao
//------------------------------------------------

#ifndef CINTERFACE_H_
#define CINTERFACE_H_

#include"Data_Structure.h"
#include"CLogIn_Out.h"
using namespace std;

class CInterface{
private:
	int user_Type;
public:
	CInterface():user_Type(0){}
	int judge_The_User_Type(const CLogin_Out & login);
	bool show_Admin_Interface(CSearch_Book & searcher, CLibrary & lib);
	bool show_Reader_Interface();
};

#endif