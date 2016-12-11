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
	Password()//构造函数，这里主要用于初始化密码，使之为空
	{
		psw = "";//初始化密码为空"";
		length = 0; //初始化密码长度
	}
	void inputPassword()//用于输入并回显*为密码
	{
		char temp_c;
		cout << "please input password:";
		while (true)
		{
			temp_c = getch();  //输入一个字符
			if (temp_c != char(13))  //判断该字符是不为回车，如果是则退出while
			{
				switch (temp_c)
				{
				case 8:
					if (length != 0)
					{
						cout << "/b /b";
						psw = psw.substr(0, length - 1);
						length--;
					}
					else;
					break;
				default:
					cout << "*"; //可用用你喜欢的任意字符，如改为cout<<"";则无回显
					psw += temp_c;//连成字符串；
					length++;
					break;
				}
			}
			else break;
		}
	}
	string getPassword()//返回一个密码字符串，其实可以把密码再次加密，存在数据库中。
	{
		return psw;
	}
};

#endif