//------------------------------------------------
//Title: CBook.cpp
//Type: Source file
//Data: 2016-12-14
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<list>
#include<algorithm>
#include"CSort.h"
#include"CLibrary.h"
#include"Data_Structure.h"
using namespace std;

/*Define custom Compare functions*/
bool CSort::comp_Two_Book_Book_Price(Book & book1, Book & book2){
	return book1.B_Pri > book2.B_Pri;
}

bool CSort::comp_Two_Book_By_Id(Book & book1, Book & book2){
	return book1.B_Id > book2.B_Id;
}

bool CSort::comp_Two_Book_By_Pub_Time(Book & book1, Book & book2){
	return book1.P_Tim > book2.P_Tim;
}

bool CSort::Sort_By_Book_Id(CLibrary & lib){
	sort(lib.Library.begin(), lib.Library.end(), comp_Two_Book_By_Id);
	return true;
}

bool CSort::Sort_by_Book_Price(CLibrary & lib){
	sort(lib.Library.begin(), lib.Library.end(), comp_Two_Book_Book_Price);
	return true;
}

bool CSort::Sort_By_Pub_Time(CLibrary & lib){
	sort(lib.Library.begin(), lib.Library.end(), comp_Two_Book_By_Pub_Time);
	return true;
}

