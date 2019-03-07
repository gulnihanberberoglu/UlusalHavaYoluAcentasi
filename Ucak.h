#pragma once
#include "stdafx.h"
#include "MySqlDatabase.h"

/// <summary>
/// Ucak tablosunu modelleyen sýnýftýr.
/// </summary>
/// <seealso cref="MySqlDatabase" />
class Ucak : public MySqlDatabase
{
public:
	/// <summary>
	/// Uçak kuyruk numarasý
	/// </summary>
	string UKN;

	/// <summary>
	/// Uçak modeli
	/// </summary>
	string MODEL;

	/// <summary>
	/// Uçak yolcu kapasitesi
	/// </summary>
	string KAPASITE;

	/// <summary>
	/// <see cref="Sefer"/> türünün constructor methodu.
	/// </summary>
	Ucak();
	
	/// <summary>
	/// Sistemde tanýmlý olan uçak listesi.
	/// </summary>
	/// <returns>Uçak listesi</returns>
	vector<Ucak*> Getir();
	
	/// <summary>
	/// Belirtilen uçak kanat numarasýna göre bilgilerini getirir.
	/// </summary>
	/// <param name="ukn">uçak kanat numarasý</param>
	/// <returns>Uçak bilgisi</returns>
	Ucak* Getir(string ukn);

	/// <summary>
	/// Uçaðý sisteme kayýt eden method.
	/// </summary>
	/// <returns>Sonuç</returns>
	bool Kaydet();

	/// <summary>
	/// Uçaðý sistemden silen method.
	/// </summary>
	/// <returns>Sonuç</returns>
	bool Sil();

	/// <summary>
	/// Uçak bilgilerini güncelliyen method.
	/// </summary>
	/// <returns>Sonuç</returns>
	bool Güncelle();

	/// <summary>
	/// <see cref="Sefer"/> türünün deconstructor methodu.
	/// </summary>
	virtual ~Ucak();
};

