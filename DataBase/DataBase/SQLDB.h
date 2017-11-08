/****************************************************************
* COPYRIGHT(EMP),emperor electronic technology of ShenZhen
* FILENAME : SQLDB.h
* AUTHOR : TangYingZhong
* VERSION : v1.0.0
* DATE : 2017/10/11
* DESCRIPTION : SQLDB
****************************************************************/
#ifndef		SYSTEMMODEL_DAL_SQLDB_H_
#define	SYSTEMMODEL_DAL_SQLDB_H_

#include "IDB.h"


namespace SystemModel
{
	namespace DAL
	{
		/*
		* CLASSNAME : SQLDB
		* FUNC : SQLDB 
		* AUTHOR : Tangyz
		* DATE : 2017/10/11
		*/
		class SQLDB :public IDB
		{
		public:
			//Construct the SQLDB
			SQLDB(STRING conStr);

			//Destruct the SQLDB
			~SQLDB();

		private:
			//Copy construct SQLDB
			SQLDB(SQLDB& other){		}

			//Assignment
			SQLDB& operator=(SQLDB& other){	}

		public:
			//Open the SQL DataBase
			virtual STATUS Open();

			//Search data
			virtual RECORDSET Search(STRING sqlStr);

			//Execute the SQL
			virtual NONE Execute(STRING sqlStr);

			//Close the SQL DataBase
			virtual NONE Close();

		private:
			//Init the SQLDB
			NONE InitDB(STRING conStr);

			//Destory the SQLDB
			NONE DestoryDB();

			//Create a connection
			NONE CreateConnection();

			//Destory the connection
			NONE DestoryConnection();

		private:
			//Configure the connction string
			NONE ConfigConString(STRING conStr);

		private:
			//Get db connection handle
			CONNECTION GetDBConnection() const;

			//Set db connection handle
			NONE SetDBConnection(CONNECTION con);

			//Get the connection string
			STRING GetConString() const;

			//Set the connection string
			NONE SetConString(STRING str);

			//Get the closed flag
			BOOL GetClosed() const;

			//Set the closed flag
			NONE SetClosed(BOOL closed);

		private:
			//Connection String
			STRING conString;

			//Connection handle
			CONNECTION dbCon;

			//USB closed
			BOOL closed;

		};
	}
}





#endif //SYSTEMMODEL_DAL_SQLDB_H_


