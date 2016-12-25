//------------------------------------------------
//Title: CData_Processor.cpp
//Type: Source file
//Data: 2016-12-10
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<fstream>
#include"CData_Processor.h"
#include"Finder_Structures.h"
using namespace std;

//TODO:关于日志处理的部分全部放到CLogFile类里面去！
//CData_Processor::CData_Processor(){
//	//这段获取时间的代码需要修改
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
	ofstream fout(file_name,ios_base::app);
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
	fout << "出版日期";
	fout << "借阅状态" << endl;
	return true;
}

//Save the struct book into the file,and the default file path has already confirmed
bool CData_Processor::Save_Info_To_File_app(CLibrary & lib, const string & File_Path){
	ofstream fout(File_Path,ios_base::app);
	if (!fout.is_open()){
		cout << "无法找到图书信息文件，请检查路径后重试" << endl;
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
		fout << (*pos).B_Pri << "      ";
		fout << (*pos).P_Tim << "      ";
		fout << (*pos).isBorrow << endl;
	}
	return true;
}


bool CData_Processor::Save_Info_To_File_rw(CLibrary & lib, const string & File_Path){
	ofstream fout(File_Path);
	if (!fout.is_open()){
		cout << "无法找到图书信息文件，请检查路径后重试" << endl;
		return false;
	}
	//Attention!!  The itearator here ought to be the const_itearator.
	list<Book>::const_iterator pos = lib.Library.begin();
	for (pos; pos != lib.Library.end(); ++pos){
		fout << (*pos).B_Id << "      ";
		fout << (*pos).B_Tit << "      ";
		fout << (*pos).A_Name << "      ";
		fout << (*pos).C_Id << "      ";
		fout << (*pos).P_Dep << "      ";
		fout << (*pos).B_Pri << "      ";
		fout << (*pos).P_Tim << "      ";
		fout << (*pos).isBorrow << endl;
	}
	return true;
}

bool CData_Processor::Init_Classify_Tree(CLibrary & lib){
	lib.classify_Tree.resize(4);
	lib.classify_Tree.push_back(lib.Tit_Branch);
	lib.classify_Tree.push_back(lib.Auth_Branch);
	lib.classify_Tree.push_back(lib.cID_Branch);
	lib.classify_Tree.push_back(lib.Pub_Dep_Branch);
	return true;
}

//classify book by title(1)
bool CData_Processor::Classify_Book_By_Title(CLibrary & lib, const string & book_Title){
	//list is not empty
	list<Book>::const_iterator i_pos = lib.Library.begin();
	list<Book>::iterator sear_pos;
	for (i_pos; i_pos != lib.Library.end(); ++i_pos){
		if (lib.classify_Tree[0].empty())
			lib.classify_Tree[0].push_back((*i_pos));
		else{
			finder_Tit title(book_Title);
			sear_pos = find_if(lib.classify_Tree[0].begin(), lib.classify_Tree[0].end(), title);
			if (sear_pos == lib.classify_Tree[0].cend())
				lib.classify_Tree[0].push_back((*i_pos));
			else{
				Book tmp = (*i_pos);
				sear_pos->book_Ls.push_back(tmp);
			}
		}
	}
	return true;
}



//classify book by Auth_Name(2)
bool CData_Processor::Classify_Book_By_Auth_Name(CLibrary & lib, const string & auth_Name){
	//list is not empty
	list<Book>::const_iterator i_pos = lib.Library.begin();
	list<Book>::iterator sear_pos;
	for (i_pos; i_pos != lib.Library.end(); ++i_pos){
		if (lib.classify_Tree[1].empty())
			lib.classify_Tree[1].push_back((*i_pos));
		else{
			finder_auth_Name auth(auth_Name);
			sear_pos = find_if(lib.classify_Tree[1].begin(), lib.classify_Tree[1].end(), auth);
			if (sear_pos == lib.classify_Tree[1].cend())
				lib.classify_Tree[1].push_back((*i_pos));
			else{
				Book tmp = (*i_pos);
				sear_pos->book_Ls.push_back(tmp);
			}
		}
	}
	return true;
}

////classify book by C_ID(3)
bool CData_Processor::Classify_Book_By_C_ID(CLibrary & lib, const string & c_ID){
	//list is not empty
	list<Book>::const_iterator i_pos = lib.Library.begin();
	list<Book>::iterator sear_pos;
	for (i_pos; i_pos != lib.Library.end(); ++i_pos){
		if (lib.classify_Tree[2].empty())
			lib.classify_Tree[2].push_back((*i_pos));
		else{
			finder_CID cID(c_ID);
			sear_pos = find_if(lib.classify_Tree[2].begin(), lib.classify_Tree[2].end(), cID);
			if (sear_pos == lib.classify_Tree[2].cend())
				lib.classify_Tree[2].push_back((*i_pos));
			else{
				Book tmp = (*i_pos);
				sear_pos->book_Ls.push_back(tmp);
			}
		}
	}
	return true;
}
//
//classify book by Pud_Dep(4)
bool CData_Processor::Classify_Book_By_Pud_Dep(CLibrary & lib, const string & pub_Dep){
	//list is not empty
	list<Book>::const_iterator i_pos = lib.Library.begin();
	list<Book>::iterator sear_pos;
	for (i_pos; i_pos != lib.Library.end(); ++i_pos){
		if (lib.classify_Tree[3].empty())
			lib.classify_Tree[3].push_back((*i_pos));
		else{
			finder_pub_Dep pub_D(pub_Dep);
			sear_pos = find_if(lib.classify_Tree[3].begin(), lib.classify_Tree[3].end(), pub_D);
			if (sear_pos == lib.classify_Tree[3].cend())
				lib.classify_Tree[3].push_back((*i_pos));
			else{
				Book tmp = (*i_pos);
				sear_pos->book_Ls.push_back(tmp);
			}
		}
	}
	return true;
}

