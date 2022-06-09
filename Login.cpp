#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <exception>
#include <wchar.h>

enum class LoginOpCode 
{
	OK = 0,
	Exception = -1,
	WrongPwd = -2,
	WrongUser = -3,
	None
};

struct LoginOpResult 
{
	LoginOpCode Code;
	char* Error;
};

LoginOpResult Authenticate(wchar_t* username, wchar_t* password)
{
	LoginOpResult result;
	result.Code = LoginOpCode::None;

	try
	{
		sql::Driver* driver;
		sql::Connection* dbConnection;
		sql::PreparedStatement* sqlStatement;
		sql::ResultSet* sqlResult;

		driver = get_driver_instance();
		dbConnection = driver->connect("localhost:3308", "root", "12345678");
		dbConnection->setSchema("aplikacijabaza");

		sqlStatement = dbConnection->prepareStatement("select lozinka from korisnici where korisnickoIme = ?");
		sqlStatement->setString(1, username);

		sqlResult = sqlStatement->executeQuery();

		while (sqlResult->next()) 
		{
			wchar_t* lozinka = res->getString("lozinka").c_str();

			if (std::wcscmp(password, lozinka) == 0) 
			{
				result.Code = LoginOpCode::OK;
			}
			else
			{
				result.Code = LoginOpCode::WrongPwd;
			}

			return result;
		}

		result.Code = LoginOpCode::WrongUser;

		delete sqlResult;
		delete sqlStatement;
		delete dbConnection;

		return result;
	}
	catch (std::exception& err)
	{
		result.Code = LoginOpCode::Exception;
		result.Error = err.what();

		return result;
	}
}