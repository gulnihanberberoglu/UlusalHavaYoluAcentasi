#pragma once
#include "stdafx.h"
#include "Yolcular.h"
#include "MySqlDatabase.h"

/// <summary>
/// Sefer tablosunun modelliyen sýnýftýr
/// </summary>
/// <seealso cref="MySqlDatabase" />
class Sefer : public MySqlDatabase
{
public:	
	/// <summary>
	/// Uçak kuyruk numarasý
	/// </summary>
	string UKN;	

	/// <summary>
	/// Uçaðýn sefere çýkacaðý tarih
	/// </summary>
	string TARIH;

	/// <summary>
	/// Uçaðýn sefere çýkacaðý saat
	/// </summary>
	string SAAT;
	
	/// <summary>
	/// Seferin baþlayacaðý ilin kodu
	/// </summary>
	int BAS_NOKTA;
	
	/// <summary>
	/// Seferin tamamlanacaðý ilin kodu
	/// </summary>
	int BIT_NOKTA;
	
	/// <summary>
	/// Sefere çýkýcak uçaðýn doluluk oraný
	/// </summary>
	int DOLULUKORANI;
	
	/// <summary>
	/// <see cref="Sefer"/> türünün constructor methodu.
	/// </summary>
	Sefer();
	
	/// <summary>
	/// Sistemde kayýtlý sefer bilgilerini getiren method.
	/// </summary>
	/// <returns>Sefer listesi</returns>
	vector<Sefer*> Getir();
	
	/// <summary>
	/// Seçilen seferdeki yolcu listesini getiren method.
	/// </summary>
	/// <returns>Yolcu listesi</returns>
	vector<Yolcular*> GetirYolcuListesi();
	
	/// <summary>
	/// Seferi sisteme kayýt eden method.
	/// </summary>
	/// <returns>Sonuç</returns>
	bool Kaydet();
	
	/// <summary>
	/// Seferi sistemden silen method.
	/// </summary>
	/// <returns>Sonuç</returns>
	bool Sil();
	
	/// <summary>
	/// <see cref="Sefer"/> türünün deconstructor methodu.
	/// </summary>
	virtual ~Sefer();
};

