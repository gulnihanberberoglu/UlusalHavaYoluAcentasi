#include "stdafx.h"
#include "Sefer.h"

/// <summary>
/// <see cref="Sefer"/> türünün constructor methodu.
/// </summary>
Sefer::Sefer()
{
}

/// <summary>
/// Sistemde kayýtlý sefer bilgilerini getiren method.
/// </summary>
/// <returns>Sefer listesi</returns>
vector<Sefer*> Sefer::Getir()
{
	vector<Sefer*> result;
	sql::ResultSet* resultSet = this->ExecuteQuery("SELECT s.UKN, s.TARIH, s.SAAT, s.BAS_NOKTA, s.BIT_NOKTA, 100 * count(b.TCKN) / u.KAPASITE as DOLULUK FROM havayolu.Sefer s INNER JOIN havayolu.Ucak u ON s.UKN = u.UKN LEFT JOIN havayolu.yolculuk b on s.UKN = b.UKN AND s.TARIH = b.TARIH group by s.UKN, s.TARIH, s.SAAT, s.BAS_NOKTA, s.BIT_NOKTA, u.KAPASITE");

	while (resultSet->next()) {
		Sefer* sefer = new Sefer();
		sefer->UKN = resultSet->getString("UKN");
		sefer->TARIH = resultSet->getString("TARIH");
		sefer->SAAT = resultSet->getString("SAAT");
		sefer->BAS_NOKTA = resultSet->getInt("BAS_NOKTA");
		sefer->BIT_NOKTA = resultSet->getInt("BIT_NOKTA");
		sefer->DOLULUKORANI = resultSet->getInt("DOLULUK");
		result.push_back(sefer);
	}
	return result;
}

/// <summary>
/// Seçilen seferdeki yolcu listesini getiren method.
/// </summary>
/// <returns>Yolcu listesi</returns>
vector<Yolcular*> Sefer::GetirYolcuListesi()
{
	string query =
		"SELECT  y.*"
		"  FROM havayolu.yolculuk b, havayolu.yolcular y"
		" WHERE y.TCKN = b.TCKN"
		"   AND b.UKN = '" + this->UKN + "' AND b.TARIH = '" + this->TARIH + "'";
	vector<Yolcular*> result;
	sql::ResultSet* resultSet = this->ExecuteQuery(query);

	while (resultSet->next()) {
		Yolcular* yolcu = new Yolcular();
		yolcu->TCKN = resultSet->getString("TCKN");
		yolcu->ISIM = resultSet->getString("ISIM");
		yolcu->EPOSTA = resultSet->getString("EPOSTA");
		yolcu->PLAKAKOD = resultSet->getInt("PLAKAKOD");
		yolcu->ADRES = resultSet->getString("ADRES");
		result.push_back(yolcu);
	}
	return result;
}

/// <summary>
/// Seferi sisteme kayýt eden method.
/// </summary>
/// <returns>Sonuç</returns>
bool Sefer::Kaydet()
{
	bool result = this->Execute("INSERT INTO havayolu.Sefer (UKN, TARIH, SAAT, BAS_NOKTA, BIT_NOKTA) VALUE ('"
		+ this->UKN + "', "
		+ "'" + this->TARIH + "', "
		+ "'" + this->SAAT + "', "
		+ to_string(this->BAS_NOKTA) + ", "
		+ to_string(this->BIT_NOKTA) + ")");
	return result;
	return false;
}

/// <summary>
/// Seferi sistemden silen method.
/// </summary>
/// <returns>Sonuç</returns>
bool Sefer::Sil()
{
	this->Execute("DELETE FROM havayolu.Yolculuk WHERE UKN = '" + this->UKN + "' AND TARIH = '" + this->TARIH + "'");
	this->Execute("DELETE FROM havayolu.Sefer WHERE UKN = '" + this->UKN + "' AND TARIH = '" + this->TARIH + "'");
	return true;
}

/// <summary>
/// <see cref="Sefer"/> türünün deconstructor methodu.
/// </summary>
Sefer::~Sefer()
{
}