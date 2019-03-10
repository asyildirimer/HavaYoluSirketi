/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

// Ad         : Ahmed Said
// Soyad      : YILDIRIMER
// Öðrenci no : 17110131002

/*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*//*/*/

#include "havayolu.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "fonksiyon.h"
using namespace std;

///////////// Ucak Classý fonksiyon tanýmlamasý baþlangýç /////////////////

void ucak::belirleKalkisYeri()
{
	
	// Bu fonksiyon uçaðýn nerede kalkýþ yapacaðýný belirlemek için kullanýlýr.	

	string ky;
	char character[31];
	for(int b=0,durum=0;durum==0;)
	{
		if(b==0)
		{
			cout<<"Kalkýþ yeri: ";
			b=1;
		}
		else
		{
			cout<<"Tekrar Kalkýþ yeri:";
		}
		getline(cin,ky);
		ky.copy(character,ky.size());
		if(ky.size()>30)
		{
			cout<<"Kalkýþ yerini çok uzun girdiniz!.(max 30 karakter)\n";
		}
		else{
			for(int i=0;i<ky.size();i++)
			{
				durum=1;
				if(!isalpha(character[i]))
				{
					if(character[i]!=' ')
					{
						durum=0;
						cout<<"Sadece harf giriniz!\n";
						break;
					}
				}
			}
		}
	}
	
	for(int i=ky.size();i<31;i++)
	{
		kalkisYeri[i]=0;
	}
	ky.copy(kalkisYeri,ky.size());
}

void ucak::belirleVarisYeri()
{
	
	//Bu fonksiyon uçaðýn nereye gideceðini belirlemek için kullanýlýr.
	
	string vy;
	char character[31];
	for(int b=0,durum=0;durum==0;)
	{
		if(b==0)
		{
			cout<<"Varýþ yeri: ";
		}
		else
		{
			cout<<"Tekrar varýþ yeri:";
		}
		getline(cin,vy);
		vy.copy(character,vy.size());
		if(vy.size()>30)
		{
			cout<<"Varýþ yerini çok uzun girdiniz!.(max 30 karakter)\n";
		}
		else{
			for(int i=0;i<vy.size();i++)
			{
				durum=1;
				if(!isalpha(character[i]))
				{
					if(character[i]!=' ')
					{
						durum=0;
						cout<<"Sadece harf giriniz!\n";
						break;
					}
				}
			}
		}
	}
	for(int i=vy.size();i<31;i++)
	{
		varisYeri[i]=0;
	}
	vy.copy(varisYeri,vy.size());
}

void ucak::belirleKoltukSayisi()
{
	
	//Bu fonksiyon uçaðýn yolcu kapasitesini belirlemek için kullanýlýr.
	
	int i=0,sayimi=1;
	string kar;
	char character[3];
	for(;sayimi==1;)
	{
		for(int z=0;z<3;z++)
		{
			character[z]=0;
		}
		cout<<"Koltuk Sayýsý: ";
		getline(cin,kar);
		kar.copy(character,3);
		for(sayimi=0,i=0;i<kar.size();i++)
		{
			if(!isdigit(character[i]))
			{
				sayimi=1;
				break;
			}
		}
		i=atoi(character);
		if(sayimi==1){
			
			cout<<"Sadece rakam giriniz!.\n";
		}
		else if(i>100 || i<1 || i%4!=0)
		{
			sayimi=1;
			cout<<"Girdiðiniz koltuk sayýlý bir uçak bulunamadý!.(4'ün katý koltuk sayýsý olmalý ve 100 den küçük olmalý)\n";
		}
		
	}
	for(int i=kar.size();i<3;i++)
	{
		koltukSayisi[i]=0;
	}
	koltukSayisi[0]=character[0];
	if(i>9)
	{
		koltukSayisi[1]=character[1];
	}
	else if(i==100)
	{
		koltukSayisi[2]=character[2];
	}
}

void ucak::belirleUcusNo()
{
	
	//Bu fonksiyon uçaðýn uçuþ numarasýný belirlemek için kullanýlýr.
	
	string u = getirSeferNo();
	for(int i=u.size();i<6;i++)
	{
		ucusNo[i]=0;
	}
	u.copy(ucusNo,u.size());
}

void ucak::belirleKalkisYeri(string ky)
{
	
	//Uçuþ' un kalkýþ yerini dosyadan okunup class'a aktarmak için kullanýlan fonksiyon.
	
	for(int i=ky.size();i<31;i++)
	{
		kalkisYeri[i]=0;
	}
	ky.copy(kalkisYeri,ky.size());
}

void ucak::belirleVarisYeri(string vy)
{
	
	//Uçuþ' un varýþ yerini dosyadan okunup class'a aktarmak için kullanýlan fonksiyon.
	
	for(int i=vy.size();i<31;i++)
	{
		varisYeri[i]=0;
	}
	vy.copy(varisYeri,vy.size());
}

void ucak::belirleKoltukSayisi(string ks)
{
	
	//Uçuþ' un koltuk sayýsýný dosyadan okunup class'a aktarmak için kullanýlan fonksiyon.
	
	for(int i=ks.size();i<4;i++)
	{
		koltukSayisi[i]=0;
	}
	ks.copy(koltukSayisi,ks.size());
}

