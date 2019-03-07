#include "stdafx.h"
#include "Yolculuk.h"

/// <summary>
/// <see cref="Sefer"/> türünün constructor methodu.
/// </summary>
Yolculuk::Yolculuk()
{
}

/// <summary>
/// Yolcuya ait biletleri dönen method.
/// </summary>
/// <param name="yolcu">Yolcu</param>
/// <returns>Bilet listesi</returns>
vector<Yolculuk*> Yolculuk::YolculukSorgula(Yolcular* yolcu)
{
	vector<Yolculuk*> result;
	sql::ResultSet* resultSet = this->ExecuteQuery("SELECT b.TCKN, b.UKN, b.TARIH, s.SAAT, s.BAS_NOKTA, s.BIT_NOKTA FROM havayolu.Yolculuk b, havayolu.Sefer s WHERE b.UKN = s.UKN AND b.TARIH = s.TARIH AND b.TCKN = '" + yolcu->TCKN + "'");

	while (resultSet->next()) {
		Yolculuk* yolcu = new Yolculuk();
		yolcu->TCKN = resultSet->getString("TCKN");
		yolcu->UKN = resultSet->getString("UKN");
		yolcu->TARIH = resultSet->getString("TARIH");
		yolcu->SAAT = resultSet->getString("SAAT");
		yolcu->BAS_NOKTA = resultSet->getInt("BAS_NOKTA");
		yolcu->BIT_NOKTA = resultSet->getInt("BIT_NOKTA");
		result.push_back(yolcu);
	}
	return result;
}

/// <summary>
/// Girilen aralýkta muhtemel biletleri hesaplayan method.
/// </summary>
/// <param name="basNokta">Baþlangýç noktasý</param>
/// <param name="bitNokta">Bitiþ noktasý</param>
/// <param name="tarih">Yolculuk tarihi</param>
/// <param name="adet">Yolcu adeti</param>
/// <returns>Bilet listesi</returns>
vector<Bilet*> Yolculuk::BiletBul(int basNokta, int bitNokta, string tarih, int adet) {
	string sorgu =
		" SELECT * FROM"
		" ("
		" SELECT s1.BAS_NOKTA, s1.BIT_NOKTA, 'Direkt' as TUR, s1.BOS, s1.UKN as BIRINCI_UCUS, '' as IKINCI_UCUS, '' as UCUNCU_UCUS"
		" FROM havayolu.sefer_bilet s1"
		" WHERE s1.TARIH = '" + tarih + "'"
		" UNION"
		" SELECT s1.BAS_NOKTA, s2.BIT_NOKTA, '1 Aktarmali' as TUR, LEAST(s1.BOS, s2.BOS), s1.UKN as BIRINCI_UCUS, s2.UKN as IKINCI_UCUS, '' as UCUNCU_UCUS"
		" FROM havayolu.sefer_bilet s1, havayolu.sefer_bilet s2"
		" WHERE s1.BIT_NOKTA = s2.BAS_NOKTA"
		" AND s1.TARIH = s2.TARIH"
		" AND s1.TARIH = '" + tarih + "'"
		" UNION"
		" SELECT s1.BAS_NOKTA, s3.BIT_NOKTA, '2 Aktarmali' as TUR, LEAST(s1.BOS, s2.BOS, s3.BOS), s1.UKN as BIRINCI_UCUS, s2.UKN as IKINCI_UCUS, s3.UKN as UCUNCU_UCUS"
		" FROM havayolu.sefer_bilet s1, havayolu.sefer_bilet s2, havayolu.sefer_bilet s3"
		" WHERE s1.BIT_NOKTA = s2.BAS_NOKTA"
		" AND s2.BIT_NOKTA = s3.BAS_NOKTA"
		" AND s1.TARIH = s2.TARIH"
		" AND s2.TARIH = s3.TARIH"
		" AND s1.TARIH = '" + tarih + "'"
		" ) t WHERE BAS_NOKTA = " + to_string(basNokta) + " AND BIT_NOKTA = " + to_string(bitNokta) + " AND BOS >= " + to_string(adet);

	vector<Bilet*> result;
	sql::ResultSet* resultSet = this->ExecuteQuery(sorgu);
	while (resultSet->next()) {
		Bilet* yolcu = new Bilet();
		yolcu->BAS_NOKTA = resultSet->getInt("BAS_NOKTA");
		yolcu->BIT_NOKTA = resultSet->getInt("BIT_NOKTA");
		yolcu->TUR = resultSet->getString("TUR");
		yolcu->BOS_ADET = resultSet->getInt("BOS");
		yolcu->BIRINCI_UCUS = resultSet->getString("BIRINCI_UCUS");
		yolcu->IKINCI_UCUS = resultSet->getString("IKINCI_UCUS");
		yolcu->UCUNCU_UCUS = resultSet->getString("UCUNCU_UCUS");
		result.push_back(yolcu);
	}

	return result;
}

/// <summary>
/// Yolculuða ait billet alýnmasýndan sorumlu method.
/// </summary>
/// <param name="yolcu">Yolcu</param>
/// <param name="sefer">Sefer</param>
/// <returns>Ýþlem sonucu</returns>
bool Yolculuk::BiletSat(Yolcular* yolcu, Sefer* sefer)
{
	bool result = this->Execute("INSERT INTO havayolu.Yolculuk (TCKN, UKN, TARIH) VALUE ('"
		+ yolcu->TCKN + "', "
		+ "'" + sefer->UKN + "', "
		+ "'" + sefer->TARIH + "')");
	return result;
}

/// <summary>
/// Yolculuða karþýlýk gelen bileti iptal eden method.
/// </summary>
/// <returns></returns>
bool Yolculuk::BiletIptal()
{
	return
		this->Execute("DELETE FROM havayolu.Yolculuk WHERE UKN = '" + this->UKN + "' AND TARIH = '" + this->TARIH + "' AND TCKN = '" + this->TCKN + "'");
}

/// <summary>
/// <see cref="Sefer"/> türünün deconstructor methodu.
/// </summary>
Yolculuk::~Yolculuk()
{
}
