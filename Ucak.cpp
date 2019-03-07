#include "stdafx.h"
#include "Ucak.h"

/// <summary>
/// <see cref="Sefer"/> türünün constructor methodu.
/// </summary>
Ucak::Ucak()
{
}

/// <summary>
/// Sistemde tanýmlý olan uçak listesi.
/// </summary>
/// <returns>Uçak listesi</returns>
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
/// Belirtilen uçak kanat numarasýna göre bilgilerini getirir.
/// </summary>
/// <param name="ukn">uçak kanat numarasý</param>
/// <returns>Uçak bilgisi</returns>
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
/// Uçaðý sisteme kayýt eden method.
/// </summary>
/// <returns>Sonuç</returns>
bool Ucak::Kaydet()
{
	bool result = this->Execute("INSERT INTO havayolu.ucak (UKN, MODEL, KAPASITE) VALUE ('"
		+ this->UKN + "', "
		+ "'" + this->MODEL + "', "
		+ this->KAPASITE + ")");
	return result;
}

/// <summary>
/// Uçaðý sistemden silen method.
/// </summary>
/// <returns>Sonuç</returns>
bool Ucak::Sil()
{
	this->Execute("DELETE FROM havayolu.Yolculuk WHERE UKN = '" + this->UKN + "'");
	this->Execute("DELETE FROM havayolu.Sefer WHERE UKN = '" + this->UKN + "'");
	this->Execute("DELETE FROM havayolu.Ucak WHERE UKN = '" + this->UKN + "'");
	return true;
}

/// <summary>
/// Uçak bilgilerini güncelliyen method.
/// </summary>
/// <returns>Sonuç</returns>
bool Ucak::Güncelle()
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
/// <see cref="Sefer"/> türünün deconstructor methodu.
/// </summary>
Ucak::~Ucak()
{
}
