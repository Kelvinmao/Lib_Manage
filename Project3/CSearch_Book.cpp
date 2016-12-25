//------------------------------------------------
//Title: CSearch_Book.cpp
//Type: Source file
//Data: 2016-12-14
//Written By: KelvinMao
//------------------------------------------------

#include<algorithm>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<list>
#include"Finder_Structures.h"
#include"Data_Structure.h"
#include"CSearch_Book.h"
#include"CLibrary.h"
#include"CSort.h"
using namespace std;

//
bool CSearch_Book::Search_By_Title(CLibrary & lib, const string & title){
	if (result.empty()==false){
		result.clear();
		iter_Vec.clear();
	}
	if (lib.classify_Tree[0].empty()==true){
		cout << "待查找序列为空" << endl;
		return false;
	}
	else{
		finder_Tit b_Title(title);
		list<Book>::const_iterator s_pos = find_if(lib.classify_Tree[0].begin(), lib.classify_Tree[0].end(), b_Title);
		list<Book>::iterator tmp = lib.classify_Tree[0].begin();
		advance(tmp, distance<list<Book>::const_iterator>(lib.classify_Tree[0].begin(), s_pos));
		if (s_pos == lib.classify_Tree[0].end()){
			cout << "未找到指定书籍" << endl;
			return false;
		}
		else{
			if (s_pos->book_Ls.empty() && s_pos->B_Tit==title){
				result.push_back((*s_pos));
				iter_Vec.push_back(tmp);
				tmp->S_Freq++;
			}
			else{
				result.push_back((*s_pos));
				list<Book>::iterator tmp_2 = tmp->book_Ls.begin();
				for (tmp_2; tmp_2 != s_pos->book_Ls.end() && tmp_2->B_Tit==title; ++tmp_2){
					result.push_back((*tmp_2));
					iter_Vec.push_back(tmp_2);
					tmp_2->S_Freq++;
				}
			}
		}
	}
	return true;
}

bool CSearch_Book::Search_By_Auth_Name(CLibrary & lib,const string & auth_Name){
	if (result.empty() == false){
		result.clear();
		iter_Vec.clear();
	}
	if (lib.classify_Tree[1].empty()){
		cout << "待查找序列为空" << endl;
		return false;
	}
	else{
		finder_auth_Name auth(auth_Name);
		list<Book>::const_iterator s_pos = find_if(lib.classify_Tree[1].begin(), lib.classify_Tree[1].end(), auth);
		list<Book>::iterator tmp = lib.classify_Tree[1].begin();
		advance(tmp, distance<list<Book>::const_iterator>(lib.classify_Tree[1].begin(), s_pos));
		if (s_pos == lib.classify_Tree[1].end()){
			cout << "未找到指定书籍" << endl;
			return false;
		}
		else{
			if (s_pos->book_Ls.empty() && s_pos->A_Name==auth_Name){
				result.push_back((*s_pos));
				iter_Vec.push_back(tmp);
				tmp->S_Freq++;
			}
			else{
				result.push_back((*s_pos));
				list<Book>::iterator tmp_2 = tmp->book_Ls.begin();
				for (tmp_2; tmp_2 != s_pos->book_Ls.end()&&tmp_2->A_Name==auth_Name; ++tmp_2){
					result.push_back((*tmp_2));
					iter_Vec.push_back(tmp_2);
					tmp_2->S_Freq++;
				}
			}
		}
	}
	return true;
}

