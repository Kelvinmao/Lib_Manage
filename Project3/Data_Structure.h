//------------------------------------------------
//Title: Data_Structure.h
//Type: Header file
//Data: 2016-12-08
//Written By: KelvinMao
//------------------------------------------------
#ifndef Data_Strcture_H_
#define Data_Strcture_H_

#include<string>
#include<vector>
#include<list>
using namespace std;
//using std::string

//Some macro defination
#define Book_ID int //ID of a book(图书编号)
#define Book_Title string //Title of a book(标题)
#define Auth_Name string //Author's name（作者）
#define Classify_ID string //（分类号）
#define Pub_Dep string //Publish department (出版社)
#define Pub_Tim string //The publishing time of a book(出版日期)
#define Auth_Pub string //A publish department ,which publish one author's book(出版了某作者全部书的出版社)
#define Pub_Auth string //All author belongs to the publish department(某社所有签约作者)
#define Book_Price float //(价格)
#define Auth_Comm_Add string //Add is the method you can connect with the author（作者联系方式）
#define Pub_Comm_Add string //the method you can connect with the publish department
#define Sear_Freq int //the search frequency of a book
#define Surplus int//the residue of a book

//Defination of Book
struct SBook{
	SBook * pNext_Book;//Book结构中加一个指针域，把具有相同属性的书串成链表
	Surplus B_surplus;//剩余量
	Sear_Freq S_Freq; //（查找频率）
	Book_ID B_Id; //(书目编号)
	Book_Title B_Tit; //(书名)
	Auth_Name A_Name; //(作者名)
	Classify_ID C_Id; //(分类号)
	Pub_Dep P_Dep; //(出版社名)
	Book_Price B_Pri; //(价格)
	Pub_Tim P_Tim;//(出版日期)
};

typedef struct SBook Book;

//Defination of Author
struct SAuthor{
	Auth_Name A_Name;
	vector<Book_Title> Title_Vec; //All book written by the author（作者写的所有书）
	vector<Auth_Pub> Pub; //All publish department ,which publish this author's book(所有出版这本书的出版社)
	Auth_Comm_Add Auth_Add;//(作者联系方式)
};

//Defination of publish department
struct SPublish_Dep{
	Pub_Dep P_Name; //The name of the publish department（出版社名）
	vector<Book_Title> P_Title_Vec;//All books published by the publish department（该社出版的所有书名）
	vector<Pub_Auth> Auth;//All author belongs to the publish department(某社所有签约作者)
	Pub_Comm_Add Pub_Add; //(出版社联系方式)
};

typedef list<Book> * List_head;
/**********************************************/
/*The headers are:
1.B_Tit
2.A_Name
3.C_ID
4.Pub_Dep*/
/**********************************************/
typedef vector<List_head> Classify_Tree;

#endif