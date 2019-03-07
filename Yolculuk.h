#pragma once
#include "stdafx.h"
#include "Sefer.h"
#include "Yolcular.h"
#include "MySqlDatabase.h"

/// <summary>
/// Direkt/1Aktarmalý/2Aktarmalý biletleri modelleyen sýnýf
/// </summary>
class Bilet {
public:	
	/// <summary>
	/// Yolculuðun baþlangýç þehiri
	/// </summary>
	int BAS_NOKTA;

	/// <summary>
	/// Yolculuðun bitiþ þehiri
	/// </summary>
	int BIT_NOKTA;
	
	/// <summary>
	/// Ilk ucusun yapýlacaðý uçaðýn kanat numarasý
	/// </summary>
	string BIRINCI_UCUS;
	
	/// <summary>
	/// Ikinci ucusun yapýlacaðý uçaðýn kanat numarasý
	/// </summary>
	string IKINCI_UCUS;
	
	/// <summary>
	/// Ucuncu ucusun yapýlacaðý uçaðýn kanat numarasý
	/// </summary>
	string UCUNCU_UCUS;
	
	/// <summary>
	/// Direkt / 1Aktarmalý / 2Aktarmalý
	/// </summary>
	string TUR;
	
	/// <summary>
	/// Min bos koltuk sayisi
	/// </summary>
	int BOS_ADET;
};

/// <summary>
/// Yolculuk tablosunu modelleyen sýnýftýr.
/// </summary>
/// <seealso cref="MySqlDatabase" />
class Yolculuk : public MySqlDatabase
{
public:	
	/// <summary>
	/// Yolculuga çýkýcak yolcunun tckn numrasý
	/// </summary>
	string TCKN;
	
	/// <summary>
	/// Yolculuða çýkýlacak uçaðýn kanat numarasý
	/// </summary>
	string UKN;
	
	/// <summary>
	/// Yolculuk tarihi
	/// </summary>
	string TARIH;
	
	/// <summary>
	/// Yolculuk saati
	/// </summary>
	string SAAT;
	
	/// <summary>
	/// Yolculuðun baþlangýç noktasý
	/// </summary>
	int BAS_NOKTA;

	/// <summary>
	/// Yolculuðun bitiþ noktasý
	/// </summary>
	int BIT_NOKTA;

	/// <summary>
	/// <see cref="Sefer"/> türünün constructor methodu.
	/// </summary>
	Yolculuk();
	
	/// <summary>
	/// Yolcuya ait biletleri dönen method.
	/// </summary>
	/// <param name="yolcu">Yolcu</param>
	/// <returns>Bilet listesi</returns>
	vector<Yolculuk*> YolculukSorgula(Yolcular* yolcu);
	
	/// <summary>
	/// Girilen aralýkta muhtemel biletleri hesaplayan method.
	/// </summary>
	/// <param name="basNokta">Baþlangýç noktasý</param>
	/// <param name="bitNokta">Bitiþ noktasý</param>
	/// <param name="tarih">Yolculuk tarihi</param>
	/// <param name="adet">Yolcu adeti</param>
	/// <returns>Bilet listesi</returns>
	vector<Bilet*> BiletBul(int basNokta, int bitNokta, string tarih, int adet);
	
	/// <summary>
	/// Yolculuða ait billet alýnmasýndan sorumlu method.
	/// </summary>
	/// <param name="yolcu">Yolcu</param>
	/// <param name="sefer">Sefer</param>
	/// <returns>Ýþlem sonucu</returns>
	bool BiletSat(Yolcular* yolcu, Sefer* sefer);
	
	/// <summary>
	/// Yolculuða karþýlýk gelen bileti iptal eden method.
	/// </summary>
	/// <returns></returns>
	bool BiletIptal();

	/// <summary>
	/// <see cref="Sefer"/> türünün deconstructor methodu.
	/// </summary>
	virtual ~Yolculuk();
};

