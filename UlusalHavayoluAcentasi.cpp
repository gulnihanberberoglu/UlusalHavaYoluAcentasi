// UlusalHavayoluAcentasi.cpp : Konsol uygulamasý için giriþ noktasýný tanýmlar.
//

#include "stdafx.h"
#include "Ucak.h";
#include "Sefer.h";
#include "Yolcular.h";
#include "Yolculuk.h";

void UcakIslemleri_Menu();
void UcakIslemleri_UcakListesiGoster();
void UcakIslemleri_UcakEkle();
void UcakIslemleri_UcakSil();
void UcakIslemleri_UcakGuncelle();

void SeferIslemleri_Menu();
void SeferIslemleri_SeferListesiGoster();
void SeferIslemleri_SeferYolcuListesiGoster();
void SeferIslemleri_SeferEkle();
void SeferIslemleri_SeferSil();

void YolcuIslemleri_Menu();
void YolcuIslemleri_YolculariGoster();
void YolcuIslemleri_YolcuEkle();
void YolcuIslemleri_YolcuSil();

void BiletIslemleri_Menu();
void BiletIslemleri_BiletSat();
void BiletIslemleri_BiletIptal();
void BiletIslemleri_BiletSorgula();

int main()
{
	int islem;
	do {
		system("CLS");
		cout << "Ulusal Havayolu Acentasi V1.0 Beta" << endl;
		cout << "*********************************************************************" << endl;
		cout << "Islem Listesi : " << endl;
		cout << "\t1-Ucak Ýslmeleri" << endl;
		cout << "\t2-Sefer Ýslmeleri" << endl;
		cout << "\t3-Yolcu Ýslmeleri" << endl;
		cout << "\t4-Bilet Ýslmeleri" << endl;
		cout << "\t0-Cikis" << endl;
		cout << "*********************************************************************" << endl;
		cout << "Lutfen yapmak istediginiz islemi girin : " << endl;
		cin >> islem;

		system("CLS");
		switch (islem)
		{
		case 0:
			break;
		case 1:
			UcakIslemleri_Menu();
			break;
		case 2:
			SeferIslemleri_Menu();
			break;
		case 3:
			YolcuIslemleri_Menu();
			break;
		case 4:
			BiletIslemleri_Menu();
			break;
		default:
			cout << "Hatali bir secim yaptiniz, Lutfen tekrar deneyiniz." << endl;
			system("PAUSE");
			break;
		}

	} while (islem != 0);

	cout << "Program sonu ....." << endl;
	system("PAUSE");
	return 0;
}

void UcakIslemleri_Menu()
{
	int islem;
	do {
		system("CLS");
		cout << "*********************************************************************" << endl;
		cout << "Ucak Islem Listesi : " << endl;
		cout << "\t1-Ucak listesini getir" << endl;
		cout << "\t2-Yeni ucak tanimla" << endl;
		cout << "\t3-Ucak bilgilerini sil" << endl;
		cout << "\t4-Ucak bilgilerini guncelle" << endl;
		cout << "\t0-Cikis" << endl;
		cout << "*********************************************************************" << endl;
		cout << "Lutfen yapmak istediginiz islemi girin : " << endl;
		cin >> islem;

		system("CLS");
		switch (islem)
		{
		case 0:
			break;
		case 1:
			UcakIslemleri_UcakListesiGoster();
			break;
		case 2:
			UcakIslemleri_UcakEkle();
			break;
		case 3:
			UcakIslemleri_UcakSil();
			break;
		case 4:
			UcakIslemleri_UcakGuncelle();
			break;
		default:
			cout << "Hatali bir secim yaptiniz, Lutfen tekrar deneyiniz." << endl;
			system("PAUSE");
			break;
		}
	} while (islem != 0);
}

