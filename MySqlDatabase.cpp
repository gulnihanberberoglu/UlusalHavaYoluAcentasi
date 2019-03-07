#include "stdafx.h"
#include "MySqlDatabase.h"

/// <summary>
/// <see cref="MySqlDatabase"/> türünün constructor fonksiyonu.
/// </summary>
MySqlDatabase::MySqlDatabase()
{
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://localhost:3306", "root", "123456");
	con->setSchema("havayolu");
}

/// <summary>
/// INSERT/UPDATE/DELETE gibi tablo verisini etkileyen 
/// sorgularý çalýþtýrmaktan sorumlu fonksiyondur
/// </summary>
/// <param name="sql">sql sorgusu</param>
/// <returns></returns>
bool MySqlDatabase::Execute(string sql)
{
	try
	{
		sql::Statement *stmt = con->createStatement();
		return stmt->execute(sql);
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
	return false;
}

/// <summary>
/// SELECT cümlesi ile tablodan veriyi getirmek için
/// kullanýlan fonksiyondur
/// </summary>
/// <param name="sql">sql sorgusu</param>
/// <returns>Satýr</returns>
sql::ResultSet* MySqlDatabase::ExecuteQuery(string sql)
{
	sql::ResultSet* result;
	try
	{
		sql::Statement *stmt = con->createStatement();
		result = stmt->executeQuery(sql);
	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
	return result;
}

/// <summary>
/// <see cref="MySqlDatabase"/> türünün deconstructor fonksiyonu.
/// </summary>
MySqlDatabase::~MySqlDatabase()
{
	delete con;
}
