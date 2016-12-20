//------------------------------------------------
//Title: CReader.cpp
//Type: Source file
//Data: 2016-12-19
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<vector>
#include<list>
#include"Finder_Structures.h"
#include"Data_Structure.h"
#include"CSearch_Book.h"
#include"CLibrary.h"
#include"CReader.h"
using namespace std;

class CSearch_Book;
class CLibrary;
//book is from CSearch_Book::result
//borrow_Book_By_Title borrows book from Classify Tree,so you should deal with the ptr carefully.
bool CReader::borrow_Book_By_Title(CLibrary & lib, CSearch_Book & sear_Book,const Book_Title & book_Tit,const int & order_id){
	sear_Book.Search_By_Title(lib,book_Tit);
	sear_Book.Show_Search_Result();
	//To filter some unvalid input
	if (order_id > sear_Book.result.size()){
		cout << "不存在序号为" << order_id << "的书,请确认后再输入" << endl;
		return false;
	}
	//If reader want give a valid order_id, firstly I will judge the state of the book 

	//If this book is not borrowed
	if (sear_Book.result[order_id - 1].isBorrow == false){
		if (sear_Book.result[order_id - 1].pNext_Book == nullptr){
			cout << "借阅成功,请注意归还日期" << endl;
			sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
			return true;
		}
		//If there exists other books have the same title, in other word,this book is not alone in the classify tree
		else{
			//When reader just want to borrow the first book in the "result vector"
			if (order_id == 1){
				cout << "借阅成功,请注意归还日期" << endl;
				sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
				return true;
			}
			else{
				//When reader want to borrow the next book of this book
				int & tmp=const_cast<int &> (order_id);
				Book * pMove = sear_Book.iter_Vec[order_id - 1]->pNext_Book;
				while (tmp > 2 && pMove!=nullptr){
					pMove = pMove->pNext_Book;
					--tmp;
				}
				pMove->isBorrow = true;
				cout << "借阅成功,请注意归还日期" << endl;
			}
		}
	}
	//Other situation,just return false.
	else{
		cout << "此书已被借阅，无法重复借阅" << endl;
			return false;
	}
	return false;
}

//book is from CSearch_Book::result
//borrow_Book_By_Auth borrows book from Classify Tree,so you should deal with the ptr carefully.
bool CReader::borrow_Book_By_Auth(CLibrary & lib, CSearch_Book & sear_Book, const Auth_Name & a_name,const int & order_id){
	sear_Book.Search_By_Auth_Name(lib,a_name);
	sear_Book.Show_Search_Result();
	//To filter some unvalid input
	if (order_id > sear_Book.result.size()){
		cout << "不存在序号为" << order_id << "的书,请确认后再输入" << endl;
		return false;
	}
	//If reader want give a valid order_id, firstly I will judge the state of the book 

	//If this book is not borrowed
	if (sear_Book.result[order_id - 1].isBorrow == false){
		if (sear_Book.result[order_id - 1].pNext_Book == nullptr){
			cout << "借阅成功,请注意归还日期" << endl;
			sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
			return true;
		}
		//If there exists other books have the same title, in other word,this book is not alone in the classify tree
		else{
			//When reader just want to borrow the first book in the "result vector"
			if (order_id == 1){
				cout << "借阅成功,请注意归还日期" << endl;
				sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
				return true;
			}
			else{
				//When reader want to borrow the next book of this book
				int & tmp = const_cast<int &> (order_id);
				Book * pMove = sear_Book.iter_Vec[order_id - 1]->pNext_Book;
				while (tmp > 2 && pMove != nullptr){
					pMove = pMove->pNext_Book;
					--tmp;
				}
				pMove->isBorrow = true;
				cout << "借阅成功,请注意归还日期" << endl;
			}
		}
	}
	//Other situation,just return false.
	else{
		cout << "此书已被借阅，无法重复借阅" << endl;
		return false;
	}
	return false;
}

