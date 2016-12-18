//------------------------------------------------
//Title: CData_Process.cpp
//Type: Source file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<fstream>
#include<ctime>
#include"CData_Process.h"
using namespace std;

CData_Processor::CData_Processor(){
	//这段获取时间的代码需要修改
	ofstream fout("log.txt");
	/*const struct tm * local=nullptr;
	char * time = asctime(local);
	string str(time);
	fout << time<<" ";*/
	fout << "CData_Processer's Constructor" << endl;
}

//This method is wasted,so ignore it!
//bool CData_Processor::Input_Info(Book & book){
//	
//}

bool CData_Processor::Constru_The_Header(const string & file_name){
	ofstream fout(file_name);
	if (!fout.is_open()){
		cout << "无法打开书籍信息文件，请检查路径后重试" << endl;
		return false;
	}
	fout << "图书编号      ";
	fout << "书名      " ;
	fout << "作者名      ";
	fout << "分类号      ";
	fout << "出版社名      ";
	fout << "本书价格      ";
	return true;
}

//Save the struct book into the file,and the default file path has already confirmed
bool CData_Processor::Save_Info_To_File(list<Book> & ls,const string & File_Path){
	ofstream fout(File_Path,ios_base::app);
	if (!fout.is_open()){
		cout << "无法找到图书信息文件，请检查路径后重试" << endl;
		return false;
	}
	//Attention!!  The itearator here ought to be the const_itearator.
	list<Book>::const_iterator pos;
	for (pos = ls.begin(); pos != ls.end(); ++pos){
		fout << (*pos).B_Id << "      ";
		fout << (*pos).B_Tit << "      ";
		fout << (*pos).A_Name << "      ";
		fout << (*pos).C_Id << "      ";
		fout << (*pos).P_Dep << "      ";
		fout << (*pos).B_Pri << "      " << endl;
	}
	return true;
}