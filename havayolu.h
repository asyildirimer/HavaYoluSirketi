/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// Öðrenci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

#ifndef HAVAYOLU_H_
#define HAVAYOLU_H_
#include <string>
#include <iostream>
using namespace std;

class ucak{
	private:
		char ucusNo[6];
		char koltukSayisi[4];
		char kalkisYeri[31];
		char varisYeri[31];
	public:	
		void belirleKalkisYeri();
		void belirleVarisYeri();
		void belirleKoltukSayisi();
		void belirleUcusNo();
		
		void belirleKalkisYeri(string ky);
		void belirleVarisYeri(string vy);
		void belirleKoltukSayisi(string ks);
		void belirleUcusNo(string un);
		
		string getirKalkisYeri();
		string getirVarisYeri();
		string getirUcusNo();
		string getirKoltukSayisi();
		
		ucak();
};

class musteri{
	private:
		char ad[21];
		char soyad[21];
		char koltukNo[4];
		char ucusNoM[6];
		char musteriId[5];
	public:
		void belirleAd();
		void belirleSoyad();
		void belirleAd(string a);
		void belirleSoyad(string s);
		
		void belirleMusteriId(string m);
		void belirleKoltukNo(string k);
		void belirleUcusNoMusteri(string u);
				
		string getirAd();
		string getirSoyad();
		string getirKoltukNo();
		string getirUcusNo();
		string getirMusteriId();
		
		musteri();
};


#endif
