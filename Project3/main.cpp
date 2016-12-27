#include<iostream>
#include<cstdlib>
#include"CData_Processor.h"
#include"Data_Structure.h"
#include"CSearch_Book.h"
#include"CInitializer.h"
#include"CLogIn_Out.h"
#include"CLibrary.h"
#include"CBook.h"
#include"CSort.h"
using namespace std;

int main(void){
	CLibrary lib;
	CData_Processor D_pro;
	CSearch_Book searcher;
	CReader reader;
	CBook books;
	CLogin_Out user_log;
	CInitializer initializer;
	vector<string> title_vec;
	vector<string> auth_vec;
	vector<string> pub_vec;
	vector<string> cid_vec;
	initializer.Initialize(D_pro, searcher, lib, reader, books, title_vec, auth_vec, pub_vec, cid_vec);
	bool check=initializer.login(user_log, reader, lib);
	/*while(!check){
		system("cls");
		cout <<endl<< "�û������������" << endl;
		check = initializer.login(user_log, reader, lib);
	}*/
	if (user_log.get_User_Type() == 2){
		cout << "==========================��ӭʹ��ͼ�����Ϣ����ϵͳ��==========================" << endl;
		cout << "                                                      ���," << user_log.return_Current_User().get_Reader_Name()<< endl;
		cout << "                              1.��ѯͼ��" << endl;
		cout << "                              2.����ͼ��" << endl;
		cout << "                              3.�黹ͼ��" << endl;
		cout << "                              4.������Ϣ��ѯ" << endl;
		cout << "                              5.����ͼ��" << endl;
		cout << "                              0.�˳���¼" << endl;
		cout << "������ѡ��" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice){
		case 1:{
			int sear_Method = 0;
			cout << "����������Ҫ�Ĳ�ѯ��ʽ" << endl;
			cout << "================================��ѯ��ʽ====================================" << endl;
			cout << "                              1.ʹ����Ŀ��Ų�ѯ" << endl;
			cout << "                              2.ʹ�ñ����ѯ" << endl;
			cout << "                              3.ʹ�����߲�ѯ" << endl;
			cout << "                              4.ʹ�ó������ѯ" << endl;
			cout << "                              5.ʹ�÷���Ų�ѯ" << endl;
			cout << "                              6.ʹ�ó���ʱ�䷶Χ���в�ѯ" << endl;
			cout << "                              7.ʹ�ü۸�Χ���в�ѯ" << endl;
			cout << "������ѡ��" << endl;
			cin >> sear_Method;
			switch (sear_Method){
			case 1:{
				cout << "��ѡ����ǰ���Ŀ��Ų�ѯ" << endl;
				Book_ID bid = 0;
				cout << "���������������Ŀ���" << endl;
				cin >> bid;
				searcher.Search_By_Book_Id(lib, bid);
				searcher.Show_Search_Result();
				break;
			}
			case 2:{
				cout << "��ѡ����ǰ������ѯ" << endl;
				cout << "�������������ͼ�����" << endl;
				Book_Title b_title;
				cin >> b_title;
				searcher.Search_By_Title(lib, b_title);
				searcher.Show_Search_Result();
				break;
			}
			case 3:{
				cout << "��ѡ����ǰ����߲�ѯ" << endl;
				cout << "�����������������" << endl;
				Auth_Name auth_name;
				cin >> auth_name;
				searcher.Search_By_Auth_Name(lib, auth_name);
				searcher.Show_Search_Result();
				break;
			}
			case 4:{
				cout << "��ѡ����ǰ��������ѯ" << endl;
				cout << "������������ĳ�����" << endl;
				Pub_Dep pub_name;
				cin >> pub_name;
				searcher.Search_By_Pub_Dep(lib, pub_name);
				searcher.Show_Search_Result();
				break;
			}
			case 5:{
				cout << "��ѡ����ǰ�����Ų�ѯ" << endl;
				cout << "�������������ͼ��ķ����" << endl;
				Classify_ID cid;
				cin >> cid;
				searcher.Search_By_CId(lib, cid);
				searcher.Show_Search_Result();
				break;
			}
			case 6:{
				Pub_Tim time_l;
				Pub_Tim time_h;
				cout << "��ѡ�����ʹ�ó���ʱ�䷶Χ���в�ѯ" << endl;
				cout << "��������ָ�����������ʱ��" << endl;
				cin >> time_l;
				cout << "��������ָ�����������ʱ��" << endl;
				cin >> time_h;
				searcher.Search_By_Pub_Time(lib, time_l, time_h);
				searcher.Show_Search_Result();
				break;
			}
			case 7:{
				Book_Price price_l;
				Book_Price price_h;
				cout << "��ѡ�����ʹ�ü۸�Χ���в�ѯ" << endl;
				cout << "��������ָ������ͼ۸�" << endl;
				cin >> price_l;
				cout << "��������ָ������߼۸�" << endl;
				cin >> price_h;
				searcher.Search_By_book_Price(lib, price_l, price_h);
				searcher.Show_Search_Result();
				break;
			}
			default:{
				cout << "������������" << endl;
			}
			}
			break;
		}
		case 2:{
			cout << "����������Ҫ�Ľ��ķ�ʽ" << endl;
			cout << "================================���ķ�ʽ====================================" << endl;
			cout << "                              1.ʹ����Ŀ��Ž���" << endl;
			cout << "                              2.ʹ�ñ������" << endl;
			cout << "                              3.ʹ�����߽���" << endl;
			cout << "                              4.ʹ�ó��������" << endl;
			cout << "                              5.ʹ�÷���Ž���" << endl;
			cout << "������ѡ��" << endl;
			int borrow_method = 0;
			cin >> borrow_method;
			switch (borrow_method){
			case 1:{
				cout << "��ѡ����ǰ���Ŀ��Ž���" << endl;
				cout << "����������Ҫ���ĵ���Ŀ���" << endl;
				Book_ID bid;
				cin >> bid;
				reader.borrow_Book_By_bID(lib, searcher, bid);
				break;
			}
			case 2:{
				cout << "��ѡ����ǰ��������" << endl;
				cout << "����������Ҫ���ĵ��鼮�ı���" << endl;
				Book_Title title;
				cin >> title;
				reader.borrow_Book_By_Title(lib, searcher, title);
				break;
			}
			case 3:{
				cout << "��ѡ����ǰ����߽���" << endl;
				cout << "����������Ҫ���ĵ��鼮������" << endl;
				Auth_Name a_name;
				cin >> a_name;
				reader.borrow_Book_By_Auth(lib, searcher, a_name);
				break;
			}
			case 4:{
				cout << "��ѡ����ǰ����������" << endl;
				cout << "����������Ҫ���ĵ��鼮�ĳ�����" << endl;
				Pub_Dep p_dep;
				cin >> p_dep;
				reader.borrow_Book_By_pub_Dep(lib, searcher, p_dep);
				break;
			}
			case 5:{
				cout << "��ѡ����ǰ�����Ž���" << endl;
				cout << "����������Ҫ���ĵ��鼮�ķ����" << endl;
				Classify_ID cid;
				cin >> cid;
				reader.borrow_Book_By_cID(lib, searcher, cid);
				break;
			}
			default:{
				cout << "������������" << endl;
			}
			}
			break;
		}
		case 3:{
			cout << "����������Ҫ�黹ͼ�����Ŀ���" << endl;
			Book_ID bid;
			cin >> bid;
			reader.give_Back_Book(searcher, bid);
			break;
		}
		case 4:{
			cout << "��ѡ������Ҫ��ѡ��" << endl;
			cout << reader.get_Reader_Name() << ",���" << endl;
			cout << "================================������Ϣ��ѯ====================================" << endl;
			cout << "                              1.��ѯ�ѽ���ͼ��" << endl;
			cout << "                              2.�޸�Ԥ������" << endl;
			cout << "                              3.�޸�Ԥ���ֻ�����" << endl;
			cout << "                              4.�޸��û���" << endl;
			cout << "                              5.�޸�����" << endl;
			cout << "������ѡ��" << endl;
			int reader_method = 0;
			cin >> reader_method;
			switch (reader_method){
			case 1:{
				reader.show_All_Borrowed_Books();
				break;
			}
			case 2:{
				reader.change_Reader_Email_Addr();
				break;
			}
			case 3:{
				reader.change_Reader_Phone_Num();
				break;
			}
			case 4:{
				reader.change_Reader_Name();
				break;
			}
			case 5:{
				reader.change_Reader_Password();
				break;
			}
			default:{
				cout << "������������" << endl;
			}
			}
			break;
		}
		case 5:{
			cout << "��������Ҫ�������Ŀ���" << endl;
			Book_ID bid;
			cin >> bid;
			reader.renew_Book(bid, lib, searcher);
			break;
		}
		case 0:{
			user_log.~CLogin_Out();
			if (user_log.check_Admin_Login_State() == false || user_log.check_Reader_Login_State() == false)
				cout << "ע���ɹ�����л����ʹ��" << endl;
			else
				cout << "ע��ʧ��" << endl;
			break;
		}
		}
	}
	return 0;
}