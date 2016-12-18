//------------------------------------------------
//Title: Custom_Comp.h
//Type: Header file
//Data: 2016-12-15
//Written By: KelvinMao
//------------------------------------------------

#include"Data_Structure.h"
using namespace std;
/*Define custom Compare functions*/
static bool comp_Two_Book_Book_Price(Book & book1, Book & book2){
	/*if (book1.B_Pri > book2.B_Pri)
		return true;
	if (book1.B_Pri < book2.B_Pri)
		return false;
	return false;*/
	return book1.B_Pri > book2.B_Pri;
}

static bool comp_Two_Book_By_Id(Book & book1, Book & book2){
	/*if (book1.B_Id > book2.B_Id)
		return true;
	if (book1.B_Id < book2.B_Id)
		return false;
	return false;*/
	return book1.B_Id > book2.B_Id;
}

static bool comp_Two_Book_By_Pub_Time(Book & book1, Book & book2){
	/*if (book1.P_Tim > book2.P_Tim)
		return true;
	if (book1.P_Tim < book2.P_Tim)
		return false;
	return false;*/
	return book1.P_Tim > book2.P_Tim;
}
