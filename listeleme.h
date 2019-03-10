/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// Öðrenci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/
#ifndef LISTELEME_H
#define LISTELEME_H
#include <iostream>
#include "havayolu.h"
using namespace std;

int musteriListele(musteri musteriListesi[]);
	//müþterileri ekranda göstermek için kullanýlan fonksiyon.
	
int ucusListele(ucak ucakListesi[],musteri musteriListesi[]);
	//uçuþlarý ekranda listelemek için kullanýlan fonksiyon
	
void genelListe(musteri musteriListesi[],ucak ucakListesi[]);
	//uçuþlara göre yolcularý düzenli bir þekilde ekrana yazdýrmak için kullanýlan fonksiyon
	
string koltukListe(string sefer,musteri musteriListesi[],int koltukSayisi,int l);
	//Uçuþun boþ koltuklarýný bulmak ve ekran da göstermek için kullanýlan fonksiyon
	
#endif