void UcakIslemleri_UcakListesiGoster()
{
	cout << "Sistemde tanimli ucaklarin listesi : " << endl;
	Ucak* ucak = new Ucak();
	vector<Ucak*> ucaklar = ucak->Getir();
	for (Ucak* ucak : ucaklar) {
		cout << "UKN : " + ucak->UKN + "\tMODEL : " + ucak->MODEL + "\tKAPASITE : " + ucak->KAPASITE << endl;
	}
	system("PAUSE");
}

void UcakIslemleri_UcakEkle()
{
	Ucak* ucak = new Ucak();
	cout << "Yeni ucagin kanat numarasi : " << endl;
	cin >> ucak->UKN;
	cout << "Yeni ucagin modeli : " << endl;
	cin >> ucak->MODEL;
	cout << "Yeni ucagin kapasitesi : " << endl;
	cin >> ucak->KAPASITE;
	ucak->Kaydet();
	cout << "Isleminiz yapildi" << endl;
	system("PAUSE");
}

void UcakIslemleri_UcakSil()
{
	Ucak* ucak = new Ucak();
	vector<Ucak*> ucaklar = ucak->Getir();
	cout << "Sistemde tanimli ucaklarin listesi : " << endl;
	for (Ucak* ucak : ucaklar) {
		cout << "UKN : " + ucak->UKN + "\tMODEL : " + ucak->MODEL + "\tKAPASITE : " + ucak->KAPASITE << endl;
	}

	cout << "Silmek istediginiz ucagin kanat numarasi : " << endl;
	cin >> ucak->UKN;
	ucak->Sil();
	cout << "Isleminiz yapildi" << endl;
	system("PAUSE");
}

void UcakIslemleri_UcakGuncelle()
{
	Ucak* ucak = new Ucak();
	vector<Ucak*> ucaklar = ucak->Getir();
	cout << "Sistemde tanimli ucaklarin listesi : " << endl;
	for (Ucak* ucak : ucaklar) {
		cout << "UKN : " + ucak->UKN + "\tMODEL : " + ucak->MODEL + "\tKAPASITE : " + ucak->KAPASITE << endl;
	}

	cout << "Guncellemek isteginiz ucagin kanat numarasi : " << endl;
	cin >> ucak->UKN;
	cout << "Ucagin yeni modeli : " << endl;
	cin >> ucak->MODEL;
	cout << "Ucagin yeni kapasitesi : " << endl;
	cin >> ucak->KAPASITE;
	ucak->Güncelle();
	cout << "Isleminiz yapildi" << endl;
	system("PAUSE");
}

void SeferIslemleri_Menu() {
	int islem;
	do {
		system("CLS");
		cout << "*********************************************************************" << endl;
		cout << "Sefer Islem Listesi : " << endl;
		cout << "\t1-Sefer Listesini Getir" << endl;
		cout << "\t2-Sefer Yolcu Listesini Getir" << endl;
		cout << "\t3-Yeni Sefer Tanimla" << endl;
		cout << "\t4-Sefer Iptal Etme" << endl;
		cout << "\t0-Cikis" << endl;
		cout << "*********************************************************************" << endl;
		cout << "Lutfen yapmak istediginiz islemi girin : " << endl;
		cin >> islem;

		system("CLS");
		switch (islem)
		{
		case 0:
			break;
		case 1:
			SeferIslemleri_SeferListesiGoster();
			break;
		case 2:
			SeferIslemleri_SeferYolcuListesiGoster();
			break;
		case 3:
			SeferIslemleri_SeferEkle();
			break;
		case 4:
			SeferIslemleri_SeferSil();
			break;
		default:
			cout << "Hatali bir secim yaptiniz, Lutfen tekrar deneyiniz." << endl;
			system("PAUSE");
			break;
		}
	} while (islem != 0);
}