//book is from CSearch_Book::result
//borrow_Book_By_cID borrows book from Classify Tree,so you should deal with the ptr carefully.
bool CReader::borrow_Book_By_cID(CLibrary & lib, CSearch_Book & sear_Book, const Classify_ID & cid, const int & order_id){
	sear_Book.Search_By_CId(lib, cid);
	sear_Book.Show_Search_Result();
	//To filter some unvalid input
	if (order_id > sear_Book.result.size()){
		cout << "不存在序号为" << order_id << "的书,请确认后再输入" << endl;
		return false;
	}
	//If reader want give a valid order_id, firstly I will judge the state of the book 

	//If this book is not borrowed
	if (sear_Book.result[order_id - 1].isBorrow == false){
		if (sear_Book.result[order_id - 1].pNext_Book == nullptr){
			cout << "借阅成功,请注意归还日期" << endl;
			sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
			return true;
		}
		//If there exists other books have the same title, in other word,this book is not alone in the classify tree
		else{
			//When reader just want to borrow the first book in the "result vector"
			if (order_id == 1){
				cout << "借阅成功,请注意归还日期" << endl;
				sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
				return true;
			}
			//When reader want to borrow the next book of this book
			else{
				int & tmp = const_cast<int &> (order_id);
				Book * pMove = sear_Book.iter_Vec[order_id - 1]->pNext_Book;
				while (tmp > 2 && pMove != nullptr){
					pMove = pMove->pNext_Book;
					--tmp;
				}
				pMove->isBorrow = true;
				cout << "借阅成功,请注意归还日期" << endl;
			}
		}
	}
	//Other situation,just return false.
	else{
		cout << "此书已被借阅，无法重复借阅" << endl;
		return false;
	}
	return false;
}

//book is from CSearch_Book::result
//borrow_Book_By_pub_Dep borrows book from Classify Tree,so you should deal with the ptr carefully.
bool CReader::borrow_Book_By_pub_Dep(CLibrary & lib, CSearch_Book & sear_Book, const Pub_Dep & p_dep, const int & order_id){
	sear_Book.Search_By_Pub_Dep(lib, p_dep);
	sear_Book.Show_Search_Result();
	//To filter some unvalid input
	if (order_id > sear_Book.result.size()){
		cout << "不存在序号为" << order_id << "的书,请确认后再输入" << endl;
		return false;
	}
	//If reader want give a valid order_id, firstly I will judge the state of the book 

	//If this book is not borrowed
	if (sear_Book.result[order_id - 1].isBorrow == false){
		//If this book is alone in the Classify Tree 
		if (sear_Book.result[order_id - 1].pNext_Book == nullptr){
			cout << "借阅成功,请注意归还日期" << endl;
			sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
			return true;
		}

		//If there exists other books have the same title, in other word,this book is not alone in the classify tree
		else{
			//When reader just want to borrow the first book in the "result vector"
			if (order_id == 1){
				cout << "借阅成功,请注意归还日期" << endl;
				sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
				return true;
			}
			//When reader want to borrow the next book of this book
			else{
				int & tmp = const_cast<int &> (order_id);
				Book * pMove = sear_Book.iter_Vec[order_id - 1]->pNext_Book;
				while (tmp > 2 && pMove != nullptr){
					pMove = pMove->pNext_Book;
					--tmp;
				}
				pMove->isBorrow = true;
				cout << "借阅成功,请注意归还日期" << endl;
			}
		}
	}
	//Other situation,just return false.
	else{
		cout << "此书已被借阅，无法重复借阅" << endl;
		return false;
	}
	return false;
}

//book is from CSearch_Book::result
bool CReader::borrow_Book_By_bID(CLibrary & lib,CSearch_Book & sear_Book, const Book_ID & bid,const int & order_id){
	sear_Book.Search_By_Book_Id(lib, bid);
	if (sear_Book.result[order_id - 1].isBorrow == false){
		sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
		cout << "借阅成功,请注意归还日期" << endl;
		return true;
	}
	else{
		cout << "此书已被借阅，无法重复借阅" << endl;
		return false;
	}
	return false;
}

bool CReader::borrow_Book_By_Pub_Time(CLibrary & lib, CSearch_Book & sear_Book, const Pub_Tim & p_time){
	vector<Book>::const_iterator pos;
	vector<Book>::iterator tmp = sear_Book.result.begin();
	advance(tmp, distance <vector<Book>::const_iterator>(tmp, pos));
	finder_pub_time pub_time(p_time);
	pos = find_if(sear_Book.result.begin(), sear_Book.result.end(), pub_time);
	if (pos == sear_Book.result.end()){
		cout << "查询结果中不存在您指定的出版日期，请检查后重新输入" << endl;
		return false;
	}
	else{
		if (tmp->isBorrow){
			cout << "此书已被借阅，无法重复借阅" << endl;
			return false;
		}
		else{
			tmp->isBorrow = true;
			cout << "借阅成功，请注意归还日期" << endl;
			return true;
		}
	}
	return false;
}

