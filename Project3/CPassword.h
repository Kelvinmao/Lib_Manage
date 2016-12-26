//------------------------------------------------
//Title: CPassword.h
//Type: Header file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------
#ifndef CPASSWORD_H_
#define CPASSWORD_H_

#include <iostream>
#include<conio.h>
#include<string>
using namespace std;

class Password
{
private:
	string psw;//用于存密码的字符串；
	int length;//密码长度
public:
	Password() :psw(""), length(0){}//构造函数，这里主要用于初始化密码，使之为空
	void inputPassword();//用于输入并回显*为密码
	string getPassword();//返回一个密码字符串，其实可以把密码再次加密，存在数据库中。
};

#endif