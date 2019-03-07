#pragma once
#include "stdafx.h"
#include "MySqlDatabase.h"

/// <summary>
/// Ucak tablosunu modelleyen s�n�ft�r.
/// </summary>
/// <seealso cref="MySqlDatabase" />
class Ucak : public MySqlDatabase
{
public:
	/// <summary>
	/// U�ak kuyruk numaras�
	/// </summary>
	string UKN;

	/// <summary>
	/// U�ak modeli
	/// </summary>
	string MODEL;

	/// <summary>
	/// U�ak yolcu kapasitesi
	/// </summary>
	string KAPASITE;

	/// <summary>
	/// <see cref="Sefer"/> t�r�n�n constructor methodu.
	/// </summary>
	Ucak();
	
	/// <summary>
	/// Sistemde tan�ml� olan u�ak listesi.
	/// </summary>
	/// <returns>U�ak listesi</returns>
	vector<Ucak*> Getir();
	
	/// <summary>
	/// Belirtilen u�ak kanat numaras�na g�re bilgilerini getirir.
	/// </summary>
	/// <param name="ukn">u�ak kanat numaras�</param>
	/// <returns>U�ak bilgisi</returns>
	Ucak* Getir(string ukn);

	/// <summary>
	/// U�a�� sisteme kay�t eden method.
	/// </summary>
	/// <returns>Sonu�</returns>
	bool Kaydet();

	/// <summary>
	/// U�a�� sistemden silen method.
	/// </summary>
	/// <returns>Sonu�</returns>
	bool Sil();

	/// <summary>
	/// U�ak bilgilerini g�ncelliyen method.
	/// </summary>
	/// <returns>Sonu�</returns>
	bool G�ncelle();

	/// <summary>
	/// <see cref="Sefer"/> t�r�n�n deconstructor methodu.
	/// </summary>
	virtual ~Ucak();
};

