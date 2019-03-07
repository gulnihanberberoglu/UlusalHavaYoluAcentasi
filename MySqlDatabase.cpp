#include "stdafx.h"
#include "MySqlDatabase.h"

/// <summary>
/// <see cref="MySqlDatabase"/> t�r�n�n constructor fonksiyonu.
/// </summary>
MySqlDatabase::MySqlDatabase()
{
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://localhost:3306", "root", "123456");
	con->setSchema("havayolu");
}

/// <summary>
/// INSERT/UPDATE/DELETE gibi tablo verisini etkileyen 
/// sorgular� �al��t�rmaktan sorumlu fonksiyondur
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
/// SELECT c�mlesi ile tablodan veriyi getirmek i�in
/// kullan�lan fonksiyondur
/// </summary>
/// <param name="sql">sql sorgusu</param>
/// <returns>Sat�r</returns>
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
/// <see cref="MySqlDatabase"/> t�r�n�n deconstructor fonksiyonu.
/// </summary>
MySqlDatabase::~MySqlDatabase()
{
	delete con;
}
