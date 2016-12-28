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
#include"CLibrary.h"
using namespace std;

class CLibrary;
class CLogin_Out{
private:
	int user_Type;//�û����ͣ����ֹ���Ա����ͨ�û�
	bool admin_flag;//����Ա��¼���
	bool reader_flag;//�û���¼���
	CReader cur_Reader;//��ǰ�û�����
public:
	CLogin_Out(){ admin_flag = false; reader_flag = false; }
	bool choose_User_Type();//���ڵ�¼ʱѡ���û�����
	int get_User_Type(){ return user_Type; }//�ṩ������user_Type�Ľӿ�
	bool admin_Login();//�������Ա��¼
	bool admin_Logout();//~�ǳ�
	bool reader_Login(CLibrary & lib);//�û���¼
	bool reader_Logout();//~�ǳ�
	bool check_Admin_Login_State(){ return admin_flag; }//����¼״̬
	bool check_Reader_Login_State(){ return reader_flag; }
	CReader & return_Current_User(){ return cur_Reader; }//���ص�ǰ�û�����
	~CLogin_Out(){ admin_flag = false; reader_flag = false; }
};

#endif