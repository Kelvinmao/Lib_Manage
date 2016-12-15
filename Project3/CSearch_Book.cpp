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
#include"CSearch_Book.h"
#include"CLibrary.h"
using namespace std;

//Defination of the custom Comp_Functions to find proper book.
//bool comp_With_Book_Title(const Book & book){ return book.B_Tit == ; }
//bool comp_With_Auth_Name(const Book & book){ return book.A_Name; }
//bool comp_With_C_ID(const Book & book){ return book.C_Id; }
//bool comp_With_Pub_Dep(const Book & book){ return book.P_Dep; }

bool CSearch_Book::Search_By_Title(const CLibrary & lib,const string & title){
	if (lib.classify_Tree[0]->empty()){
		cout << "´ý²éÑ¯ÐòÁÐÎª¿Õ" << endl;
		return false;
	}
	else{
		list<Book>::const_iterator fir_Pos;
		Book * pMove = nullptr;
		fir_Pos = find_if(lib.classify_Tree[0]->begin(), lib.classify_Tree[0]->end(),);
		result.push_back((*fir_Pos));
		pMove = (*fir_Pos).pNext_Book;
		while (pMove){
			result.push_back((*pMove));
			pMove = pMove->pNext_Book;
		}
	}
}

bool CSearch_Book::Search_By_Auth_Name(const CLibrary & lib,const string & auth_Name){

}

bool CSearch_Book::Search_By_CId(const CLibrary & lib, const string & c_ID){

}

bool CSearch_Book::Search_By_Pub_Dep(const CLibrary & lib, const string & pub_Dep){

}