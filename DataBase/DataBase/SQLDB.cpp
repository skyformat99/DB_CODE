#include "SQLDB.h"


using namespace SystemModel::DAL;



//Construct the SQLDB
//conString:"Provider=SQLEXPRESS;Persist Security Info=False;User ID=sa;Password=tang1028;Initial Catalog=EmpeorSysDB"
SQLDB::SQLDB(STRING conStr)
{
	//Init the SQLDB
	InitDB(conStr);
}

//Destruct the SQLDB
SQLDB::~SQLDB()
{
	//Destory the SQLDB
	DestoryDB();
}

//Init the SQLDB
SQLDB::NONE SQLDB::InitDB(STRING conStr)
{
	//Init Com
	::CoInitialize(NULL);
	//Configure the connection string
	ConfigConString(conStr);
	//Set closed flag
	SetClosed(false);
}

//Destory the SQLDB
SQLDB::NONE SQLDB::DestoryDB()
{
	if (!GetClosed())
	{
		SetClosed(true);
		//Close the DB
		this->Close();
		//UnInit the Com
		::CoUninitialize();
	}
}

//Create a connection
SQLDB::NONE SQLDB::CreateConnection()
{
	dbCon.CreateInstance(__uuidof(Connection));
	dbCon->Open(GetConString(), "", "", adConnectUnspecified);
}

//Destory the connection
SQLDB::NONE SQLDB::DestoryConnection()
{
	if (GetDBConnection())
	{
		GetDBConnection()->Close();
		SetDBConnection(NULL);
	}
}

//Configure the connction string
SQLDB::NONE SQLDB::ConfigConString(STRING conStr)
{
	//Set the connection string
	SetConString(conStr);
}









//Open the SQL DataBase 
SQLDB::STATUS SQLDB::Open()
{
	STATUS status = STATUS::FAILURE;

	try
	{
		//Create a connection
		CreateConnection();
	}
	catch (_com_error)
	{
		this->Close();
		return status;
	}

	status = STATUS::SUCCESS;
	
	return status;
}

//Execute the SQL
SQLDB::RECORDSET SQLDB::Search(STRING sqlStr)
{
	if (GetDBConnection())
	{
		try
		{
			RECORDSET dbRecordSet = GetDBConnection()->Execute(sqlStr, NULL, adCmdText);
			return dbRecordSet;
		}
		catch (_com_error)
		{
			this->Close();
			return NULL;
		}
	}
	return NULL;
}

//Execute the SQL
SQLDB::NONE SQLDB::Execute(STRING sqlStr)
{
	if (GetDBConnection())
	{
		try
		{
			GetDBConnection()->Execute(sqlStr, NULL, adCmdText);
		}
		catch (_com_error)
		{
			this->Close();
			return;
		}
	}
}

//Close the SQL DataBase
SQLDB::NONE SQLDB::Close()
{
	//Destory the connection
	DestoryConnection();
}






//Get the closed flag
SQLDB::BOOL SQLDB::GetClosed() const
{
	return this->closed;
}

//Set the closed flag
SQLDB::NONE SQLDB::SetClosed(BOOL closed)
{
	this->closed = closed;
}

//Get db connection handle
SQLDB::CONNECTION SQLDB::GetDBConnection() const
{
	return this->dbCon;
}

//Set db connection handle
SQLDB::NONE SQLDB::SetDBConnection(CONNECTION con)
{
	this->dbCon = con;
}

//Get the connection string
SQLDB::STRING SQLDB::GetConString() const
{
	return this->conString;
}

//Set the connection string
SQLDB::NONE SQLDB::SetConString(STRING str)
{
	this->conString = str;
}






