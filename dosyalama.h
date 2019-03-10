/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// Öðrenci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

#ifndef DOSYALAMA_H_
#define DOSYALAMA_H_
#include <iostream>
#include "havayolu.h"
using namespace std;

void ucusGuncelle(ucak ucakListesi[],musteri musteriListesi[],int islemTuru);
		//uçuþ verilerini güncelleyen-silen fonksiyon
		
		
void genelListeGuncelle(musteri musteriListesi[],ucak ucakListesi[]);
		//GenelListe.txt sine uçuþ ve müþteri bilgilerini yazan fonksiyon
		
		
void musteriGuncelle(ucak ucakListesi[],musteri musteriListesi[],int islemTuru);
		//müþteri bilgierini güncelleme-silme için kullanýlan fonksiyon
		
		
void ucusEkle(ucak ucakListesi[]);
		//yeni uçuþ kaydý oluþturmak için kullanýlan fonksiyon
		
		
void ucusOku(ucak ucakListesi[]);
		//txt dosyasýndaki uçuþ verilerini diziye aktarmak için olan fonksiyon
		
		
void musteriOku(musteri musteriListesi[]);
		//txt dosyasýndaki müþteri verilerini diziye aktarmak için olan fonksiyon
		

void biletSatis(musteri musteriListesi[],ucak ucakListesi[]);		
		//müþteriye bilet satýþý yapmak için kullanýlan fonksiyon
		
#endif
