//------------------------------------------------
//Title: Comp_Structures.h
//Type: Header file
//Data: 2016-12-17
//Written By: KelvinMao
//------------------------------------------------

#include"Data_Structure.h"

//Define some inline functions,to sort element as my meaning.
bool sort_by_id(const Book  book1, const Book & book2){
	if (book1.B_Id < book2.B_Id)
		return true;
	if (book1.B_Id > book2.B_Id)
		return false;
	return false;
}

bool sort_by_price(const Book & book1, const Book & book2){
	if (book1.B_Pri < book2.B_Pri)
		return true;
	if (book1.B_Pri > book2.B_Pri)
		return false;
	return false;
}

bool sort_by_pub_time(const Book & book1, const Book & book2){
	if (book1.P_Tim < book2.P_Tim)
		return true;
	if (book1.P_Tim > book2.P_Tim)
		return false;
	return false;
}

bool sort_by_sear_freq(const Book & book1, const Book & book2){
	if (book1.S_Freq < book2.S_Freq)
		return true;
	if (book1.S_Freq > book2.S_Freq)
		return false;
	return false;
}
