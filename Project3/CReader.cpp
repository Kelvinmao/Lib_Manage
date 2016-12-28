//------------------------------------------------
//Title: CReader.cpp
//Type: Source file
//Data: 2016-12-19
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<list>
#include"Finder_Structures.h"
#include"Data_Structure.h"
#include"CSearch_Book.h"
#include"CPassword.h"
#include"CLibrary.h"
#include"CReader.h"
using namespace std;

class CSearch_Book;
class Password;
class CLibrary;

//sign_Up_As_A_New_Reader
bool CReader::sign_Up_As_A_New_Reader(CLibrary & lib){
	Password password;
	cout << "请填写下面的信息用于注册成为本馆会员" << endl;
	cout << "学号:" << endl;
	cin >> r_ID;
	char tmp = getchar();
	cout << "姓名:" << endl;
	cin >> r_Name;
	tmp = getchar();
	cout << "电子邮箱:" << endl;
	cin >> comm_Addr;
	tmp = getchar();
	cout << "手机号码:" << endl;
	cin >> phone_Num;
	tmp = getchar();
	password.inputPassword();
	r_password = password.getPassword();
	cout <<endl<< "请确认您的信息" << endl;
	cout << "姓名: " << r_Name << endl << "学号: " << r_ID << endl << endl << "电子邮箱: " << comm_Addr << endl;
	cout << "手机号码: " << phone_Num << endl;
	lib.readers_Vec.push_back((*this));
	lib.new_Reader_Vec.push_back((*this));
	return true;
}

