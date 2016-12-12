//------------------------------------------------
//Title: CData_Processor.cpp
//Type: Source file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<fstream>
#include"CData_Processor.h"
using namespace std;

//TODO:������־����Ĳ���ȫ���ŵ�CLogFile������ȥ��
//CData_Processor::CData_Processor(){
//	//��λ�ȡʱ��Ĵ�����Ҫ�޸�
//	ofstream fout("log.txt");
//	/*const struct tm * local=nullptr;
//	char * time = asctime(local);
//	string str(time);
//	fout << time<<" ";*/
//	fout << "CData_Processer's Constructor" << endl;
//}

//This method is wasted,so ignore it!
//bool CData_Processor::Input_Info(Book & book){
//	
//}

bool CData_Processor::Constru_The_Header(const string & file_name){
	ofstream fout(file_name);
	if (!fout.is_open()){
		cout << "�޷����鼮��Ϣ�ļ�������·��������" << endl;
		return false;
	}
	fout << "ͼ����      ";
	fout << "����      " ;
	fout << "������      ";
	fout << "�����      ";
	fout << "��������      ";
	fout << "����۸�      " << endl;
	return true;
}

//Save the struct book into the file,and the default file path has already confirmed
bool CData_Processor::Save_Info_To_File(CLibrary & lib, const string & File_Path){
	ofstream fout(File_Path,ios_base::app);
	if (!fout.is_open()){
		cout << "�޷��ҵ�ͼ����Ϣ�ļ�������·��������" << endl;
		return false;
	}
	//Attention!!  The itearator here ought to be the const_itearator.
	list<Book>::const_iterator pos=lib.Library.begin();
	for (pos; pos != lib.Library.end();++pos){
		fout << (*pos).B_Id << "      ";
		fout << (*pos).B_Tit << "      ";
		fout << (*pos).A_Name << "      ";
		fout << (*pos).C_Id << "      ";
		fout << (*pos).P_Dep << "      ";
		fout << (*pos).B_Pri << "      " << endl;
	}
	return true;
}

