//------------------------------------------------
//Title: CPassword.cpp
//Type: Source file
//Data: 2016-12-26
//Written By: KelvinMao
//------------------------------------------------

#include <iostream>
#include<conio.h>
#include<string>
#include"CPassword.h"
using namespace std;

void Password::inputPassword(){
	cout << "���������룺 " << endl;
	int i = 0;
	char ch;
	while ((ch = _getch()) != 13)
	{
		psw += ch;
		cout << "*";
	}
	/*cout << endl << "������ϣ���������ǣ� " << psw << endl;*/
}

string Password::getPassword(){
	return psw;
}