void SeferIslemleri_SeferListesiGoster()
{
	cout << "Sistemde tanimli seferlerin listesi : " << endl;
	Sefer* sefer = new Sefer();
	vector<Sefer*> seferler = sefer->Getir();
	for (Sefer* sefer : seferler) {
		cout << "UKN : " + sefer->UKN + "\tTARIH : " + sefer->TARIH + "\tSAAT : " + sefer->SAAT +
			"\tBAS_NOKTA : " + to_string(sefer->BAS_NOKTA) + "\tBIT_NOKTA : " + to_string(sefer->BIT_NOKTA) +
			"\tDOLULUK : " + to_string(sefer->DOLULUKORANI) << endl;
	}
	system("PAUSE");
}

void SeferIslemleri_SeferYolcuListesiGoster()
{
	cout << "Sistemde tanimli seferlerin listesi : " << endl;
	Sefer* sefer = new Sefer();
	vector<Sefer*> seferler = sefer->Getir();
	for (Sefer* sefer : seferler) {
		cout << "UKN : " + sefer->UKN + "\tTARIH : " + sefer->TARIH + "\tSAAT : " + sefer->SAAT +
			"\tBAS_NOKTA : " + to_string(sefer->BAS_NOKTA) + "\tBIT_NOKTA : " + to_string(sefer->BIT_NOKTA) << endl;
	}

	cout << "Seferi yapicak olan ucagin kanat numarasi : " << endl;
	cin >> sefer->UKN;
	cout << "Seferi yapicagi tarih : " << endl;
	cin >> sefer->TARIH;

	cout << sefer->UKN + "-" + sefer->TARIH + " numarali seferin yolcu listesi : " << endl;
	vector<Yolcular*> yolcular = sefer->GetirYolcuListesi();
	for (Yolcular* yolcu : yolcular) {
		cout << "TCKN : " + yolcu->TCKN + "\tISIM : " + yolcu->ISIM + "\tEPOSTA : " + yolcu->EPOSTA +
			"\tPLAKAKOD : " + to_string(yolcu->PLAKAKOD) + "\tADRES : " + yolcu->ADRES << endl;
	}
	system("PAUSE");
}

void SeferIslemleri_SeferEkle()
{
	cout << "Sistemde tanimli ucaklarin listesi : " << endl;
	Ucak* ucak = new Ucak();
	vector<Ucak*> ucaklar = ucak->Getir();
	for (Ucak* ucak : ucaklar) {
		cout << "UKN : " + ucak->UKN + "\tMODEL : " + ucak->MODEL + "\tKAPASITE : " + ucak->KAPASITE << endl;
	}

	Sefer* sefer = new Sefer();
	cout << "Sefere cikmasi planlanan ucagin kanat numarasi : " << endl;
	cin >> sefer->UKN;
	cout << "Sefer tarihi : " << endl;
	cin >> sefer->TARIH;
	cout << "Sefer saati : " << endl;
	cin >> sefer->SAAT;
	cout << "Sefer baslangic noktasi : " << endl;
	cin >> sefer->BAS_NOKTA;
	cout << "Sefer bitis noktasi : " << endl;
	cin >> sefer->BIT_NOKTA;
	sefer->Kaydet();
	cout << "Isleminiz yapildi" << endl;
	system("PAUSE");
}

void SeferIslemleri_SeferSil()
{
	cout << "Sistemde tanimli seferlerin listesi : " << endl;
	Sefer* sefer = new Sefer();
	vector<Sefer*> seferler = sefer->Getir();
	for (Sefer* sefer : seferler) {
		cout << "UKN : " + sefer->UKN + "\tTARIH : " + sefer->TARIH + "\tSAAT : " + sefer->SAAT +
			"\tBAS_NOKTA : " + to_string(sefer->BAS_NOKTA) + "\tBIT_NOKTA : " + to_string(sefer->BIT_NOKTA) << endl;
	}

	cout << "Seferi iptal edilecek olan ucagin kanat numarasi : " << endl;
	cin >> sefer->UKN;
	cout << "Iptal edilecek sefer tarih : " << endl;
	cin >> sefer->TARIH;

	sefer->Sil();
	cout << "Isleminiz yapildi" << endl;
	system("PAUSE");
}

