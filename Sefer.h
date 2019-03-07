#pragma once
#include "stdafx.h"
#include "Yolcular.h"
#include "MySqlDatabase.h"

/// <summary>
/// Sefer tablosunun modelliyen s�n�ft�r
/// </summary>
/// <seealso cref="MySqlDatabase" />
class Sefer : public MySqlDatabase
{
public:	
	/// <summary>
	/// U�ak kuyruk numaras�
	/// </summary>
	string UKN;	

	/// <summary>
	/// U�a��n sefere ��kaca�� tarih
	/// </summary>
	string TARIH;

	/// <summary>
	/// U�a��n sefere ��kaca�� saat
	/// </summary>
	string SAAT;
	
	/// <summary>
	/// Seferin ba�layaca�� ilin kodu
	/// </summary>
	int BAS_NOKTA;
	
	/// <summary>
	/// Seferin tamamlanaca�� ilin kodu
	/// </summary>
	int BIT_NOKTA;
	
	/// <summary>
	/// Sefere ��k�cak u�a��n doluluk oran�
	/// </summary>
	int DOLULUKORANI;
	
	/// <summary>
	/// <see cref="Sefer"/> t�r�n�n constructor methodu.
	/// </summary>
	Sefer();
	
	/// <summary>
	/// Sistemde kay�tl� sefer bilgilerini getiren method.
	/// </summary>
	/// <returns>Sefer listesi</returns>
	vector<Sefer*> Getir();
	
	/// <summary>
	/// Se�ilen seferdeki yolcu listesini getiren method.
	/// </summary>
	/// <returns>Yolcu listesi</returns>
	vector<Yolcular*> GetirYolcuListesi();
	
	/// <summary>
	/// Seferi sisteme kay�t eden method.
	/// </summary>
	/// <returns>Sonu�</returns>
	bool Kaydet();
	
	/// <summary>
	/// Seferi sistemden silen method.
	/// </summary>
	/// <returns>Sonu�</returns>
	bool Sil();
	
	/// <summary>
	/// <see cref="Sefer"/> t�r�n�n deconstructor methodu.
	/// </summary>
	virtual ~Sefer();
};

