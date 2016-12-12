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
using namespace std;

class CLogFile{
private:
	/*const string m_Default_Path;*/ //I'm not sure is this variable is neccessary,so,put it aside.
public:
	explicit CLogFile(const string & Log_File_Path="log.txt");
	const string & AckTime();//Acquire the system time
	bool Get_Info_From_Other_Method(); //Acquire info from other mathods which actions will be recorded. 
	bool Write_Info_To_Log(); //Format and write into the logfile.
};
#endif