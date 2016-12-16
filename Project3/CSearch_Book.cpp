//------------------------------------------------
//Title: CSearch_Book.cpp
//Type: Source file
//Data: 2016-12-14
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<list>
#include"Data_Structure.h"
#include"Comp_Structures.h"
#include"CSearch_Book.h"
#include"CLibrary.h"
using namespace std;

bool CSearch_Book::Search_By_Title(const CLibrary & lib,const string & title){
	if (lib.classify_Tree[0]->empty()){
		cout << "待查询序列为空" << endl;
		return false;
	}
	else{
		finder_Tit tar_Title(title);
		list<Book>::const_iterator fir_Pos;
		Book * pMove = nullptr;
		fir_Pos = find_if(lib.classify_Tree[0]->begin(), lib.classify_Tree[0]->end(),tar_Title);
		result.push_back((*fir_Pos));
		pMove = (*fir_Pos).pNext_Book;
		while (pMove){
			result.push_back((*pMove));
			pMove = pMove->pNext_Book;
		}
	}
	return true;
}

bool CSearch_Book::Search_By_Auth_Name(const CLibrary & lib,const string & auth_Name){
	if (lib.classify_Tree[1]->empty()){
		cout << "待查询序列为空" << endl;
		return false;
	}
	else{
		finder_auth_Name tar_Auth_Name(auth_Name);
		list<Book>::const_iterator fir_Pos;
		Book * pMove = nullptr;
		fir_Pos = find_if(lib.classify_Tree[1]->begin(), lib.classify_Tree[1]->end(), tar_Auth_Name);
		result.push_back((*fir_Pos));
		pMove = (*fir_Pos).pNext_Book;
		while (pMove){
			result.push_back((*pMove));
			pMove = pMove->pNext_Book;
		}
	}
	return true;
}

bool CSearch_Book::Search_By_CId(const CLibrary & lib, const string & c_ID){
	if (lib.classify_Tree[2]->empty()){
		cout << "待查询序列为空" << endl;
		return false;
	}
	else{
		finder_CID tar_CID(c_ID);
		list<Book>::const_iterator fir_Pos;
		Book * pMove = nullptr;
		fir_Pos = find_if(lib.classify_Tree[2]->begin(), lib.classify_Tree[2]->end(), tar_CID);
		result.push_back((*fir_Pos));
		pMove = (*fir_Pos).pNext_Book;
		while (pMove){
			result.push_back((*pMove));
			pMove = pMove->pNext_Book;
		}
	}
	return true;
}

bool CSearch_Book::Search_By_Pub_Dep(const CLibrary & lib, const string & pub_Dep){
	if (lib.classify_Tree[3]->empty()){
		cout << "待查询序列为空" << endl;
		return false;
	}
	else{
		finder_pub_Dep tar_Pub_Dep(pub_Dep);
		list<Book>::const_iterator fir_Pos;
		Book * pMove = nullptr;
		fir_Pos = find_if(lib.classify_Tree[3]->begin(), lib.classify_Tree[3]->end(), tar_Pub_Dep);
		result.push_back((*fir_Pos));
		pMove = (*fir_Pos).pNext_Book;
		while (pMove){
			result.push_back((*pMove));
			pMove = pMove->pNext_Book;
		}
	}
	return true;
}