void YolcuIslemleri_Menu() {
	int islem;
	do {
		system("CLS");
		cout << "*********************************************************************" << endl;
		cout << "Yolcu Islem Listesi : " << endl;
		cout << "\t1-Tanimli yolcu listesi" << endl;
		cout << "\t2-Yeni yolcu tanimla" << endl;
		cout << "\t3-Yolcu silme" << endl;
		cout << "\t0-Cikis" << endl;
		cout << "*********************************************************************" << endl;
		cout << "Lutfen yapmak istediginiz islemi girin : " << endl;
		cin >> islem;

		system("CLS");
		switch (islem)
		{
		case 0:
			break;
		case 1:
			YolcuIslemleri_YolculariGoster();
			break;
		case 2:
			YolcuIslemleri_YolcuEkle();
			break;
		case 3:
			YolcuIslemleri_YolcuSil();
			break;
		default:
			cout << "Hatali bir secim yaptiniz, Lutfen tekrar deneyiniz." << endl;
			system("PAUSE");
			break;
		}
	} while (islem != 0);
}

void YolcuIslemleri_YolculariGoster()
{
	cout << "Sistemde tanimli yolcu listesi : " << endl;
	Yolcular* yolcu = new Yolcular();
	vector<Yolcular*> yolcular = yolcu->Getir();
	for (Yolcular* yolcu : yolcular) {
		cout << "TCKN : " + yolcu->TCKN
			<< " \tISIM : " + yolcu->ISIM
			<< " \tEPOSTA : " + yolcu->EPOSTA
			<< " \tPLAKAKOD : " + to_string(yolcu->PLAKAKOD)
			<< " \tADRES : " + yolcu->ADRES << endl;
	}

	system("PAUSE");
}

void YolcuIslemleri_YolcuEkle()
{
	Yolcular* yolcu = new Yolcular();
	cout << "Yolcunun TCKN bilgisi : " << endl;
	cin >> yolcu->TCKN;
	cout << "Yolcunun ISIM bilgisi : " << endl;
	cin >> yolcu->ISIM;
	cout << "Yolcunun EPOSTA bilgisi : " << endl;
	cin >> yolcu->EPOSTA;
	cout << "Yolcunun PLAKAKOD bilgisi : " << endl;
	cin >> yolcu->PLAKAKOD;
	cout << "Yolcunun ADRES bilgisi : " << endl;
	cin >> yolcu->ADRES;

	yolcu->Kaydet();
	cout << "Isleminiz yapildi" << endl;
	system("PAUSE");
}

void YolcuIslemleri_YolcuSil()
{
	cout << "Sistemde tanimli yolcu listesi : " << endl;
	Yolcular* yolcu = new Yolcular();
	vector<Yolcular*> yolcular = yolcu->Getir();
	for (Yolcular* yolcu : yolcular) {
		cout << "TCKN : " + yolcu->TCKN
			<< "\tISIM : " + yolcu->ISIM
			<< "\EPOSTA : " + yolcu->EPOSTA
			<< "\PLAKAKOD : " + yolcu->PLAKAKOD
			<< "\ADRES : " + yolcu->ADRES << endl;
	}

	cout << "Silinecek yolcunun TCKN bilgisi : " << endl;
	cin >> yolcu->TCKN;
	yolcu->Sil();
	cout << "Isleminiz yapildi" << endl;
	system("PAUSE");
}

