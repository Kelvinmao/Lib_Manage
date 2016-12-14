//------------------------------------------------
//Title: CLogFile.cpp
//Type: Source file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<queue>
#include"CLogFile.h"
using namespace std;

ofstream fout;
ifstream fin;
CLogFile::CLogFile(const string & Log_File_Path){
	fout.open(Log_File_Path,ios_base::app);
	if (!fout.is_open){
		cout << "日志文件打开失败，请检查路径后重试" << endl;
		exit(EXIT_FAILURE);
	}
}

//
const string & CLogFile::AckTime(){
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	//cout<<"The current date/time is:"<<asctime(timeinfo);
	return asctime(timeinfo);
}

//Get info from other methods if neccessray
/*****************************************************************************************/
//To achieve this goal,maybe i can make all other class be a friend class of the CLogFile,
//but it will be too trouble and ungraceful.

//I dont have a good solution to this problem.So,let me put it aside......
bool CLogFile::Get_Info_From_Other_Method(){
	return true;
}

bool CLogFile::Write_Info_To_Log(const string & Event_str){
	if (Event_str.empty()){
		fout << "Nothing happened" << endl;
	}
	fout << Event_str << endl;
}

bool CLogFile::Read_Info_From_File(const string & Log_File_Path){
	if (Log_File_Path.empty()){
		cout << "日志文件路径不能为空，请检查后重试";
		return false;
	}
	string tmp;
	fin.open(Log_File_Path);
	if (!fin.is_open()){
		cout << "无法打开日志文件，请检查路径后重试" << endl;
		return false;
	}
	while (getline(fin, tmp) && tmp.size() > 0)
		Msg_Que.push(tmp);
}

bool CLogFile::Dis_Info_From_MsgQue(){
	if (Msg_Que.empty())
		cout << "事件队列为空" << endl;
	int index = 0;
	for (index = 0; index < Msg_Que.size(); ++index)
		cout << Msg_Que[index] << endl;
}


