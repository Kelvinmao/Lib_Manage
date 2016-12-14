//------------------------------------------------
//Title: CLogFile.h
//Type: Header file
//Data: 2016-12-12
//Written By: KelvinMao
//------------------------------------------------

#ifndef CLOGFILE_H_
#define CLOGFILE_H_

#include<iostream>
#include<string>
#include<queue>
using namespace std;

class CLogFile{
private:
	/*const string m_Default_Path;*/ //I'm not sure is this variable is neccessary,so,put it aside.
	queue<string> Msg_Que;
public:
	explicit CLogFile(const string & Log_File_Path="log.txt");
	const string & AckTime();//Acquire the system time
	bool Get_Info_From_Other_Method(); //Acquire info from other mathods which actions will be recorded. 
	bool Write_Info_To_Log(const string & event_str); //Format and write into the logfile.
	bool Read_Info_From_File(const string & Log_File_Path = "log.txt");//Get info from Log file and push them into Msg_Queue
	bool Dis_Info_From_MsgQue();//Display info to the screen.
};
#endif