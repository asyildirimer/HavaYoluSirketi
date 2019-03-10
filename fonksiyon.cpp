/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// Öðrenci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <locale.h>
#include "HavaYolu.h"
#include "dosyalama.h"
#include "fonksiyon.h"
#define maxUcusSiniri 1500
#define minUcusSiniri 1348
using namespace std;

void belirleSeferNo(int s)
{
	
	//uçuþ numarasýný SistemBilgileri.txt ye kaydetmek için kullanýlan fonksiyon
	
	int k,m;
	fstream oku("SistemBilgileri.txt",ios::in);
	oku>>m>>k;
	oku.close();	
	fstream sefer("SistemBilgileri.txt",ios::out);
	sefer.setf(ios::left);
	sefer<<setw(6)<<s<<k;
	sefer.close();
}

void belirleMusteriId(int koltuk)
{
	
	//müþteri ID numarasýný SistemBilgileri.txt ye kaydetmek için kullanýlan fonksiyon
	
	int k,m;
	fstream oku("SistemBilgileri.txt",ios::in);
	oku>>m>>k;
	oku.close();
	fstream sefer("SistemBilgileri.txt",ios::out);
	sefer.setf(ios::left);
	sefer<<setw(6)<<m<<koltuk;
	sefer.close();
}

string getirSeferNo()
{
	
	//uçuþ numarasýný SistemBilgileri.txt den  getirmek için kullanýlan fonksiyon
	
	string s;
	fstream sefer("SistemBilgileri.txt",ios::in);
	if(!sefer)
	{
		belirleSeferNo(minUcusSiniri);
		belirleMusteriId(1);
		return "1348";
	}
	else{
		sefer>>s;
		return s;
	}
}

string getirMusteriId()
{
	
	//müþteri ID numarasýný SistemBilgileri.txt den getirmek için kullanýlan fonksiyon
	
	string s,k;
	fstream sefer("SistemBilgileri.txt",ios::in);
	if(!sefer)
	{
		belirleSeferNo(minUcusSiniri);
		belirleMusteriId(1);
		return "1";
	}
	else{
		sefer>>s>>k;
		return k;
	}
}

void fabrikaAyarlari()
{
	
	//txt dosyalarýnýn içindeki verileri boþaltmak için kullanýlan fonskiyon
	
	string a;
		cout<<"Programý fabrika verilerine döndürmek istiyorsanýz \"ONAYLIYORUM\" yazýnýz = ";
		cin>>a;
	if(a=="ONAYLIYORUM"){	
		fstream d1( "Ucuslar.txt", ios::out );
		fstream d2( "SistemBilgileri.txt", ios::out);
		fstream d3("Yolcular.txt",ios::out);
		fstream d4("GenelListe.txt",ios::out);
		d2.setf(ios::left);
		d2<<setw(6)<<1348<<1;
		d1.close();
		d2.close();
		d3.close();
		d4.close();
		cout<<"Program fabrika verilenrine baþarýyla döndürülmüþtür."<<endl;
	}
	else cout<<"Program fabrika verilerine döndürme iþlemi iptal edilmiþtir."<<endl;
}

void clearScreen()	
{
	
	//system("cls"); ekraný temizlemek için kullanýyorum(yazýlarý yukarý kaydýrýyor temiz bir ekran görünüyor)
	
	for(int i=0;i<100;i++)
	{
		cout<<"\n";
	}
}
