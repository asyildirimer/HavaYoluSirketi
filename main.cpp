/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// Öðrenci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <locale.h>
#include <ctype.h>

#include "menu.h"
#include "dosyalama.h"
#include "fonksiyon.h"
#include "listeleme.h"
#include "HavaYolu.h"

#define maxUcusSiniri 1500

using namespace std;

int main() 
{
	setlocale(LC_ALL,"Turkish");

	ucak ucuslar[maxUcusSiniri];
	musteri musteriler[16000];
	cout<<"BU PROGRAM WÝNDOWS UYUMLU OLARAK HAZIRLANMIÞTIR.\nLÝNUX UYUMU ÝÇÝN BAÐZI GETCHAR() fonksiyonlarýndan dolayý sorunlar çýkabilir\nonlarýn gerekli olanlarýný kaldýrýp çalýþtýrabilisiniz.\n\n\n";
	char islem;
	for(;1;)
	{
		islem=anaMenu();
		if(islem==1)//listelerin bulunduðu menü
		{
			
			for(;islem!=0;)
			{
				islem=ucusListeMenu();
				ucusOku(ucuslar);
				musteriOku(musteriler);
				if(islem==1)
				{
					clearScreen();
					ucusListele(ucuslar,musteriler);
				}
				else if(islem==2)
				{
					clearScreen();
					musteriListele(musteriler);
				}
				else if(islem==3)
				{
					clearScreen();
					genelListe(musteriler,ucuslar);
				}
				else if(islem==0)
				{
					clearScreen();
					cout<<"\nÜst menüye çýkýlýyor.\n";
				}
				else
				{
					clearScreen();
					cout<<"\nGeçersiz iþlem girdiniz!\n";
				}
			}
		}
		else if(islem==2)//bilet iþlemleri menüsü
		{
			for(;islem!=0;)
			{
				
				islem=biletMenu();
				if(islem==1)
				{
					clearScreen();
					ucusOku(ucuslar);
					musteriOku(musteriler);
					biletSatis(musteriler,ucuslar);
				}
				else if(islem==2)
				{
					//bilet güncelleme 1
					clearScreen();
					ucusOku(ucuslar);
					musteriOku(musteriler);
					musteriGuncelle(ucuslar,musteriler,1);
				}
				else if(islem ==3)
				{
					//bilet silme 2
					clearScreen();
					ucusOku(ucuslar);
					musteriOku(musteriler);
					musteriGuncelle(ucuslar,musteriler,2);
				}
				else if(islem==0)
				{
					clearScreen();
					cout<<"\nÜst menüye çýkýlýyor.\n";
				}
				else
				{
					clearScreen();
					cout<<"Geçersiz iþlem girdiniz!\n";
				}
			}
		}
		else if(islem==3)//uçuþ iþlemleri menüsü
		{
			for(;islem!=0;){
				islem=ucakMenu();
				if(islem==1)
				{
					clearScreen();
					ucusOku(ucuslar);
					ucusEkle(ucuslar);
				}
				else if(islem==2)
				{
					clearScreen();
					//uçuþ güncelleme (1)
					ucusOku(ucuslar);
					musteriOku(musteriler);
					ucusGuncelle(ucuslar,musteriler,1);
				}
				else if(islem==3)
				{
					clearScreen();
					//uçuþ silme (2)
					ucusOku(ucuslar);
					musteriOku(musteriler);
					ucusGuncelle(ucuslar,musteriler,2);
				}
				else if(islem==0)
				{
					clearScreen();
					cout<<"Üst menüye çýkýlýyor.\n";
				}
				else{
					cout<<"Geçersiz iþlem girdiniz!\n";
				}
				
			}
		}
		else if(islem==4)//dosyalarý silme
		{
			clearScreen();
			fabrikaAyarlari();
		}
		else if(islem==0)//programdan çýkýþ
		{
			clearScreen();
			ucusOku(ucuslar);
			musteriOku(musteriler);
			genelListeGuncelle(musteriler,ucuslar);
			
			cout<<"Program Sonlandýrýldý!";
			return 0;
		}
		else
		{
			clearScreen();
			cout<<"Geçersiz iþlem yaptýnýz!\n";
		}
	}

}