bool CSearch_Book::Search_By_CId(CLibrary & lib, const string & c_ID){
	if (result.empty() == false){
		result.clear();
		iter_Vec.clear();
	}
	if (lib.classify_Tree[2].empty()){
		cout << "待查找序列为空" << endl;
		return false;
	}
	else{
		finder_CID CId(c_ID);
		list<Book>::const_iterator s_pos = find_if(lib.classify_Tree[2].begin(), lib.classify_Tree[2].end(), CId);
		list<Book>::iterator tmp = lib.classify_Tree[2].begin();
		advance(tmp, distance<list<Book>::const_iterator>(lib.classify_Tree[2].begin(), s_pos));
		if (s_pos == lib.classify_Tree[2].end()){
			cout << "未找到指定书籍" << endl;
			return false;
		}
		else{
			if (s_pos->book_Ls.empty() && s_pos->C_Id==c_ID){
				result.push_back((*s_pos));
				iter_Vec.push_back(tmp);
				tmp->S_Freq++;
			}
			else{
				result.push_back((*s_pos));
				list<Book>::iterator tmp_2 = tmp->book_Ls.begin();
				for (tmp_2; tmp_2 != s_pos->book_Ls.end() && tmp_2->C_Id==c_ID; ++tmp_2){
					result.push_back((*tmp_2));
					iter_Vec.push_back(tmp_2);
					tmp_2->S_Freq++;
				}
			}
		}
	}
	return true;
}
//
bool CSearch_Book::Search_By_Pub_Dep(CLibrary & lib, const string & pub_Dep){
	if (result.empty() == false){
		result.clear();
		iter_Vec.clear();
	}
	if (lib.classify_Tree[3].empty()){
		cout << "待查找序列为空" << endl;
		return false;
	}
	else{
		finder_pub_Dep p_Dep(pub_Dep);
		list<Book>::const_iterator s_pos = find_if(lib.classify_Tree[3].begin(), lib.classify_Tree[3].end(),p_Dep);
		list<Book>::iterator tmp = lib.classify_Tree[3].begin();
		advance(tmp, distance<list<Book>::const_iterator>(lib.classify_Tree[3].begin(), s_pos));
		if (s_pos == lib.classify_Tree[3].end()){
			cout << "未找到指定书籍" << endl;
			return false;
		}
		else{
			if (s_pos->book_Ls.empty() && s_pos->P_Dep==pub_Dep){
				result.push_back((*s_pos));
				iter_Vec.push_back(tmp);
				tmp->S_Freq++;
			}
			else{
				result.push_back((*s_pos));
				list<Book>::iterator tmp_2 = tmp->book_Ls.begin();
				for (tmp_2; tmp_2 != s_pos->book_Ls.end() && tmp_2->P_Dep==pub_Dep; ++tmp_2){
					result.push_back((*tmp_2));
					iter_Vec.push_back(tmp_2);
					tmp_2->S_Freq++;
				}
			}
		}
	}
	return true;
}

//这个方法需要改一下

bool CSearch_Book::Search_By_Book_Id(CLibrary & lib, const Book_ID & bid){
	if (result.empty() == false){
		result.clear();
		iter_Vec.clear();
	}
	if (lib.Library.empty()){
		cout << "待查询序列为空" << endl;
		return false;
	}
	else{
		finder_book_id b_ID(bid);
		list<Book>::iterator s_pos = find_if(lib.Library.begin(), lib.Library.end(), b_ID);
		if (s_pos == lib.Library.end()){
			cout << "未找到您指定的书籍" << endl;
			return false;
		}
		else{
			result.push_back((*s_pos));
			iter_Vec.push_back(s_pos);
			s_pos->S_Freq++;
		}
	}
	return true;
}


bool CSearch_Book::Search_By_Pub_Time(const CLibrary & lib, const Pub_Tim & time_low,const Pub_Tim & time_high){
	if (!result.empty()){
		result.clear();
		iter_Vec.clear();
	}
	list<Book>::const_iterator low_pos;
	list<Book>::const_iterator high_pos;
	finder_pub_time lower_bound(time_low);
	finder_pub_time higher_bound(time_high);
	low_pos = find_if(lib.Library.begin(), lib.Library.end(), lower_bound);
	high_pos = find_if(lib.Library.begin(), lib.Library.end(), lower_bound);
	for (auto pos = low_pos; pos != high_pos; pos++){
		result.push_back((*pos));
		list<Book>::iterator tmp;
		advance(tmp, distance<list<Book>::const_iterator>(lib.Library.begin(), pos));
		iter_Vec.push_back(tmp);
	}
	return true;
}

