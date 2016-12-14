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
	fout << "出版日期" << endl;
	return true;
}

//Save the struct book into the file,and the default file path has already confirmed
bool CData_Processor::Save_Info_To_File(CLibrary & lib, const string & File_Path){
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
		fout << (*pos).B_Pri << "      " << endl;
		fout << (*pos).P_Tim << "      " << endl;
	}
	return true;
}

//Initialize,allocate memory and initialize its initial value
bool CData_Processor::Init_Classify_Tree(CLibrary & lib){
	int index = 0;
	lib.classify_Tree.resize(4);
	for (index = 0; index < 4; ++index)
		lib.classify_Tree[index] = new list<Book>;
	return true;
}

//classify book by title(1)
bool CData_Processor::Classify_Book_By_Title(const CLibrary & lib, const string & book_Title,Book & book){
	//list is empty,
	if (lib.classify_Tree[0]->empty()){
		lib.classify_Tree[0]->push_back(book);
		return true;
	}
	//list is not empty
	else{
		list<Book>::iterator pos = lib.classify_Tree[0]->begin();
		for (pos; pos != lib.classify_Tree[0]->end(); ++pos){
			//The book is already in the list
			if (book_Title == (*pos).B_Tit){
				Book * pMove = &(*pos);
				while (pMove->pNext_Book)
					pMove = pMove->pNext_Book;
				//Allocate for a new nodes,and insert the new node at tail.
				Book * pNode = new Book;
				pMove->pNext_Book = pNode;
				pMove = pNode;
				pMove->pNext_Book = nullptr;
			}
			//The book isn't in the list
			else
				lib.classify_Tree[0]->push_back(book);
		}
	}
	return true;
}

//classify book by Auth_Name(2)
bool CData_Processor::Classify_Book_By_Auth_Name(const CLibrary & lib, const string & auth_Name, Book & book){
	//list is empty,
	if (lib.classify_Tree[1]->empty()){
		lib.classify_Tree[1]->push_back(book);
		return true;
	}
	//list is not empty
	else{
		list<Book>::iterator pos = lib.classify_Tree[1]->begin();
		for (pos; pos != lib.classify_Tree[1]->end(); ++pos){
			//The book is already in the list
			if (auth_Name == (*pos).A_Name){
				Book * pMove = &(*pos);
				while (pMove->pNext_Book)
					pMove = pMove->pNext_Book;
				//Allocate for a new nodes,and insert the new node at tail.
				Book * pNode = new Book;
				pMove->pNext_Book = pNode;
				pMove = pNode;
				pMove->pNext_Book = nullptr;
			}
			//The book isn't in the list
			else
				lib.classify_Tree[1]->push_back(book);
		}
	}
	return true;
}

//classify book by C_ID(3)
bool CData_Processor::Classify_Book_By_C_ID(const CLibrary & lib, const string & c_ID,Book & book){
	//list is empty,
	if (lib.classify_Tree[2]->empty()){
		lib.classify_Tree[2]->push_back(book);
		return true;
	}
	//list is not empty
	else{
		list<Book>::iterator pos = lib.classify_Tree[1]->begin();
		for (pos; pos != lib.classify_Tree[1]->end(); ++pos){
			//The book is already in the list
			if (c_ID == (*pos).C_Id){
				Book * pMove = &(*pos);
				while (pMove->pNext_Book)
					pMove = pMove->pNext_Book;
				//Allocate for a new nodes,and insert the new node at tail.
				Book * pNode = new Book;
				pMove->pNext_Book = pNode;
				pMove = pNode;
				pMove->pNext_Book = nullptr;
			}
			//The book isn't in the list
			else
				lib.classify_Tree[2]->push_back(book);
		}
	}
	return true;
}

//classify book by Pud_Dep(4)
bool CData_Processor::Classify_Book_By_Pud_Dep(const CLibrary & lib, const string & pub_Dep, Book & book){
	//list is empty,
	if (lib.classify_Tree[3]->empty()){
		lib.classify_Tree[3]->push_back(book);
		return true;
	}
	//list is not empty
	else{
		list<Book>::iterator pos = lib.classify_Tree[1]->begin();
		for (pos; pos != lib.classify_Tree[1]->end(); ++pos){
			//The book is already in the list
			if (pub_Dep == (*pos).P_Dep){
				Book * pMove = &(*pos);
				while (pMove->pNext_Book)
					pMove = pMove->pNext_Book;
				//Allocate for a new nodes,and insert the new node at tail.
				Book * pNode = new Book;
				pMove->pNext_Book = pNode;
				pMove = pNode;
				pMove->pNext_Book = nullptr;
			}
			//The book isn't in the list
			else
				lib.classify_Tree[3]->push_back(book);
		}
	}
	return true;
}

