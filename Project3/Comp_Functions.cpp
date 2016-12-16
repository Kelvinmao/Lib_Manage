//------------------------------------------------
//Title: Comp_Functions.cpp
//Type: Source file
//Data: 2016-12-16
//Written By: KelvinMao
//------------------------------------------------

#include<string>
#include"Data_Structure.h"
#include"Comp_Functions.h"
using namespace std;

bool same_Auth_Name(const string & A_Name,const SBook & book){
	return A_Name == book.A_Name;
}

bool same_cID(const string & C_Id,const SBook & book){
	return C_Id == book.C_Id;
}

bool same_Pub_Dep(const string & P_Dep,const SBook & book){
	return P_Dep == book.P_Dep;
}

bool same_Title(const string & B_Tit,const SBook & book){
	return B_Tit == book.B_Tit;
}