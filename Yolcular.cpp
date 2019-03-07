#include "stdafx.h"
#include "Yolcular.h"

/// <summary>
/// <see cref="Sefer"/> türünün constructor methodu.
/// </summary>
Yolcular::Yolcular()
{
}

/// <summary>
/// Sistemde kayýtlý yolcu bilgilerini getiren method.
/// </summary>
/// <returns>Sefer listesi</returns>
vector<Yolcular*> Yolcular::Getir()
{
	vector<Yolcular*> result;
	sql::ResultSet* resultSet = this->ExecuteQuery("SELECT TCKN, ISIM, EPOSTA, PLAKAKOD, ADRES FROM havayolu.Yolcular");

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
/// tckn bilgisinden yolcu bilgisini getiren method.
/// </summary>
/// <param name="tckn">tckn numarasý</param>
/// <returns>
/// Yolcu
/// </returns>
Yolcular * Yolcular::Getir(string tckn)
{
	sql::ResultSet* resultSet = this->ExecuteQuery("SELECT TCKN, ISIM, EPOSTA, PLAKAKOD, ADRES FROM havayolu.Yolcular WHERE TCKN = '" + tckn + "'");
	while (resultSet->next()) {
		Yolcular* yolcu = new Yolcular();
		yolcu->TCKN = resultSet->getString("TCKN");
		yolcu->ISIM = resultSet->getString("ISIM");
		yolcu->EPOSTA = resultSet->getString("EPOSTA");
		yolcu->PLAKAKOD = resultSet->getInt("PLAKAKOD");
		yolcu->ADRES = resultSet->getString("ADRES");
		return yolcu;
	}
	return nullptr;
}

/// <summary>
/// Yolcuyu sisteme kayýt eden method.
/// </summary>
/// <returns>Sonuç</returns>
bool Yolcular::Kaydet()
{
	bool result = this->Execute("INSERT INTO havayolu.Yolcular (TCKN, ISIM, EPOSTA, PLAKAKOD, ADRES) VALUE ('"
		+ this->TCKN + "', "
		+ "'" + this->ISIM + "', "
		+ "'" + this->EPOSTA + "', "
		+ to_string(this->PLAKAKOD) + ", "
		+ "'" + this->ADRES + "')");
	return result;
}

/// <summary>
/// Yolcuyu sistemden silen method.
/// </summary>
/// <returns>Sonuç</returns>
bool Yolcular::Sil()
{
	this->Execute("DELETE FROM havayolu.Yolculuk WHERE TCKN = '" + this->TCKN + "'");
	this->Execute("DELETE FROM havayolu.Yolcular WHERE TCKN = '" + this->TCKN + "'");
	return true;
}

/// <summary>
/// <see cref="Sefer"/> türünün deconstructor methodu.
/// </summary>
Yolcular::~Yolcular()
{
}