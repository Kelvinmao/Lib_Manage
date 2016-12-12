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
#include"CLogFile.h"
using namespace std;

ofstream fout;
CLogFile::CLogFile(const string & Log_File_Path){
	fout.open(Log_File_Path);
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

//Get info from other method if neccessray
bool CLogFile::Get_Info_From_Other_Method(){

}

bool CLogFile::Write_Info_To_Log(){

}