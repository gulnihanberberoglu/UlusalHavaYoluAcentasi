#pragma once
#include "stdafx.h"
#include "MySqlDatabase.h"

/// <summary>
/// Yolcu tablosunu modelleyen s�n�ft�r.
/// </summary>
/// <seealso cref="MySqlDatabase" />
class Yolcular : public MySqlDatabase
{
public:	
	/// <summary>
	/// Yolcu TC Kimlik numaras�
	/// </summary>
	string TCKN;
	
	/// <summary>
	/// Yolcu Ism�
	/// </summary>
	string ISIM;
	
	/// <summary>
	/// Yolcu EPosta bilgisi
	/// </summary>
	string EPOSTA;
	
	/// <summary>
	/// Yolcunun ya�ad��� �ehirin il kodu
	/// </summary>
	int PLAKAKOD;
	
	/// <summary>
	/// Yolcunun adresi
	/// </summary>
	string ADRES;

	/// <summary>
	/// <see cref="Sefer"/> t�r�n�n constructor methodu.
	/// </summary>
	Yolcular();

	/// <summary>
	/// Sistemde kay�tl� yolcu bilgilerini getiren method.
	/// </summary>
	/// <returns>Sefer listesi</returns>
	vector<Yolcular*> Getir();

	/// <summary>
	/// tckn bilgisinden yolcu bilgisini getiren method.
	/// </summary>
	/// <param name="tckn">tckn numaras�</param>
	/// <returns>
	/// Yolcu
	/// </returns>
	Yolcular* Getir(string tckn);

	/// <summary>
	/// Yolcuyu sisteme kay�t eden method.
	/// </summary>
	/// <returns>Sonu�</returns>
	bool Kaydet();

	/// <summary>
	/// Yolcuyu sistemden silen method.
	/// </summary>
	/// <returns>Sonu�</returns>
	bool Sil();

	/// <summary>
	/// <see cref="Sefer"/> t�r�n�n deconstructor methodu.
	/// </summary>
	virtual ~Yolcular();
};