void BiletIslemleri_Menu() {
	int islem;
	do {
		system("CLS");
		cout << "*********************************************************************" << endl;
		cout << "Bilet Islem Listesi : " << endl;
		cout << "\t1-Bilet satin alma" << endl;
		cout << "\t2-Bilet iptal etme" << endl;
		cout << "\t3-Yolcu bilet sorgulama" << endl;
		cout << "\t0-Cikis" << endl;
		cout << "*********************************************************************" << endl;
		cout << "Lutfen yapmak istediginiz islemi girin : " << endl;
		cin >> islem;

		system("CLS");
		switch (islem)
		{
		case 0:
			break;
		case 1:
			BiletIslemleri_BiletSat();
			break;
		case 2:
			BiletIslemleri_BiletIptal();
			break;
		case 3:
			BiletIslemleri_BiletSorgula();
			break;
		default:
			cout << "Hatali bir secim yaptiniz, Lutfen tekrar deneyiniz." << endl;
			system("PAUSE");
			break;
		}
	} while (islem != 0);

}

void BiletIslemleri_BiletSat()
{
	string tckn;
	cout << "Yolcunun TCKN bilgisi : " << endl;
	cin >> tckn;
	Yolcular* yolcu = new Yolcular();
	yolcu = yolcu->Getir(tckn);
	if (yolcu == nullptr) {
		cout << "Girilen tckn icin musteri bilgisi bulunamadi, yeni yolcu olusturuluyor" << endl;
		Yolcular* yolcu = new Yolcular();
		yolcu->TCKN = tckn;
		cout << "Yolcunun ISIM bilgisi : " << endl;
		cin >> yolcu->ISIM;
		cout << "Yolcunun EPOSTA bilgisi : " << endl;
		cin >> yolcu->EPOSTA;
		cout << "Yolcunun PLAKAKOD bilgisi : " << endl;
		cin >> yolcu->PLAKAKOD;
		cout << "Yolcunun ADRES bilgisi : " << endl;
		cin >> yolcu->ADRES;
		yolcu->Kaydet();
	}

	string tarih;
	int basNokta, bitNokta, biletSayisi;
	cout << "Yolculuk tarihi : " << endl;
	cin >> tarih;
	cout << "Yolculuk baslangic noktasi : " << endl;
	cin >> basNokta;
	cout << "Yolculuk bitis noktasi : " << endl;
	cin >> bitNokta;
	cout << "Yolculuk bilet sayisi : " << endl;
	cin >> biletSayisi;

	Yolculuk* yolculuk = new Yolculuk();
	vector<Bilet*> biletler = yolculuk->BiletBul(basNokta, bitNokta, tarih, biletSayisi);
	if (!biletler.empty())
	{
		int i = 1, secenek;
		for (Bilet* bilet : biletler) {
			cout << to_string(i) + ". Bilet"
				<< "\tBAS_NOKTA : " + to_string(bilet->BAS_NOKTA)
				<< "\tBIT_NOKTA : " + to_string(bilet->BIT_NOKTA)
				<< "\tTUR : " + bilet->TUR
				<< "\tBOS_ADET : " + to_string(bilet->BOS_ADET)
				<< "\tBIRINCI_UCUS : " + bilet->BIRINCI_UCUS
				<< "\tIKINCI_UCUS : " + bilet->IKINCI_UCUS
				<< "\tUCUNCU_UCUS : " + bilet->UCUNCU_UCUS << endl;
			i++;
		}
		cout << "Hangi bileti seciyorsunuz : " << endl;
		cin >> secenek;

		for (int i = 0; i < biletSayisi; i++)
		{
			if (!biletler[secenek - 1]->BIRINCI_UCUS.empty()) {
				Sefer* sefer = new Sefer();
				sefer->UKN = biletler[secenek - 1]->BIRINCI_UCUS;
				sefer->TARIH = tarih;
				yolculuk->BiletSat(yolcu, sefer);
			}
			if (!biletler[secenek - 1]->IKINCI_UCUS.empty()) {
				Sefer* sefer = new Sefer();
				sefer->UKN = biletler[secenek - 1]->IKINCI_UCUS;
				sefer->TARIH = tarih;
				yolculuk->BiletSat(yolcu, sefer);
			}
			if (!biletler[secenek - 1]->UCUNCU_UCUS.empty()) {
				Sefer* sefer = new Sefer();
				sefer->UKN = biletler[secenek - 1]->UCUNCU_UCUS;
				sefer->TARIH = tarih;
				yolculuk->BiletSat(yolcu, sefer);
			}
		}
		cout << "Isleminiz yapildi" << endl;
	}
	else {
		cout << "Uygun bilet bulunamadi" << endl;
	}
	system("PAUSE");
}

