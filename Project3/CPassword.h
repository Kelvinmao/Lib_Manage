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
	string psw;//���ڴ�������ַ�����
	int length;//���볤��
public:
	Password() :psw(""), length(0){}//���캯����������Ҫ���ڳ�ʼ�����룬ʹ֮Ϊ��
	void inputPassword();//�������벢����*Ϊ����
	string getPassword();//����һ�������ַ�������ʵ���԰������ٴμ��ܣ��������ݿ��С�
};

#endif