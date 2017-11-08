/****************************************************************
* COPYRIGHT(EMP),emperor electronic technology of ShenZhen
* FILENAME : IDB.h
* AUTHOR : TangYingZhong
* VERSION : v1.0.0
* DATE : 2017/10/11
* DESCRIPTION : DataBase interface
****************************************************************/
#ifndef		SYSTEMMODEL_DAL_IDB_H_
#define	SYSTEMMODEL_DAL_IDB_H_

#include <Windows.h>
#import "C:\\Program Files\\Common Files\\System\\ADO\\msado15.dll" no_namespace rename("EOF", "EndOfFile")


namespace SystemModel
{
	namespace DAL
	{
		/*
		* CLASSNAME : IDB
		* FUNC : Usb's interface
		* AUTHOR : Tangyz
		* DATE : 2017/10/11
		*/
		class IDB
		{
		public:
			typedef void NONE;
			typedef bool BOOL;
			typedef char* STRING;
			typedef _ConnectionPtr CONNECTION;
			typedef _RecordsetPtr RECORDSET;

		public:
			typedef enum
			{
				FAILURE=-1,
				SUCCESS=0
			}STATUS;

		public:
			virtual ~IDB(){		}

		public:
			//Open the SQL DataBase
			virtual STATUS Open() = 0;

			//Search data
			virtual RECORDSET Search(STRING sqlStr) = 0;

			//Execute the SQL
			virtual NONE Execute(STRING sqlStr) = 0;

			//Close the SQL DataBase
			virtual NONE Close() = 0;
		};
	}
}

#endif //SYSTEMMODEL_DAL_IUSB_H_