void ucak::belirleUcusNo(string un)
{
	
	//Uçuþ' un uçuþ no sunu dosyadan okunup class'a aktarmak için kullanýlan fonksiyon.
	
	for(int i=un.size();i<6;i++)
	{
		ucusNo[i]=0;
	}
	un.copy(ucusNo,un.size());
}



string ucak::getirKalkisYeri()
{
	return kalkisYeri;
}

string ucak::getirVarisYeri()
{
	return varisYeri;
}

string ucak::getirUcusNo()
{
	return ucusNo;
}

string ucak::getirKoltukSayisi()
{
	return koltukSayisi;
}

ucak::ucak()
{
	belirleUcusNo("\0");
	belirleKalkisYeri("");
	belirleVarisYeri("");
	belirleKoltukSayisi("");
}


///////////// Ucak Classý fonksiyon tanýmlamasý bitiþ /////////////////

///////////// Müþteri Classý fonksiyon tanýmlamasý baþlangýç /////////////////

void musteri::belirleAd()
{
	
	//Bu fonksiyon müþterinin adýný belirlemek için kullanýlýr.
	
	string a;
	char character[21];
	for(int b=0,durum=0;durum==0;)
	{
		if(b==0)
		{
			cout<<"Adý: ";
		}
		else
		{
			cout<<"Tekrar Adý:";
		}
		getline(cin,a);
		a.copy(character,a.size());
		if(a.size()>20)
		{
			cout<<"Adýný çok uzun girdiniz!.(max 20 karakter)\n";
		}
		else{
			for(int i=0;i<a.size();i++)
			{
				durum=1;
				if(!isalpha(character[i]))
				{
					if(character[i]!=' ')
					{
						durum=0;
						cout<<"Sadece harf giriniz!\n";
						break;
					}
				}
			}
		}
	}
	for(int i=a.size();i<21;i++)
	{
		ad[i]=0;
	}
	a.copy(ad,a.size());
}

void musteri::belirleSoyad()
{
	
	//Bu fonksiyon müþterinin soyadýný belirlemek için kullanýlýr.
	
	string s;
	char character[21];
	for(int b=0,durum=0;durum==0;)
	{
		if(b==0)
		{
			cout<<"Soyadý: ";
		}
		else
		{
			cout<<"Tekrar Soyadý:";
		}
		getline(cin,s);
		s.copy(character,s.size());
		if(s.size()>20)
		{
			cout<<"Soyadýný çok uzun girdiniz!.(max 20 karakter)\n";
		}
		else{
			for(int i=0;i<s.size();i++)
			{
				durum=1;
				if(!isalpha(character[i]))
				{
					if(character[i]!=' ')
					{
						durum=0;
						cout<<"Sadece harf giriniz!\n";
						break;
					}
				}
			}
		}
	}
	for(int i=s.size();i<21;i++)
	{
		soyad[i]=0;
	}
	s.copy(soyad,s.size());
}

void musteri::belirleAd(string a)
{
	
	//Bu fonksiyon müþterinin adýný belirlemek için kullanýlýr.
	
	for(int i=a.size();i<21;i++)
	{
		ad[i]=0;
	}
	a.copy(ad,a.size());
}

void musteri::belirleSoyad(string s)
{
	
	//Bu fonksiyon müþterinin soyadýný belirlemek için kullanýlýr.
	
	for(int i=s.size();i<21;i++)
	{
		soyad[i]=0;
	}
	s.copy(soyad,s.size());
}


void musteri::belirleMusteriId(string m)
{
	
	//Müþteriye belirli bir id vermek için kullanýlýr.
	
	for(int i=m.size();i<5;i++)
	{
		musteriId[i]=0;
	}
	m.copy(musteriId,m.size());
}

void musteri::belirleKoltukNo(string k)
{	

	//Müþterinin koltuk numarasýný belirlemek için kullanýlýr.
	
	for(int i=k.size();i<4;i++)
	{
		koltukNo[i]=0;
	}
	k.copy(koltukNo,k.size());
}

void musteri::belirleUcusNoMusteri(string u)
{
	
	//Müþterinin hangi uçuþ'a ait olduðunu belirlemek için kullanýlýr.
	for(int i=u.size();i<6;i++)
	{
		ucusNoM[i]=0;
	}
	u.copy(ucusNoM,u.size());
}

string musteri::getirAd()
{
	return ad;
}

string musteri::getirSoyad()
{
	return soyad;
}

string musteri::getirKoltukNo()
{
	return koltukNo;
}

string musteri::getirUcusNo()
{
	return ucusNoM;
}

string musteri::getirMusteriId()
{
	return musteriId;
}


musteri::musteri()
{
	belirleAd("\0");
	belirleSoyad("");
	belirleKoltukNo("");
	belirleUcusNoMusteri("");
	belirleMusteriId("");
}

///////////// Müþteri Classý fonksiyon tanýmlamasý bitiþ /////////////////
