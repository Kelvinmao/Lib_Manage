//------------------------------------------------
//Title: CLogIn_Out.h
//Type: Header file
//Data: 2016-12-25
//Written By: KelvinMao
//------------------------------------------------

#ifndef CLOGINOUT_H_
#define CLOGINOUT_H_

#include<iostream>
#include"Data_Structure.h"
#include"CInitializer.h"
#include"CLibrary.h"
using namespace std;

class CLibrary;
class CInitializer;
class CLogin_Out{
	friend class CInitializer;
private:
	int user_Type;//用户类型，区分管理员和普通用户
	bool admin_flag;//管理员登录标记
	bool reader_flag;//用户登录标记
	CReader cur_Reader;//当前用户对象
public:
	CLogin_Out(){ admin_flag = false; reader_flag = false; }
	bool choose_User_Type();//用于登录时选择用户类型
	int get_User_Type(){ return user_Type; }//提供外界访问user_Type的接口
	bool admin_Login();//处理管理员登录
	bool admin_Logout();//~登出
	bool reader_Login(CLibrary & lib);//用户登录
	bool reader_Logout();//~登出
	bool check_Admin_Login_State(){ return admin_flag; }//检查登录状态
	bool check_Reader_Login_State(){ return reader_flag; }
	bool set_Reader_Login_State(){ reader_flag = true; return true; }
	bool set_User_Type(const int & type){ user_Type = type; return true; }
	CReader & return_Current_User(){ return cur_Reader; }//返回当前用户对象
	~CLogin_Out(){ admin_flag = false; reader_flag = false; }
};

#endif