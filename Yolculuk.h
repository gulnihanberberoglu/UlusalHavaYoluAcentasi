#pragma once
#include "stdafx.h"
#include "Sefer.h"
#include "Yolcular.h"
#include "MySqlDatabase.h"

/// <summary>
/// Direkt/1Aktarmal�/2Aktarmal� biletleri modelleyen s�n�f
/// </summary>
class Bilet {
public:	
	/// <summary>
	/// Yolculu�un ba�lang�� �ehiri
	/// </summary>
	int BAS_NOKTA;

	/// <summary>
	/// Yolculu�un biti� �ehiri
	/// </summary>
	int BIT_NOKTA;
	
	/// <summary>
	/// Ilk ucusun yap�laca�� u�a��n kanat numaras�
	/// </summary>
	string BIRINCI_UCUS;
	
	/// <summary>
	/// Ikinci ucusun yap�laca�� u�a��n kanat numaras�
	/// </summary>
	string IKINCI_UCUS;
	
	/// <summary>
	/// Ucuncu ucusun yap�laca�� u�a��n kanat numaras�
	/// </summary>
	string UCUNCU_UCUS;
	
	/// <summary>
	/// Direkt / 1Aktarmal� / 2Aktarmal�
	/// </summary>
	string TUR;
	
	/// <summary>
	/// Min bos koltuk sayisi
	/// </summary>
	int BOS_ADET;
};

/// <summary>
/// Yolculuk tablosunu modelleyen s�n�ft�r.
/// </summary>
/// <seealso cref="MySqlDatabase" />
class Yolculuk : public MySqlDatabase
{
public:	
	/// <summary>
	/// Yolculuga ��k�cak yolcunun tckn numras�
	/// </summary>
	string TCKN;
	
	/// <summary>
	/// Yolculu�a ��k�lacak u�a��n kanat numaras�
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
	/// Yolculu�un ba�lang�� noktas�
	/// </summary>
	int BAS_NOKTA;

	/// <summary>
	/// Yolculu�un biti� noktas�
	/// </summary>
	int BIT_NOKTA;

	/// <summary>
	/// <see cref="Sefer"/> t�r�n�n constructor methodu.
	/// </summary>
	Yolculuk();
	
	/// <summary>
	/// Yolcuya ait biletleri d�nen method.
	/// </summary>
	/// <param name="yolcu">Yolcu</param>
	/// <returns>Bilet listesi</returns>
	vector<Yolculuk*> YolculukSorgula(Yolcular* yolcu);
	
	/// <summary>
	/// Girilen aral�kta muhtemel biletleri hesaplayan method.
	/// </summary>
	/// <param name="basNokta">Ba�lang�� noktas�</param>
	/// <param name="bitNokta">Biti� noktas�</param>
	/// <param name="tarih">Yolculuk tarihi</param>
	/// <param name="adet">Yolcu adeti</param>
	/// <returns>Bilet listesi</returns>
	vector<Bilet*> BiletBul(int basNokta, int bitNokta, string tarih, int adet);
	
	/// <summary>
	/// Yolculu�a ait billet al�nmas�ndan sorumlu method.
	/// </summary>
	/// <param name="yolcu">Yolcu</param>
	/// <param name="sefer">Sefer</param>
	/// <returns>��lem sonucu</returns>
	bool BiletSat(Yolcular* yolcu, Sefer* sefer);
	
	/// <summary>
	/// Yolculu�a kar��l�k gelen bileti iptal eden method.
	/// </summary>
	/// <returns></returns>
	bool BiletIptal();

	/// <summary>
	/// <see cref="Sefer"/> t�r�n�n deconstructor methodu.
	/// </summary>
	virtual ~Yolculuk();
};

