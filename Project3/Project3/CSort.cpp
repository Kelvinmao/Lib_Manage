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
#include"Comp_Functions.h"
using namespace std;

//2016-12-17 I solve the problem by using list<>::sort,what a fucking problem spent my two days!!!
//And why I use std::sort will result error,is this a bug of VS!!!
//Why the iterator should be the "rbegin" or "rend"??	Interesting......
bool CSort::Sort_By_Book_Id(CLibrary & lib){
	lib.Library.sort(sort_by_id);
	return true;
}

bool CSort::Sort_By_Book_Price(CLibrary & lib){
	lib.Library.sort(sort_by_price);
	return true;
}

bool CSort::Sort_By_Pub_Time(CLibrary & lib){
	lib.Library.sort(sort_by_pub_time);
	return true;
}

bool CSort::Sort_By_Search_Freq(CLibrary & lib){
	lib.Library.sort(sort_by_sear_freq);
	return true;
}