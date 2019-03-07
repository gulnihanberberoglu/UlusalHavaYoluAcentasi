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
/// Veritabanýna baðlanmak ve sorgu çalýþtýrmak için
//  gerekli fonksiyonlarý barýndýran sýnýftýr.
/// </summary>
class MySqlDatabase
{
private:	
	/// <summary>
	/// MySQL 'e baðlanmak için kullanýlan driver
	/// </summary>
	sql::mysql::MySQL_Driver *driver;	

	/// <summary>
	/// MySQL ile kurulan baðlantýyý tutan nesne, ayrýca
	/// sorgu çalýtýrmak için gereken statement burdan oluþturulur.
	/// </summary>
	sql::Connection *con;
protected:	
	/// <summary>
	/// <see cref="MySqlDatabase"/> türünün constructor fonksiyonu.
	/// </summary>
	MySqlDatabase();
	
	/// <summary>
	/// INSERT/UPDATE/DELETE gibi tablo verisini etkileyen 
	/// sorgularý çalýþtýrmaktan sorumlu fonksiyondur
	/// </summary>
	/// <param name="sql">sql sorgusu</param>
	/// <returns></returns>
	bool Execute(string sql);
	
	/// <summary>
	/// SELECT cümlesi ile tablodan veriyi getirmek için
	/// kullanýlan fonksiyondur
	/// </summary>
	/// <param name="sql">sql sorgusu</param>
	/// <returns>Satýr</returns>
	sql::ResultSet* ExecuteQuery(string sql);

	/// <summary>
	/// <see cref="MySqlDatabase"/> türünün deconstructor fonksiyonu.
	/// </summary>
	~MySqlDatabase();
};