bool CSearch_Book::Search_By_book_Price(const CLibrary & lib, const Book_Price & low_pri, const Book_Price & high_pri){
	if (lib.Library.empty()){
		cout << "待查询序列为空" << endl;
		return false;
	}
	if (!result.empty()){
		result.clear();
		iter_Vec.clear();
	}
	list<Book>::const_iterator low_pos;
	list<Book>::const_iterator high_pos;
	finder_book_price lower_bound(low_pri);
	finder_book_price higher_bound(high_pri);
	low_pos = find_if(lib.Library.begin(), lib.Library.end(), lower_bound);
	high_pos = find_if(lib.Library.begin(), lib.Library.end(), higher_bound);
	for (auto pos = low_pos; pos != high_pos; pos++){
		result.push_back((*pos));
		list<Book>::iterator tmp;
		advance(tmp, distance<list<Book>::const_iterator>(lib.Library.begin(), pos));
		iter_Vec.push_back(tmp);
	}
	return true;
}

ofstream & operator <<(ofstream & fout,const Book & book){
	fout << book.A_Name << " " << book.B_Id << " " << book.B_Pri << " " << book.B_Tit << " ";
	fout << book.C_Id << " " << book.P_Dep << " " << book.P_Tim << " " << endl;
	return fout;
}

bool CSearch_Book::Add_Book_Into_Cache(CLibrary & lib){
	if (lib.Library.empty())
		return false;
	else{
		CSort c_sort;
		c_sort.Sort_By_Search_Freq(lib);
		list<Book>::const_iterator pos = lib.Library.begin();
		for (pos; pos != lib.Library.end(); ++pos){
			int count = 0;
			if (count < cache_Max)
				Cache.push_back((*pos));
			else
				break;
			++count;
		}
	}
	return true;
}

bool CSearch_Book::Set_Max_Cache(){
	cout << "请输入最大缓存数量(小于100)" << endl;
	cin >> cache_Max;
	while (cache_Max>100){
		cout << "输入数值过大，请重新输入" << endl;
		cin >> cache_Max;
	}
	return true;
}

//TODO:Finish this method
//bool CSearch_Book::Read_From_Cache_File(){
//	ifstream fin("Cache.txt",ios_base::in);
//	if (!fin.is_open()){
//		cout << "缓存文件打开失败" << endl;
//		return false;
//	}
//	else{
//		if (fin.peek() == EOF) return false;//The cache file is empty.
//		else{
//			//此处需要先确定缓存写入格式后，再来填这个坑
//			Book * tmp = new Book;
//			string str_tmp;
//			string item;
//			getline(fin, str_tmp);
//			istringstream in(str_tmp);
//			for (in >> item;)
//			return true;
//		}
//	}
//	return true;
//}

bool CSearch_Book::Write_Cache_Into_File(){
	ofstream fout("Cache.txt", ios_base::app);
	if (!fout.is_open()){
		cout << "缓存文件打开失败" << endl;
		return false;
	}
	else{
		vector<Book>::iterator pos = Cache.begin();
		for (pos; pos != Cache.end(); pos++)
			fout << (*pos);
	}
	return true;
}

bool CSearch_Book::Show_Search_Result(){
	if (result.empty()){
		cout << "没有查找到相应书籍" << endl;
	}
	vector<Book>::const_iterator pos = result.cbegin();
	for (pos; pos != result.cend(); ++pos){
		cout << pos->B_Tit << "   " << pos->A_Name << "   " << pos->P_Dep<<"   ";
		if (pos->isBorrow==true)
			cout << "已借出"<<endl;
		else
			cout << "可借阅"<<endl;
	}
	return true;
}