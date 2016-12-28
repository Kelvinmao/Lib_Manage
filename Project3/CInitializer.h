//------------------------------------------------
//Title: CInitializer.h
//Type: Header file
//Data: 2016-12-26
//Written By: KelvinMao
//------------------------------------------------

#ifndef CINITIALIZER_H_
#define CINITIALIZER_H_

#include<iostream>
#include"Data_Structure.h"
#include"CData_Processor.h"
#include"CSearch_Book.h"
#include"CLibrary.h"
#include"CReader.h"
#include"CBook.h"
using namespace std;

class CInitializer{
private:
public:
	CInitializer(){}
	//初始化，从文件中读取数据，构建Classsyfy_Tree
	bool Initialize(CData_Processor & Data_processor, 
					CSearch_Book & Book_Searcher, 
					CLibrary & library, 
					CReader & reader, 
					CBook & book,
					vector<string> & title,
					vector<string> & auth,
					vector<string> & pub,
					vector<string> & cid
					);
	//处理用户登录
	bool login(CLogin_Out & user_log, CReader & reader, CLibrary & lib);
	~CInitializer(){}
};

#endif