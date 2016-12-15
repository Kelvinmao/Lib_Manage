//------------------------------------------------
//Title: CSort.cpp
//Type: Source file
//Data: 2016-12-14
//Written By: KelvinMao
//------------------------------------------------

#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
#include"CSort.h"
#include"CLibrary.h"
//#include"Custom_Comp.h"
#include"Data_Structure.h"
using namespace std;

//Why the iterator should be the "rbegin" or "rend"??	Interesting......
bool CSort::Sort_By_Book_Id(CLibrary & lib){
	std::sort(lib.Library.rbegin(),lib.Library.rend(),comp_Two_Book_By_Id);
	return true;
}

bool CSort::Sort_by_Book_Price(CLibrary & lib){
	std::sort(lib.Library.rbegin(), lib.Library.rend(), comp_Two_Book_Book_Price);
	return true;
}

bool CSort::Sort_By_Pub_Time(CLibrary & lib){
	std::sort(lib.Library.rbegin(), lib.Library.rend(), comp_Two_Book_By_Pub_Time);
	return true;
}

