//------------------------------------------------
//Title: CSort.h
//Type: Header file
//Data: 2016-12-14
//Written By: KelvinMao
//------------------------------------------------
#ifndef CSORT_H_
#define CSORT_H_

#include<iostream>
#include<fstream>
#include<list>
#include"Data_Structure.h"
#include"CLibrary.h"
using namespace std;

class CLibrary;
class CSort{
private:
	//Let me think over does this class need some private var or methods
	//std::sort is a global function,so comp_ should be static,comp_ methods shouldn't depends on any instance 
	static bool comp_Two_Book_By_Id(Book & book1, Book & book2);
	static bool comp_Two_Book_By_Pub_Time(Book & book1, Book & book2);
	static bool comp_Two_Book_Book_Price(Book & book1, Book & book2);
public:
	bool Sort_By_Book_Id(CLibrary & lib);
	bool Sort_By_Pub_Time(CLibrary & lib);
	bool Sort_by_Book_Price(CLibrary & lib);
};

#endif
