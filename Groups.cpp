#include <iostream>
#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <exception>
#include <wchar.h>

void CreateGroup(int currentUserId wchar_t* naziv,  wchar_t* opis)
{
	try
	{
		sql::Driver* driver;
		sql::Connection* dbConnection;
		sql::PreparedStatement* sqlStatement;
		sql::ResultSet* sqlResult;

		driver = get_driver_instance();
		dbConnection = driver->connect("localhost:3308", "root", "12345678");
		dbConnection->setSchema("aplikacijabaza");

		sqlStatement = dbConnection->prepareStatement("select uloga from korisnici where id = ?");
		sqlStatement->setInt(1, id);

		sqlResult = sqlStatement->executeQuery();

		while (sqlResult->next())
		{
			wchar_t* uloga = sqlResult->getString("uloga").c_str();

			if (wcscmp(uloga, "Teacher") != 0)
			{
				std::cout << "Access denied" << std::endl;
				return;
			}
		}

		sqlStatement = dbConnection->prepareStatement("insert into grupe(naziv, opis) values(?, ?)");
		sqlStatement->setString(1, naziv);
		sqlStatement->setString(2, opis);

		sqlResult = sqlStatement->executeQuery();

		delete sqlResult;
		delete sqlStatement;
		delete dbConnection;
	}
	catch (std::exception& err)
	{
		std::cout << "Error: " << err.what() << std::endl;
	}
}

void DeleteGroup(int currentUserId, int groupId)
{
	try
	{
		sql::Driver* driver;
		sql::Connection* dbConnection;
		sql::PreparedStatement* sqlStatement;
		sql::ResultSet* sqlResult;

		driver = get_driver_instance();
		dbConnection = driver->connect("localhost:3308", "root", "12345678");
		dbConnection->setSchema("aplikacijabaza");

		sqlStatement = dbConnection->prepareStatement("select uloga from korisnici where id = ?");
		sqlStatement->setInt(1, id);

		sqlResult = sqlStatement->executeQuery();

		while (sqlResult->next())
		{
			wchar_t* uloga = sqlResult->getString("uloga").c_str();

			if (wcscmp(uloga, "Teacher") != 0)
			{
				std::cout << "Access denied" << std::endl;
				return;
			}
		}

		sqlStatement = dbConnection->prepareStatement("delete from grupe where id = ?");
		sqlStatement->setInt(1, id);

		qlStatement->executeQuery();

		delete sqlResult;
		delete sqlStatement;
		delete dbConnection;
	}
	catch (std::exception& err)
	{
		std::cout << "Error: " << err.what() << std::endl;
	}
}