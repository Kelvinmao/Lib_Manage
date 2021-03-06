//------------------------------------------------
//Title: Comp_Structures.h
//Type: Header file
//Data: 2016-12-16
//Written By: KelvinMao
//------------------------------------------------
#include<string>
#include"Data_Structure.h"
using namespace std;
#ifndef COMP_STRUCTURES_H_
#define COMP_STRUCTURES_H_

/*Define "finder" to search books in the classify_Tree*/
typedef struct finder_Tit{
	Book_Title title;
	finder_Tit(const string & tit) :title(tit){}
	bool operator()(const Book & book){ return title == book.B_Tit; }
}finder_Tit;

typedef struct finder_auth_Name{
	Auth_Name auth_name;
	finder_auth_Name(const string & a_name) :auth_name(a_name){}
	bool operator()(const Book & book){ return auth_name == book.A_Name; }
}finder_auth_Name;

typedef struct finder_CID{
	Classify_ID CID;
	finder_CID(const string & cid) :CID(cid){}
	bool operator()(const Book & book){ return CID == book.C_Id; }
}finder_CID;

typedef struct finder_pub_Dep{
	Pub_Dep p_dep;
	finder_pub_Dep(const string & pub_dep) :p_dep(pub_dep){}
	bool operator()(const Book & book){ return p_dep == book.P_Dep; }
}finder_pub_Dep;

typedef struct finder_book_id{
	Book_ID b_id;
	finder_book_id(const Book_ID & bid) :b_id(bid){}
	bool operator()(const Book & book){ return b_id == book.B_Id; }
}finder_book_id;

typedef struct finder_pub_time{
	Pub_Tim p_time;
	finder_pub_time(const Pub_Tim & ptime) : p_time(ptime){}
	bool operator()(const Book & book){ return p_time==book.P_Tim; }
}finder_pub_time;

typedef struct finder_book_price{
	Book_Price b_price;
	finder_book_price(const Book_Price & price) :b_price(price){}
	bool operator()(const Book & book){ return b_price == book.B_Pri; }
}finder_book_price;
//typedef struct sort_book_ID{
//	Book_ID book_id;
//	sort_book_ID(const Book_ID & bid) :book_id(bid){}
//	bool operator ()(const Book & book){ return book_id < book.B_Id; }
//}sort_book_ID;
//
//typedef struct sort_pub_Time{
//	Pub_Tim pub_time;
//	sort_pub_Time(const Pub_Tim & p_tim) :pub_time(p_tim){}
//	bool operator()(const Book & book){ return pub_time < book.P_Tim; }
//}sort_pub_Time;
//
//typedef struct sort_book_price{
//	Book_Price price;
//	sort_book_price(const Book_Price & b_price) :price(b_price){}
//	bool operator()(const Book & book){ return price < book.B_Pri; }
//}sort_book_price;
//
//typedef struct sort_book_pub_time{
//	Pub_Tim p_time;
//	sort_book_pub_time(const Pub_Tim & time) :p_time(time){}
//	bool operator()(const Book & book){ return p_time < book.P_Tim; }
//}sort_book_pub_time;

#endif