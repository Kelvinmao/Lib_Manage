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

bool CSearch_Book::Search_By_Title(const CLibrary & lib,const string & title){
	if (lib.classify_Tree[0]->empty()){
		cout << "待查询序列为空" << endl;
		return false;
	}
	else{
		finder_Tit tar_Title(title);
		list<Book>::iterator fir_Pos;
		Book * pMove = nullptr;
		fir_Pos = find_if(lib.classify_Tree[0]->begin(), lib.classify_Tree[0]->end(),tar_Title);
		//After be searched,its freq should be refresh 
		(*fir_Pos).S_Freq++;
		result.push_back((*fir_Pos));
		pMove = (*fir_Pos).pNext_Book;
		while (pMove){
			result.push_back((*pMove));
			pMove->S_Freq++;
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
		list<Book>::iterator fir_Pos;
		Book * pMove = nullptr;
		fir_Pos = find_if(lib.classify_Tree[1]->begin(), lib.classify_Tree[1]->end(), tar_Auth_Name);
		result.push_back((*fir_Pos));
		(*fir_Pos).S_Freq++;
		pMove = (*fir_Pos).pNext_Book;
		while (pMove){
			result.push_back((*pMove));
			pMove->S_Freq++;
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
		list<Book>::iterator fir_Pos;
		Book * pMove = nullptr;
		fir_Pos = find_if(lib.classify_Tree[2]->begin(), lib.classify_Tree[2]->end(), tar_CID);
		result.push_back((*fir_Pos));
		(*fir_Pos).S_Freq++;
		pMove = (*fir_Pos).pNext_Book;
		while (pMove){
			pMove->S_Freq++;
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
		list<Book>::iterator fir_Pos;
		Book * pMove = nullptr;
		fir_Pos = find_if(lib.classify_Tree[3]->begin(), lib.classify_Tree[3]->end(), tar_Pub_Dep);
		result.push_back((*fir_Pos));
		(*fir_Pos).S_Freq++;
		pMove = (*fir_Pos).pNext_Book;
		while (pMove){
			result.push_back((*pMove));
			pMove->S_Freq++;
			pMove = pMove->pNext_Book;
		}
	}
	return true;
}

//这个方法需要改一下

bool CSearch_Book::Search_By_Book_Id(const CLibrary & lib, const Book_ID & bid){
	if (lib.Library.empty()){
		cout << "待查询序列为空" << endl;
		return false;
	}
	else{
		list<Book>::const_iterator fir_pos;
		finder_book_id b_id(bid);
		fir_pos=find_if(lib.Library.begin(),lib.Library.end(),b_id);
		/*(*fir_pos).S_Freq++;*/
		result.push_back((*fir_pos));
	}
	return true;
}


bool CSearch_Book::Search_By_Pub_Time(const CLibrary & lib, const Pub_Tim & time_low,const Pub_Tim & time_high){
	if (lib.Library.empty()){
		cout << "待查询序列为空" << endl;
		return false;
	}
	else{
		list<Book>::const_iterator low_pos;
		list<Book>::const_iterator high_pos;
		finder_pub_time lower_bound(time_low);
		finder_pub_time higher_bound(time_high);
		low_pos = find_if(lib.Library.begin(), lib.Library.end(),lower_bound);
		high_pos = find_if(lib.Library.begin(), lib.Library.end(), lower_bound);
		for (auto pos = low_pos; pos != high_pos; pos++)
			result.push_back((*pos));
	}
	return true;
}

bool CSearch_Book::Search_By_book_Price(const CLibrary & lib, const Book_Price & low_pri, const Book_Price & high_pri){
	if (lib.Library.empty()){
		cout << "待查询序列为空" << endl;
		return false;
	}
	else{
		list<Book>::const_iterator low_pos;
		list<Book>::const_iterator high_pos;
		finder_book_price lower_bound(low_pri);
		finder_book_price higher_bound(high_pri);
		low_pos = find_if(lib.Library.begin(), lib.Library.end(), lower_bound);
		high_pos = find_if(lib.Library.begin(), lib.Library.end(), higher_bound);
		for (auto pos = low_pos; pos != high_pos; pos++)
			result.push_back((*pos));
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

bool CSearch_Book::Read_From_Cache_File(){
	ifstream fin("Cache.txt",ios_base::in);
	if (!fin.is_open()){
		cout << "缓存文件打开失败" << endl;
		return false;
	}
	else{
		if (fin.peek() == EOF) return false;//The cache file is empty.
		else{
			//此处需要先确定缓存写入格式后，再来填这个坑
			Book * tmp = new Book;
			string str_tmp;
			string item;
			getline(fin, str_tmp);
			istringstream in(str_tmp);
			for (in >> item;)
			return true;
		}
	}
	return true;
}

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