//book is from CSearch_Book::result
//borrow_Book_By_Title borrows book from Classify Tree,so you should deal with the ptr carefully.
bool CReader::borrow_Book_By_Title(CLibrary & lib, CSearch_Book & sear_Book,const Book_Title & book_Tit){
	sear_Book.Search_By_Title(lib,book_Tit);
	sear_Book.Show_Search_Result();
	int order_id = 0;
	cout << "请输入您需要的书的序号(在搜索结果中的顺序)" << endl;
	cin >> order_id;
	//To filter some unvalid input
	if (order_id > sear_Book.result.size()){
		cout << "不存在序号为" << order_id << "的书,请确认后再输入" << endl;
		return false;
	}
	//If reader want give a valid order_id, I will judge the state of the book firstly 

	//If this book is not borrowed
	if (sear_Book.result[order_id - 1].isBorrow == false){
		if (sear_Book.result[order_id - 1].book_Ls.empty()){
			cout << "您已经借阅本馆藏书:" << "标题为: " << sear_Book.iter_Vec[order_id - 1]->B_Tit;
			cout << "出版社为: " << sear_Book.iter_Vec[order_id - 1]->P_Dep;
			cout << "作者为: " << sear_Book.iter_Vec[order_id - 1]->A_Name << endl;
			cout << "借阅成功,请注意归还日期" << endl;
			sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
			return true;
		}
		//If there exists other books have the same title, in other word,this book is not alone in the classify tree
		else{
			//When reader just want to borrow the first book in the "result vector"
			if (order_id == 1){
				cout << "您已经借阅本馆藏书:" << "标题为: " << sear_Book.iter_Vec[order_id-1]->B_Tit;
				cout << "出版社为: " << sear_Book.iter_Vec[order_id - 1]->P_Dep;
				cout << "作者为: " << sear_Book.iter_Vec[order_id - 1]->A_Name << endl;
				cout << "借阅成功,请注意归还日期" << endl;
				sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
				return true;
			}
			else{
				//When reader want to borrow the next book of this book
				int & tmp=const_cast<int &> (order_id);
				list<Book>::iterator tmp_pos= sear_Book.iter_Vec[order_id - 1]->book_Ls.begin();
				while (tmp > 2 && tmp_pos != sear_Book.iter_Vec[order_id - 1]->book_Ls.end()){
					++tmp_pos;
					--tmp;
				}
				tmp_pos->isBorrow = true;
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
bool CReader::borrow_Book_By_Auth(CLibrary & lib, CSearch_Book & sear_Book, const Auth_Name & a_name){
	sear_Book.Search_By_Auth_Name(lib,a_name);
	sear_Book.Show_Search_Result();
	int order_id = 0;
	cout << "请输入您需要的书的序号(在搜索结果中的顺序)" << endl;
	cin >> order_id;
	//To filter some unvalid input
	if (order_id > sear_Book.result.size()){
		cout << "不存在序号为" << order_id << "的书,请确认后再输入" << endl;
		return false;
	}
	//If reader want give a valid order_id, firstly I will judge the state of the book 

	//If this book is not borrowed
	//If this book is not borrowed
	if (sear_Book.result[order_id - 1].isBorrow == false){
		if (sear_Book.result[order_id - 1].book_Ls.empty()){
			cout << "您已经借阅本馆藏书:" << "标题为: " << sear_Book.iter_Vec[order_id - 1]->B_Tit;
			cout << "出版社为: " << sear_Book.iter_Vec[order_id - 1]->P_Dep;
			cout << "作者为: " << sear_Book.iter_Vec[order_id - 1]->A_Name << endl;
			cout << "借阅成功,请注意归还日期" << endl;
			sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
			return true;
		}
		//If there exists other books have the same title, in other word,this book is not alone in the classify tree
		else{
			//When reader just want to borrow the first book in the "result vector"
			if (order_id == 1){
				cout << "您已经借阅本馆藏书:" << "标题为: " << sear_Book.iter_Vec[order_id - 1]->B_Tit;
				cout << "出版社为: " << sear_Book.iter_Vec[order_id - 1]->P_Dep;
				cout << "作者为: " << sear_Book.iter_Vec[order_id - 1]->A_Name << endl;
				cout << "借阅成功,请注意归还日期" << endl;
				sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
				return true;
			}
			else{
				//When reader want to borrow the next book of this book
				int & tmp = const_cast<int &> (order_id);
				list<Book>::iterator tmp_pos = sear_Book.iter_Vec[order_id - 1]->book_Ls.begin();
				while (tmp > 2 && tmp_pos != sear_Book.iter_Vec[order_id - 1]->book_Ls.end()){
					++tmp_pos;
					--tmp;
				}
				tmp_pos->isBorrow = true;
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
bool CReader::borrow_Book_By_cID(CLibrary & lib, CSearch_Book & sear_Book, const Classify_ID & cid){
	sear_Book.Search_By_CId(lib, cid);
	sear_Book.Show_Search_Result();
	int order_id = 0;
	cout << "请输入您需要的书的序号(在搜索结果中的顺序)" << endl;
	cin >> order_id;
	//To filter some unvalid input
	if (order_id > sear_Book.result.size()){
		cout << "不存在序号为" << order_id << "的书,请确认后再输入" << endl;
		return false;
	}
	//If reader want give a valid order_id, firstly I will judge the state of the book 

	//If this book is not borrowed
	if (sear_Book.result[order_id - 1].isBorrow == false){
		if (sear_Book.result[order_id - 1].book_Ls.empty()){
			cout << "您已经借阅本馆藏书:" << "标题为: " << sear_Book.iter_Vec[order_id - 1]->B_Tit;
			cout << "出版社为: " << sear_Book.iter_Vec[order_id - 1]->P_Dep;
			cout << "作者为: " << sear_Book.iter_Vec[order_id - 1]->A_Name << endl;
			cout << "借阅成功,请注意归还日期" << endl;
			sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
			return true;
		}
		//If there exists other books have the same title, in other word,this book is not alone in the classify tree
		else{
			//When reader just want to borrow the first book in the "result vector"
			if (order_id == 1){
				cout << "您已经借阅本馆藏书:" << "标题为: " << sear_Book.iter_Vec[order_id - 1]->B_Tit;
				cout << "出版社为: " << sear_Book.iter_Vec[order_id - 1]->P_Dep;
				cout << "作者为: " << sear_Book.iter_Vec[order_id - 1]->A_Name << endl;
				cout << "借阅成功,请注意归还日期" << endl;
				sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
				return true;
			}
			else{
				//When reader want to borrow the next book of this book
				int & tmp = const_cast<int &> (order_id);
				list<Book>::iterator tmp_pos = sear_Book.iter_Vec[order_id - 1]->book_Ls.begin();
				while (tmp > 2 && tmp_pos != sear_Book.iter_Vec[order_id - 1]->book_Ls.end()){
					++tmp_pos;
					--tmp;
				}
				tmp_pos->isBorrow = true;
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
bool CReader::borrow_Book_By_pub_Dep(CLibrary & lib, CSearch_Book & sear_Book, const Pub_Dep & p_dep){
	sear_Book.Search_By_Pub_Dep(lib, p_dep);
	sear_Book.Show_Search_Result();
	int order_id = 0;
	cout << "请输入您需要的书的序号(在搜索结果中的顺序)" << endl;
	cin >> order_id;
	//To filter some unvalid input
	if (order_id > sear_Book.result.size()){
		cout << "不存在序号为" << order_id << "的书,请确认后再输入" << endl;
		return false;
	}
	//If reader want give a valid order_id, firstly I will judge the state of the book 

	//If this book is not borrowed
	if (sear_Book.result[order_id - 1].isBorrow == false){
		if (sear_Book.result[order_id - 1].book_Ls.empty()){
			cout << "您已经借阅本馆藏书:" << "标题为: " << sear_Book.iter_Vec[order_id - 1]->B_Tit;
			cout << "出版社为: " << sear_Book.iter_Vec[order_id - 1]->P_Dep;
			cout << "作者为: " << sear_Book.iter_Vec[order_id - 1]->A_Name << endl;
			cout << "借阅成功,请注意归还日期" << endl;
			sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
			return true;
		}
		//If there exists other books have the same title, in other word,this book is not alone in the classify tree
		else{
			//When reader just want to borrow the first book in the "result vector"
			if (order_id == 1){
				cout << "您已经借阅本馆藏书:" << "标题为: " << sear_Book.iter_Vec[order_id - 1]->B_Tit;
				cout << "出版社为: " << sear_Book.iter_Vec[order_id - 1]->P_Dep;
				cout << "作者为: " << sear_Book.iter_Vec[order_id - 1]->A_Name << endl;
				cout << "借阅成功,请注意归还日期" << endl;
				sear_Book.iter_Vec[order_id - 1]->isBorrow = true;
				return true;
			}
			else{
				//When reader want to borrow the next book of this book
				int & tmp = const_cast<int &> (order_id);
				list<Book>::iterator tmp_pos = sear_Book.iter_Vec[order_id - 1]->book_Ls.begin();
				while (tmp > 2 && tmp_pos != sear_Book.iter_Vec[order_id - 1]->book_Ls.end()){
					++tmp_pos;
					--tmp;
				}
				tmp_pos->isBorrow = true;
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
bool CReader::borrow_Book_By_bID(CLibrary & lib,CSearch_Book & sear_Book, const Book_ID & bid){
	sear_Book.Search_By_Book_Id(lib, bid);
	sear_Book.Show_Search_Result();
	if (sear_Book.iter_Vec[0]->isBorrow == false){
		cout << "您已经借阅本馆藏书:" << "标题为: " << sear_Book.iter_Vec[0]->B_Tit;
		cout << "出版社为: " << sear_Book.iter_Vec[0]->P_Dep;
		cout << "作者为: " << sear_Book.iter_Vec[0]->A_Name << endl;
		sear_Book.iter_Vec[0]->isBorrow = true;
		cout << "借阅成功,请注意归还日期" << endl;
		return true;
	}
	else{
		cout << sear_Book.result[0].isBorrow;
		cout << "此书已被借阅，无法重复借阅" << endl;
		return false;
	}
	return false;
}

bool CReader::give_Back_Book(CSearch_Book & sear_Book, const Book_ID & bid){
	vector<list<Book>::iterator>::iterator i_pos=sear_Book.iter_Vec.begin();
	vector<Book *>::iterator p_pos=sear_Book.ptr_Vec.begin();
	for (i_pos; i_pos != sear_Book.iter_Vec.end(); ++i_pos){
		if (bid == (*i_pos)->B_Id && (*i_pos)->isBorrow){
			(*i_pos)->isBorrow = false;
			cout << "归还成功" << endl;
			return true;
		}
	}
	for (p_pos; p_pos != sear_Book.ptr_Vec.end(); ++p_pos){
		if (bid == (*p_pos)->B_Id && (*p_pos)->isBorrow){
			(*p_pos)->isBorrow = false;
			cout << "归还成功" << endl;
			return true;
		}
	}
	if (i_pos == sear_Book.iter_Vec.end() && p_pos == sear_Book.ptr_Vec.end()){
		cout << "图书编号有误，请检查您的输入信息" << endl;
		return false;
	}
	return false;
}

bool CReader::show_All_Borrowed_Books(){
	list<Book>::const_iterator pos = borrowed_Book.cbegin();
	cout << "您一共借阅了" << borrowed_Book.size() << "本书" << endl;
	for (pos; pos != borrowed_Book.cend(); ++pos){
		cout << pos->B_Tit << "   " << pos->A_Name << "    " << pos->P_Dep << "    ";
		cout << "热度" << pos->S_Freq << endl;
	}
	return true;
}

bool CReader::write_Readers_Info_Into_File(const CLibrary & lib){
	ofstream fout("all_Readers.txt", ios_base::app);
	if (!fout.is_open()){
		cout << "用户数据文件打开失败" << endl;
		return false;
	}
	else{
		//It's better to just append new_readers into the file
		//vector<CReader>::const_iterator c_iter = lib.readers_Vec.cbegin();
		vector<CReader>::const_iterator c_iter = lib.new_Reader_Vec.cbegin();
		for (c_iter; c_iter != lib.new_Reader_Vec.cend(); ++c_iter){
			fout << c_iter->r_ID << "    " << c_iter->r_Name << "    " << c_iter->comm_Addr<<"    ";
			fout << c_iter->phone_Num << "    " << c_iter->r_password << endl;
		}
		return true;
	}
	return false;
}

bool CReader::read_Readers_Info_From_File(CLibrary & lib){
	ifstream fin("all_Readers.txt", ios_base::in);
	string tmp[100];
	if (fin.is_open() == false){
		cout << "用户数据文件打开失败" << endl;
		return false;
	}
	else{
		int count = 0;
		while (getline(fin, tmp[count % 100]) && tmp[count % 100].size() > 0){
			istringstream str(tmp[count % 100]);
			string tmp[5];
			int i = 0;
			for (string item; str >> item; i++)
				tmp[i] = item;
			CReader * reader = new CReader;
			reader->r_ID = tmp[0];
			reader->r_Name = tmp[1];
			reader->comm_Addr = tmp[2];
			reader->phone_Num = tmp[3];
			reader->r_password = tmp[4];
			lib.readers_Vec.push_back((*reader));
			delete reader;
			count++;
		}
		fin.close();
	}
	return true;
}

bool CReader::renew_Book(const Book_ID & bid,CLibrary & lib,CSearch_Book & sear_Book){
	list<Book> ::iterator i_pos = borrowed_Book.begin();
	for (i_pos; i_pos != borrowed_Book.end(); ++i_pos){
		if (i_pos->B_Id == bid){
			i_pos->b_Time = 30;
			cout << "续借成功" << endl;
			return true;
		}
	}
	if (i_pos == borrowed_Book.end()){
		cout << "未能找到与您指定的书目编号相同的书，请检查后重试" << endl;
		return false;
	}
	return false;
}

bool CReader::change_Reader_Name(){
	string tmp;
	cout << "请输入新用户名" << endl;
	cin >> tmp;
	r_Name = tmp;
	return true;
}

bool CReader::change_Reader_ID(){
	string tmp;
	cout << "请输入新学号" << endl;
	cin >> tmp;
	r_ID = tmp;
	return true;
}

bool CReader::change_Reader_Email_Addr(){
	string tmp;
	cout << "请输入新邮箱" << endl;
	cin >> tmp;
	comm_Addr = tmp;
	return true;
}

bool CReader::change_Reader_Phone_Num(){
	string tmp;
	cout << "请输入新手机号码" << endl;
	cin >> tmp;
	phone_Num = tmp;
	return true;
}

bool CReader::change_Reader_Password(){
	string tmp_pass;
	string new_pass;
	cout << "请输入旧密码" << endl;
	cin >> tmp_pass;
	if (tmp_pass == r_password){
		cout << "请输入新密码" << endl;
		cin >> new_pass;
		r_password = new_pass;
		return true;
	}
	else{
		cout << "旧密码有误" << endl;
		return false;
	}
	return false;
}