void BiletIslemleri_BiletIptal()
{
	string tckn;
	cout << "Yolcunun TCKN bilgisi : " << endl;
	cin >> tckn;

	Yolcular* yolcu = new Yolcular();
	yolcu = yolcu->Getir(tckn);
	if (yolcu != nullptr) {
		Yolculuk* bilet = new Yolculuk();
		vector<Yolculuk*> biletler = bilet->YolculukSorgula(yolcu);

		cout << yolcu->TCKN + " kimlik numarali musterinin bilgileri : " << endl;
		cout << "TCKN : " + yolcu->TCKN
			<< " \tISIM : " + yolcu->ISIM
			<< " \tEPOSTA : " + yolcu->EPOSTA
			<< " \tPLAKAKOD : " + to_string(yolcu->PLAKAKOD)
			<< " \tADRES : " + yolcu->ADRES << endl;

		cout << yolcu->TCKN + " kimlik numarali musterinin biletleri : " << endl;
		for (Yolculuk* bilet : biletler) {
			cout << "TCKN : " + bilet->TCKN
				<< "UKN : " + bilet->UKN
				<< "TARIH : " + bilet->TARIH
				<< "SAAT : " + bilet->SAAT
				<< "BAS_NOKTA : " + to_string(bilet->BAS_NOKTA)
				<< "BIT_NOKTA : " + to_string(bilet->BIT_NOKTA) << endl;
		}
		bilet->TCKN = yolcu->TCKN;
		cout << "Iptal edilecek olan biletin ukn bilgisi : " << endl;
		cin >> bilet->UKN;
		cout << "Iptal edilecek olan biletin tarih bilgisi : " << endl;
		cin >> bilet->TARIH;

		bilet->BiletIptal();
		cout << "Isleminiz yapildi" << endl;
	}
	else {
		cout << "Girilen tckn icin musteri bilgisi bulunamadi" << endl;
	}
	system("PAUSE");
}

void BiletIslemleri_BiletSorgula()
{
	string tckn;
	cout << "Yolcunun TCKN bilgisi : " << endl;
	cin >> tckn;

	Yolcular* yolcu = new Yolcular();
	yolcu = yolcu->Getir(tckn);
	if (yolcu != nullptr) {
		Yolculuk* bilet = new Yolculuk();
		vector<Yolculuk*> biletler = bilet->YolculukSorgula(yolcu);

		cout << yolcu->TCKN + " kimlik numarali musterinin bilgileri : " << endl;
		cout << "TCKN : " + yolcu->TCKN
			<< " \tISIM : " + yolcu->ISIM
			<< " \tEPOSTA : " + yolcu->EPOSTA
			<< " \tPLAKAKOD : " + to_string(yolcu->PLAKAKOD)
			<< " \tADRES : " + yolcu->ADRES << endl;

		cout << yolcu->TCKN + " kimlik numarali musterinin biletleri : " << endl;
		for (Yolculuk* bilet : biletler) {
			cout << "TCKN : " + bilet->TCKN
				<< "UKN : " + bilet->UKN
				<< "TARIH : " + bilet->TARIH
				<< "SAAT : " + bilet->SAAT
				<< "BAS_NOKTA : " + to_string(bilet->BAS_NOKTA)
				<< "BIT_NOKTA : " + to_string(bilet->BIT_NOKTA) << endl;
		}
	}
	else {
		cout << "Girilen tckn icin musteri bilgisi bulunamadi" << endl;
	}
	system("PAUSE");
}