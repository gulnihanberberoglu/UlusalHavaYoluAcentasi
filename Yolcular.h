#pragma once
#include "stdafx.h"
#include "MySqlDatabase.h"

/// <summary>
/// Yolcu tablosunu modelleyen sýnýftýr.
/// </summary>
/// <seealso cref="MySqlDatabase" />
class Yolcular : public MySqlDatabase
{
public:	
	/// <summary>
	/// Yolcu TC Kimlik numarasý
	/// </summary>
	string TCKN;
	
	/// <summary>
	/// Yolcu Ismý
	/// </summary>
	string ISIM;
	
	/// <summary>
	/// Yolcu EPosta bilgisi
	/// </summary>
	string EPOSTA;
	
	/// <summary>
	/// Yolcunun yaþadýðý þehirin il kodu
	/// </summary>
	int PLAKAKOD;
	
	/// <summary>
	/// Yolcunun adresi
	/// </summary>
	string ADRES;

	/// <summary>
	/// <see cref="Sefer"/> türünün constructor methodu.
	/// </summary>
	Yolcular();

	/// <summary>
	/// Sistemde kayýtlý yolcu bilgilerini getiren method.
	/// </summary>
	/// <returns>Sefer listesi</returns>
	vector<Yolcular*> Getir();

	/// <summary>
	/// tckn bilgisinden yolcu bilgisini getiren method.
	/// </summary>
	/// <param name="tckn">tckn numarasý</param>
	/// <returns>
	/// Yolcu
	/// </returns>
	Yolcular* Getir(string tckn);

	/// <summary>
	/// Yolcuyu sisteme kayýt eden method.
	/// </summary>
	/// <returns>Sonuç</returns>
	bool Kaydet();

	/// <summary>
	/// Yolcuyu sistemden silen method.
	/// </summary>
	/// <returns>Sonuç</returns>
	bool Sil();

	/// <summary>
	/// <see cref="Sefer"/> türünün deconstructor methodu.
	/// </summary>
	virtual ~Yolcular();
};

