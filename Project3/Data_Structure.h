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
#define Book_ID int //ID of a book(ͼ����)
#define Book_Title string //Title of a book(����)
#define Auth_Name string //Author's name�����ߣ�
#define Classify_ID string //������ţ�
#define Pub_Dep string //Publish department (������)
#define Pub_Tim string //The publishing time of a book(��������)
#define Auth_Pub string //A publish department ,which publish one author's book(������ĳ����ȫ����ĳ�����)
#define Pub_Auth string //All author belongs to the publish department(ĳ������ǩԼ����)
#define Book_Price float //(�۸�)
#define Auth_Comm_Add string //Add is the method you can connect with the author��������ϵ��ʽ��
#define Pub_Comm_Add string //the method you can connect with the publish department
#define Sear_Freq int //the search frequency of a book
#define Surplus int//the residue of a book
#define Status bool//The status of a book
#define Bor_Tim int//The longest time of a book can be borrowed

//Defination of Book
struct SBook{
	SBook(){}
	SBook(
		Surplus sur,
		Sear_Freq freq,
		Book_ID bid,
		Book_Title tit,
		Auth_Name name,
		Classify_ID cid,
		Pub_Dep pub,
		Book_Price price,
		Pub_Tim time,
		Bor_Tim btime=0,
		Status state=false,
		SBook * pt = nullptr
		) :B_surplus(sur), S_Freq(freq), B_Id(bid), B_Tit(tit), A_Name(name), C_Id(cid), P_Dep(pub), B_Pri(price), P_Tim(time), isBorrow(state), b_Time(btime),pNext_Book(pt){}
	bool operator <(const SBook & book){ return B_surplus < book.B_surplus; }
	SBook * pNext_Book;//Book�ṹ�м�һ��ָ���򣬰Ѿ�����ͬ���Ե��鴮������
	Surplus B_surplus;//ʣ����
	Sear_Freq S_Freq; //������Ƶ�ʣ�
	Book_ID B_Id; //(��Ŀ���)
	Book_Title B_Tit; //(����)
	Auth_Name A_Name; //(������)
	Classify_ID C_Id; //(�����)
	Pub_Dep P_Dep; //(��������)
	Book_Price B_Pri; //(�۸�)
	Pub_Tim P_Tim;//(��������)
	Status isBorrow;//���Ƿ񱻽��ģ�
	Bor_Tim b_Time;//�����ʱ��
	list<SBook> book_Ls;
};

typedef struct SBook Book;

//Defination of Author
struct SAuthor{
	Auth_Name A_Name;
	vector<Book_Title> Title_Vec; //All book written by the author������д�������飩
	vector<Auth_Pub> Pub; //All publish department ,which publish this author's book(���г����Ȿ��ĳ�����)
	Auth_Comm_Add Auth_Add;//(������ϵ��ʽ)
};

//Defination of publish department
struct SPublish_Dep{
	Pub_Dep P_Name; //The name of the publish department������������
	vector<Book_Title> P_Title_Vec;//All books published by the publish department��������������������
	vector<Pub_Auth> Auth;//All author belongs to the publish department(ĳ������ǩԼ����)
	Pub_Comm_Add Pub_Add; //(��������ϵ��ʽ)
};

//typedef list<Book> * List_head;
/**********************************************/
/*The headers are:
1.B_Tit
2.A_Name
3.C_ID
4.Pub_Dep*/
/**********************************************/
//typedef vector<List_head> Classify_Tree;
typedef vector<list<Book>> Classify_Tree;
#endif