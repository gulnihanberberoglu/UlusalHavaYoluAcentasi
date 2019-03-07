#include "stdafx.h"
#include "Ucak.h"

/// <summary>
/// <see cref="Sefer"/> t�r�n�n constructor methodu.
/// </summary>
Ucak::Ucak()
{
}

/// <summary>
/// Sistemde tan�ml� olan u�ak listesi.
/// </summary>
/// <returns>U�ak listesi</returns>
vector<Ucak*> Ucak::Getir()
{
	vector<Ucak*> result;
	sql::ResultSet* resultSet = this->ExecuteQuery("SELECT UKN, MODEL, KAPASITE FROM havayolu.ucak");
	
	while (resultSet->next()) {
		Ucak* ucak = new Ucak();
		ucak->UKN = resultSet->getString("UKN");
		ucak->MODEL = resultSet->getString("MODEL");
		ucak->KAPASITE = resultSet->getString("KAPASITE");
		result.push_back(ucak);
	}
	return result;
}

/// <summary>
/// Belirtilen u�ak kanat numaras�na g�re bilgilerini getirir.
/// </summary>
/// <param name="ukn">u�ak kanat numaras�</param>
/// <returns>U�ak bilgisi</returns>
Ucak * Ucak::Getir(string ukn)
{
	sql::ResultSet* resultSet = this->ExecuteQuery("SELECT * FROM havayolu.ucak WHERE UKN = " + ukn);
	while (resultSet->next()) {
		Ucak* ucak = new Ucak();
		ucak->UKN = resultSet->getString("UKN");
		ucak->MODEL = resultSet->getString("MODEL");
		ucak->KAPASITE = resultSet->getString("KAPASITE");
		return ucak;
	}
	return nullptr;
}

/// <summary>
/// U�a�� sisteme kay�t eden method.
/// </summary>
/// <returns>Sonu�</returns>
bool Ucak::Kaydet()
{
	bool result = this->Execute("INSERT INTO havayolu.ucak (UKN, MODEL, KAPASITE) VALUE ('"
		+ this->UKN + "', "
		+ "'" + this->MODEL + "', "
		+ this->KAPASITE + ")");
	return result;
}

/// <summary>
/// U�a�� sistemden silen method.
/// </summary>
/// <returns>Sonu�</returns>
bool Ucak::Sil()
{
	this->Execute("DELETE FROM havayolu.Yolculuk WHERE UKN = '" + this->UKN + "'");
	this->Execute("DELETE FROM havayolu.Sefer WHERE UKN = '" + this->UKN + "'");
	this->Execute("DELETE FROM havayolu.Ucak WHERE UKN = '" + this->UKN + "'");
	return true;
}

/// <summary>
/// U�ak bilgilerini g�ncelliyen method.
/// </summary>
/// <returns>Sonu�</returns>
bool Ucak::G�ncelle()
{
	bool result = this->Execute(
		"UPDATE havayolu.ucak SET UKN = '" + this->UKN + "', " +
		"MODEL = '" + this->MODEL + "', " +
		"KAPASITE = " + this->KAPASITE + " " +
		"WHERE UKN = '" + this->UKN + "'"
	);
	return result;
}

/// <summary>
/// <see cref="Sefer"/> t�r�n�n deconstructor methodu.
/// </summary>
Ucak::~Ucak()
{
}
