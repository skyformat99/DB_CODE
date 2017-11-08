#include <iostream>
#include "SQLDB.h"


using namespace std;
using namespace SystemModel::DAL;

int main()
{
	//Create a SQLDB handle 
	IDB* db = new SQLDB("Provider=SQLOLEDB.1;Persist Security Info=True;User ID=sa;Password=emp1997;Initial Catalog=EmpeorSysDB");

	//Open the DB
	db->Open();

	//Excute seraching
	SQLDB::RECORDSET set=db->Search("select * from Patient");
	while (!set->EndOfFile)
	{
		int id = set->GetCollect("ID");
		std::string name = (_bstr_t)(set->GetCollect("Name"));
		std::string gender = (_bstr_t)(set->GetCollect("Gender"));
		int age = set->GetCollect("Age");
		std::string phone = (_bstr_t)(set->GetCollect("Phone"));

		cout << id << " | " << name.c_str() << " | " << gender.c_str() << " | " << age << " | " << phone.c_str() << endl;
		
		set->MoveNext();
	}


	//Close the DB
	db->Close();


	cout <<"\r\n"<<"Updating DB"<< endl;



	//Open the DB
	db->Open();
	//Excute seraching
	db->Execute("UPDATE Patient SET Phone=18124628381 where ID=4");
	//Close the DB
	db->Close();


	cout << "\r\n"<<"Finish update db\r\n" << endl;

	//Open the DB
	db->Open();
	//Excute seraching
	SQLDB::RECORDSET recordSet = db->Search("select * from Patient where ID=4");
	while (!recordSet->EndOfFile)
	{
		int id = recordSet->GetCollect("ID");
		std::string name = (_bstr_t)(recordSet->GetCollect("Name"));
		std::string gender = (_bstr_t)(recordSet->GetCollect("Gender"));
		int age = recordSet->GetCollect("Age");
		std::string phone = (_bstr_t)(recordSet->GetCollect("Phone"));

		cout << id << " | " << name.c_str() << " | " << gender.c_str() << " | " << age << " | " << phone.c_str() << endl;

		recordSet->MoveNext();
	}


	//Close the DB
	db->Close();

	//Delete the SQLDB handle
	delete db;

	cout << "\r\n" << endl;


	return 0;
}








