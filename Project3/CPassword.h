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
	Password()//���캯����������Ҫ���ڳ�ʼ�����룬ʹ֮Ϊ��
	{
		psw = "";//��ʼ������Ϊ��"";
		length = 0; //��ʼ�����볤��
	}
	void inputPassword()//�������벢����*Ϊ����
	{
		char temp_c;
		cout << "please input password:";
		while (true)
		{
			temp_c = getch();  //����һ���ַ�
			if (temp_c != char(13))  //�жϸ��ַ��ǲ�Ϊ�س�����������˳�while
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
					cout << "*"; //��������ϲ���������ַ������Ϊcout<<"";���޻���
					psw += temp_c;//�����ַ�����
					length++;
					break;
				}
			}
			else break;
		}
	}
	string getPassword()//����һ�������ַ�������ʵ���԰������ٴμ��ܣ��������ݿ��С�
	{
		return psw;
	}
};

#endif