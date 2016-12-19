#include<iostream>
#include"Data_Structure.h"
#include"CLibrary.h"
#include"CData_Process.h"
using namespace std;

int main(void){
	/*CLibrary lib;
    lib.Set_And_Save_Info();
	lib.Show_Info_From_File();
	lib.Change_Info();*/
	Book book;
	CData_Processor processor;
	processor.Constru_The_Header();
	processor.Input_Info(book);
	system("pause");
}