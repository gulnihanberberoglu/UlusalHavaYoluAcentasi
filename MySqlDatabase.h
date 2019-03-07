#pragma once
#include "stdafx.h"

#include <mysql_connection.h>
#include <mysql_driver.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

/// <summary>
/// Veritaban�na ba�lanmak ve sorgu �al��t�rmak i�in
//  gerekli fonksiyonlar� bar�nd�ran s�n�ft�r.
/// </summary>
class MySqlDatabase
{
private:	
	/// <summary>
	/// MySQL 'e ba�lanmak i�in kullan�lan driver
	/// </summary>
	sql::mysql::MySQL_Driver *driver;	

	/// <summary>
	/// MySQL ile kurulan ba�lant�y� tutan nesne, ayr�ca
	/// sorgu �al�t�rmak i�in gereken statement burdan olu�turulur.
	/// </summary>
	sql::Connection *con;
protected:	
	/// <summary>
	/// <see cref="MySqlDatabase"/> t�r�n�n constructor fonksiyonu.
	/// </summary>
	MySqlDatabase();
	
	/// <summary>
	/// INSERT/UPDATE/DELETE gibi tablo verisini etkileyen 
	/// sorgular� �al��t�rmaktan sorumlu fonksiyondur
	/// </summary>
	/// <param name="sql">sql sorgusu</param>
	/// <returns></returns>
	bool Execute(string sql);
	
	/// <summary>
	/// SELECT c�mlesi ile tablodan veriyi getirmek i�in
	/// kullan�lan fonksiyondur
	/// </summary>
	/// <param name="sql">sql sorgusu</param>
	/// <returns>Sat�r</returns>
	sql::ResultSet* ExecuteQuery(string sql);

	/// <summary>
	/// <see cref="MySqlDatabase"/> t�r�n�n deconstructor fonksiyonu.
	/// </summary>
	~MySqlDatabase();
};

