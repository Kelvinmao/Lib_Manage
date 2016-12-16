//------------------------------------------------
//Title: CSort.cpp
//Type: Source file
//Data: 2016-12-14
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<string>
#include"CSort.h"
#include"CLibrary.h"
#include"Data_Structure.h"
#include"Comp_Structures.h"

using namespace std;

bool Sort_By_Id(const Book & book1, const Book & book2){
	if (book1.B_Id < book2.B_Id)
		return true;
	if (book1.B_Id > book2.B_Id)
		return false;
	return false;
}

//Why the iterator should be the "rbegin" or "rend"??	Interesting......
bool CSort::Sort_By_Book_Id(CLibrary & lib){
	/*sort_book_ID sort_id((*lib.Library.begin()).B_Id);*/
	std::sort(lib.Library.begin(), lib.Library.end(),Sort_By_Id);
	return true;
}

bool CSort::Sort_by_Book_Price(CLibrary & lib){
	/*sort_book_price sort_pri((*lib.Library.begin()).B_Pri);*/
	std::sort(lib.Library.begin(), lib.Library.end(), Sort_By_Id);
	return true;
}

bool CSort::Sort_By_Pub_Time(CLibrary & lib){
	/*sort_book_pub_time sort_tim((*lib.Library.begin()).P_Tim);*/
	std::sort(lib.Library.begin(), lib.Library.end(), Sort_By_Id);
	return true;
}

