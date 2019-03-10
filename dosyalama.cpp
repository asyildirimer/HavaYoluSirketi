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
#include "listeleme.h"
#define maxUcusSiniri 1500
#define minUcusSiniri 1348

using namespace std;

////////////////////////////////////////////// UÇUÞ GÜNCELLEME BAÞLANGIÇ //////////////////////////////////////////////

void ucusGuncelle(ucak ucakListesi[],musteri musteriListesi[],int islemTuru) 
{
	
	//uçuþ verilerini güncelleyen-silen fonksiyon
	
	// islem 1 güncelleme islem 2 silme
	int bos=ucusListele(ucakListesi,musteriListesi);
	if(bos==1) 
	{
		int liste[200]= {0};
		int islem=0;
		string sefer;
		
		for(int i=minUcusSiniri,s=0; i<atoi(getirSeferNo().c_str()); i++) 
		{
			if(ucakListesi[i].getirUcusNo()!="\0") 		//tüm uçuþlarýn uçul no larýný listeye atýyorum
			{
				liste[s]=atoi(ucakListesi[i].getirUcusNo().c_str());
				s++;
			}
		}
		
		if(islemTuru==1) 
		{
			cout<<"Güncelleme istediðiniz uçuþ no:";
		}
		else 
		{
			cout<<"Silmek istediðiniz uçuþ no:";
		}
		getchar();
		getline(cin,sefer);
		for(int i=0; liste[i]!=0; i++) 
		{
			if(liste[i]==atoi(sefer.c_str())) 
			{
				islem=1;
				break;
			}
		}
		
		if(islem==0) 
		{
			cout<<"Geçersiz uçuþ no girdiniz!\n";
			return;
		}
		
		int is=atoi(sefer.c_str());
		
		if(islemTuru==2) 
		{
			cout<<"Silme iþlemine devam etmek için \"ONAYLIYORUM\" yazýnýz(bu uçuþa ait tüm yolcu kayýtlarýnýda silmiþ olursunuz!):";
			string o;
			getline(cin,o);
			if(o=="ONAYLIYORUM")		//uçuþ kaydýný siliyorum
			{
				ucakListesi[is].belirleUcusNo("00000");
			} 
			else 
			{
				cout<<"Silme iþlemi iptal edildi!";
				return;
			}
		} 
		else if(islemTuru==1) 
		{
			int musteriMax=0;
				
			cout<<"\n\n"<<setw(10)<<"UÇUÞ NO"<<setw(35)<<"KALKIÞ YERÝ"<<setw(35)<<"VARIÞ YERÝ"<<setw(15)<<"KOLTUK SAYISI"<<"\n";
			cout<<setw(10)<<ucakListesi[is].getirUcusNo()
			<<setw(35)<<ucakListesi[is].getirKalkisYeri()
			<<setw(35)<<ucakListesi[is].getirVarisYeri()
			<<setw(15)<<ucakListesi[is].getirKoltukSayisi()	
			<<"\nolan uçuþun yeni bilgileri:\n\n";
			ucakListesi[is].belirleUcusNo(ucakListesi[is].getirUcusNo());
			ucakListesi[is].belirleKalkisYeri();
			ucakListesi[is].belirleVarisYeri();
						
						//uçuþ kaydýný güncelliyorum	

			for(int i=0;i<atoi(getirMusteriId().c_str()); i++) 
			{
				if( musteriListesi[i].getirUcusNo()==sefer && atoi(musteriListesi[i].getirKoltukNo().c_str())>musteriMax) 
				{
					musteriMax= atoi(musteriListesi[i].getirKoltukNo().c_str());	//seçilen uçuþun kaçýncý koltuða kadar satýldýðýný buluyorum
				}
			}
			
			if(musteriMax<100) //koltuk güncelliyorum
			{
				string ks;

				if(musteriMax!=0) 
				{
					cout<<"Yeni koltuk sayýsýný giriniz ("<<musteriMax<<". koltuða kadar bilet satýþý yapýlmýþtýr):";
				} 
				else 
				{
					cout<<"Yeni koltuk sayýsýný giriniz:";
				}
				getline(cin,ks);
				if(atoi(ks.c_str())>0 && atoi(ks.c_str())<=100 && atoi(ks.c_str())%4==0 && musteriMax<atoi(ks.c_str())) 
				{
					ucakListesi[is].belirleKoltukSayisi(ks);
					islem=1;
				} 
				else 
				{
					for(int islem=0; islem==0 || atoi(ks.c_str())%4!=0;) 
					{
						if(musteriMax>atoi(ks.c_str())) 
						{
							cout<<musteriMax<<". koltuða kadar bilet satýlmýþtýr!\nBilet sayýsýný "<<ks.c_str()<<" e düþüremezsiniz!\nTekrar giriniz:";
							getline(cin,ks);
						}
						else if(atoi(ks.c_str())%4!=0 || atoi(ks.c_str())<0 || atoi(ks.c_str())>100  ) 
						{
							cout<<"Girdiðiniz koltuk sayýlý bir uçak bulunamadý!.(4'ün katý koltuk sayýsý olmalý ve 100 den küçük olmalý)\nTekrar giriniz:";
							getline(cin,ks);
						}
						if(atoi(ks.c_str())>0 && atoi(ks.c_str())<=100 && atoi(ks.c_str())%4==0 && musteriMax<=atoi(ks.c_str())) 
						{
							ucakListesi[is].belirleKoltukSayisi(ks);
							islem=1;
						}
					}
				}
			}
		}

		fstream yazma("Ucuslar.txt",ios::out);
		for(int i=minUcusSiniri; i<atoi(getirSeferNo().c_str()); i++) 
		{
			if(ucakListesi[i].getirUcusNo()!="00000" && i!=is && ucakListesi[i].getirUcusNo()!="") 
			{
				yazma.setf(ios::left);
				string a,b,c,d;
				if(ucakListesi[i].getirUcusNo()!="")
				{
					a=ucakListesi[i].getirUcusNo()+";";
					b=ucakListesi[i].getirKalkisYeri()+";";
					c=ucakListesi[i].getirVarisYeri()+";";
					d=ucakListesi[i].getirKoltukSayisi();
					yazma<<a<<b<<c<<d<<endl;
				}
				
			}
		}
		
		if(islemTuru==1) 
		{
			string a,b,c,d;
			a=ucakListesi[is].getirUcusNo()+";";
			b=ucakListesi[is].getirKalkisYeri()+";";
			c=ucakListesi[is].getirVarisYeri()+";";
			d=ucakListesi[is].getirKoltukSayisi();
			yazma<<a<<b<<c<<d<<endl;
			cout<<"Kayýt baþarýyla güncelendi!\n";
		}
		else 
		{
			fstream musteriSilme("Yolcular.txt",ios::out);
			for(int i=1;i<atoi(getirMusteriId().c_str());i++)
			{
				if(musteriListesi[i].getirUcusNo()!=sefer)
				{
					string a,b,c,d,e;
					if(musteriListesi[i].getirAd()!="")
					{
						a=musteriListesi[i].getirMusteriId()+";";
						b=musteriListesi[i].getirUcusNo()+";";
						c=musteriListesi[i].getirSoyad()+";";
						d=musteriListesi[i].getirAd()+";";
						e=musteriListesi[i].getirKoltukNo();
						musteriSilme<<a<<b<<c<<d<<e<<endl;
					}
					
				}
			}
			
			musteriSilme.close();
			cout<<"Uçuþ ve yolcu kayýtlarý baþarýyla silindi!\n";
		}
		yazma.close();
	}

}

////////////////////////////////////////////// UÇUÞ GÜNCELLEME BÝTÝÞ //////////////////////////////////////////////



///////////////////////////////////////// GENEL LÝSTE GÜNCELLEME BAÞLANGIÇ ////////////////////////////////////////

void genelListeGuncelle(musteri musteriListesi[],ucak ucakListesi[])
{
	
	//GenelListe.txt sine uçuþ ve müþteri bilgilerini yazan fonksiyon
	
	fstream genelListeDosyalama("GenelListe.txt",ios::out);
	genelListeDosyalama.setf(ios::left);
	for(int i=minUcusSiniri;i<atoi(getirSeferNo().c_str());i++)
	{
		if(ucakListesi[i].getirKalkisYeri()!="")
		{
			genelListeDosyalama<<setw(10)<<"UÇUÞ NO"<<setw(31)<<"KALKIÞ YERÝ"<<setw(31)<<"VARIÞ YERÝ"<<setw(15)<<"KOLTUK SAYISI"<<setw(15)<<"YOLCU SAYISI"<<"\n";
			fstream musteriAdet("Yolcular.txt",ios::in);
			int adetDizi[100]={0};
			int adet=0;
			for(int m=1;m<atoi(getirMusteriId().c_str());m++)
			{
				if(musteriListesi[m].getirUcusNo()==ucakListesi[i].getirUcusNo())
				{
					adetDizi[adet]=atoi(musteriListesi[m].getirMusteriId().c_str());
					adet++;
				}
			} 
			genelListeDosyalama<<setw(10)<<ucakListesi[i].getirUcusNo()
			<<setw(31)<<ucakListesi[i].getirKalkisYeri()
			<<setw(31)<<ucakListesi[i].getirVarisYeri()
			<<setw(15)<<ucakListesi[i].getirKoltukSayisi()
			<<setw(15)<<adet<<"\n\n";
			if(adet==0)
			{
				genelListeDosyalama<<"                            Bu uçuþda yolcu kaydý bulunmamaktadýr!"<<endl;
			}
			else
			{
				genelListeDosyalama<<setw(15)<<"KOLTUK NO"<<setw(25)<<"SOYAD"<<setw(25)<<"AD"<<endl;
			}
			for(int k=0;k<adet;k++)
			{
				genelListeDosyalama<<setw(15)<<musteriListesi[adetDizi[k]].getirKoltukNo()
				<<setw(25)<<musteriListesi[adetDizi[k]].getirSoyad()
				<<setw(25)<<musteriListesi[adetDizi[k]].getirAd()<<endl;
			}
			genelListeDosyalama<<"***************************************************************************************************"<<endl;
		}
	}
	genelListeDosyalama.close();
}

///////////////////////////////////////// GENEL LÝSTE GÜNCELLEME BÝTÝÞ ////////////////////////////////////////



///////////////////////////////////////// MÜÞTERÝ GÜNCELLEME BAÞLANGIÇ ////////////////////////////////////////

void musteriGuncelle(ucak ucakListesi[],musteri musteriListesi[],int islemTuru)	
{	

	//müþteri bilgierini güncelleme-silme için kullanýlan fonksiyon
	
	
	int b1=ucusListele(ucakListesi,musteriListesi);	
	if(b1==1)
	{
		cout<<"Düzenleyeceðiniz müþteri'nin sefer numarasýný giriniz:";
		string ucusNoGiris;
		getchar();
		getline(cin,ucusNoGiris);
		int islem=0;
		for(int i=minUcusSiniri;i<atoi(getirSeferNo().c_str()) && islem==0;i++)
		{
			if(ucakListesi[i].getirUcusNo()==ucusNoGiris)
			{
				islem=1;
			}
		}
		if(islem==1)
		{
			int yolcu=0;
			
			for(int i=1;i<atoi(getirMusteriId().c_str());i++)
			{
				if(musteriListesi[i].getirUcusNo()==ucusNoGiris)
				{
					cout.setf(ios::left);
					if(yolcu==0)
					{
						cout<<setw(5)<<"ID"<<setw(10)<<"UÇUÞ NO"<<setw(35)<<"ADI"<<setw(35)<<"SOYADI"<<setw(15)<<"KOLTUK NO"<<"\n";
						yolcu=1;
					}
					cout<<setw(5)<<musteriListesi[i].getirMusteriId()
					<<setw(10)<<musteriListesi[i].getirUcusNo()
					<<setw(35)<<musteriListesi[i].getirAd()
					<<setw(35)<<musteriListesi[i].getirSoyad()
					<<setw(15)<<musteriListesi[i].getirKoltukNo()<<endl;
				}
			}
			
			if(yolcu==0)
			{
				cout<<"Girdiðiniz Sefer numarasýnda hiçbir yolcu bulunmamaktadýr!\n";
			}
			else{
				cout<<"Müþterinin id'sini giriniz:";
				string musteriGncllm;
				getline(cin,musteriGncllm);
				int s= atoi(musteriGncllm.c_str());
				int is = atoi(ucusNoGiris.c_str());
				
				if(musteriListesi[s].getirMusteriId()==musteriGncllm && musteriListesi[s].getirUcusNo()==ucusNoGiris)
				{
					if(islemTuru==1)
					{
						//güncelleme
						cout<<"\nAdý:          "<<musteriListesi[s].getirAd()
						<<"\nSoyadý:       "<<musteriListesi[s].getirSoyad()
						<<"\nKoltuk no'su: "<<musteriListesi[s].getirKoltukNo()
						<<"\nolan müþterinin yeni\n";
						string a;
						cout<<"Adý: ";
						getline(cin,a);
						for(;a.size()>20;)
						{
							cout<<"Adýný çok uzun girdiniz!.(max 20 karakter)\nTekrar adý:";
							getline(cin,a);
						}
						musteriListesi[s].belirleAd(a);
						musteriListesi[s].belirleSoyad();
						string koltukSonuc=koltukListe(ucakListesi[is].getirUcusNo(),musteriListesi,atoi(ucakListesi[is].getirKoltukSayisi().c_str()),atoi(musteriListesi[s].getirKoltukNo().c_str()));
						musteriListesi[s].belirleKoltukNo(koltukSonuc);
					}
					else
					{
						//silme
						cout<<"Uçuþ numarasý:"<<musteriListesi[s].getirUcusNo()
						<<"\nAdý:          "<<musteriListesi[s].getirAd()
						<<"\nSoyadý:       "<<musteriListesi[s].getirSoyad()
						<<"\nKoltuk no'su: "<<musteriListesi[s].getirKoltukNo()
						<<"\nolan müþteriyi silmek için \"ONAYLIYORUM\" yazýnýz:";
						string as;
						getline(cin,as);
						
						if(as=="ONAYLIYORUM")
						{
							musteriListesi[s].belirleUcusNoMusteri("00000");
						}
					}
					fstream yazici("Yolcular.txt",ios::out);
					
					for(int z=1;z<atoi(getirMusteriId().c_str());z++)
					{
						if(musteriListesi[z].getirUcusNo()!="00000" && musteriListesi[z].getirAd()!="")
						{
							string a,b,c,d,e;
							a=musteriListesi[z].getirMusteriId()+";";
							b=musteriListesi[z].getirUcusNo()+";";
							c=musteriListesi[z].getirSoyad()+";";
							d=musteriListesi[z].getirAd()+";";
							e=musteriListesi[z].getirKoltukNo();
							yazici<<a<<b<<c<<d<<e<<endl;
						}
					}
					
					yazici.close();	
					
					if(islemTuru==1)
					{
						cout<<"Kayýt baþarýyla güncellendi!\n";
					}
					else if(musteriListesi[s].getirUcusNo()=="00000"){
						cout<<"Kayýt baþarýyla silindi!\n";
					}
					else{
						cout<<"Silme iþlemi iptal edildi!";
					}	
				}
				else
				{
					cout<<"Geçersiz müþteri ID si!\n";
				}
			}
		}
		else
		{
			cout<<"girdiðiniz sefer numaralý uçuþ bulunamadý!\n";
		}
	}
}

/////////////////////////////////////////// MÜÞTERÝ GÜNCELLEME BÝTÝÞ //////////////////////////////////////////



//////////////////////////////////////////// UÇUÞ EKLEME BAÞLANGIÇ ///////////////////////////////////////////

void ucusEkle(ucak ucakListesi[]) 
{
	
	//yeni uçuþ kaydý oluþturmak için kullanýlan fonksiyon
	
	int indi;
	indi=atoi(getirSeferNo().c_str());

	if(maxUcusSiniri>indi) 
	{

		cout<<"Uçuþ numarasý: "<<indi<<" olan uçuþun:\n";

		ucakListesi[indi].belirleUcusNo();
		getchar();
		ucakListesi[indi].belirleKalkisYeri();
		ucakListesi[indi].belirleVarisYeri();
		ucakListesi[indi].belirleKoltukSayisi();

		cout<<"\n\nYeni uçuþ kaydý oluþturuldu.\n";

		belirleSeferNo(indi+1);
		fstream ucuslar("Ucuslar.txt", ios::app);
		
		ucuslar.setf(ios::left);
		string a,b,c,d;
		
		a=ucakListesi[indi].getirUcusNo()+";";
		b=ucakListesi[indi].getirKalkisYeri()+";";
		c=ucakListesi[indi].getirVarisYeri()+";";
		d=ucakListesi[indi].getirKoltukSayisi();
		
		ucuslar<<a<<b<<c<<d<<endl;
		ucuslar.close();
	} 
	else 
	{
		cout<<"\n\nmaximum uçuþ sayýsýna ulaþýldý!.\n\n";
	}
}

////////////////////////////////////////////// UÇUÞ EKLEME BÝTÝÞ /////////////////////////////////////////////


//////////////////////////////////////////// UÇUÞ OKUMA BAÞLANGIÇ  ///////////////////////////////////////////

void ucusOku(ucak ucakListesi[]) 
{
	
	//txt dosyasýndaki uçuþ verilerini diziye aktarmak için olan fonksiyon
	
	fstream ucuslarOku("Ucuslar.txt",ios::in);
	if(!ucuslarOku) 
	{
		return;
	}
	for(int i=minUcusSiniri; ucuslarOku &&!ucuslarOku.eof(); i++) 
	{
		string un,ky,vy,ks;
		getline(ucuslarOku,un,';');
		getline(ucuslarOku,ky,';');
		getline(ucuslarOku,vy,';');
		getline(ucuslarOku,ks,'\n');
		int s=atoi(un.c_str());
		ucakListesi[s].belirleUcusNo(un);
		ucakListesi[s].belirleKalkisYeri(ky);
		ucakListesi[s].belirleVarisYeri(vy);
		ucakListesi[s].belirleKoltukSayisi(ks);
	}
	ucuslarOku.close();
}

////////////////////////////////////////////// UÇUÞ OKUMA BÝTÝÞ  /////////////////////////////////////////////



/////////////////////////////////////////// MÜÞTERÝ OKUMA BAÞLANGIÇ //////////////////////////////////////////

void musteriOku(musteri musteriListesi[]) 
{
	
	//txt dosyasýndaki müþteri verilerini diziye aktarmak için olan fonksiyon
	
	fstream okumaMusteri("Yolcular.txt",ios::in);
	if(!okumaMusteri) 
	{
		return;
	}
	for(int i=0; !okumaMusteri.eof(); i++) 
	{

		string mId,ad,soy,un,kn;
		getline(okumaMusteri,mId,';');
		getline(okumaMusteri,un,';');
		getline(okumaMusteri,soy,';');
		getline(okumaMusteri,ad,';');
		getline(okumaMusteri,kn,'\n');
		int s=atoi(mId.c_str());
		musteriListesi[s].belirleMusteriId(mId);
		musteriListesi[s].belirleAd(ad);
		musteriListesi[s].belirleSoyad(soy);
		musteriListesi[s].belirleUcusNoMusteri(un);
		musteriListesi[s].belirleKoltukNo(kn);
	}
	okumaMusteri.close();
}

///////////////////////////////////////////// MÜÞTERÝ OKUMA BÝTÝÞ ////////////////////////////////////////////



//////////////////////////////////////////// BÝLET SATIÞ BAÞLANGIÇ ///////////////////////////////////////////

void biletSatis(musteri musteriListesi[],ucak ucakListesi[]) 
{
	
	//müþteriye bilet satýþý yapmak için kullanýlan fonksiyon
	
	int durum = ucusListele(ucakListesi,musteriListesi);
	if(durum==1) 
	{
		string ky,vy;
		cout<<"Kalkýþ yeri: ";
		getchar();
		getline(cin,ky);
		
		for(;ky.size()>30;) 
		{
			cout<<"Kalkýþ yerini çok uzun girdiniz!.(max 30 karakter)\nTekrar kalkýþ yeri giriniz:";
			getline(cin,ky);
		}
		
		cout<<"Varýþ yeri: ";
		getline(cin,vy);
		
		for(; vy.size()>30;) 
		{
			cout<<"Varýþ yerini çok uzun girdiniz!.(max 30 karakter)\nTekrar varýþ yeri giriniz:";
			getline(cin,vy);
		}
		
		int bulundu=0;
		string bulunanUcus[maxUcusSiniri-minUcusSiniri];
		
		for(int k=minUcusSiniri,s=0; k<atoi(getirSeferNo().c_str()); k++) 
		{
			if(ky==ucakListesi[k].getirKalkisYeri() && vy==ucakListesi[k].getirVarisYeri()) 
			{
				bulundu++;
				bulunanUcus[s]=ucakListesi[k].getirUcusNo();
				s++;
			}
		}
		
		if(bulundu>0) 
		{
			int sonuc=0;
			string ucus;
			
			cout<<"Aradýðýnýz kriterlerde "<<bulundu<<" adet uçuþ bulunmuþtur.\n";
			cout<<"\n\n* * * * * * * * * * * * * * * * * * * * UÇUÞ  LÝSTESÝ * * * * * * * * * * * * * * * * * * *\n";
			cout<<setw(10)<<"UÇUÞ NO"<<setw(35)<<"KALKIÞ YERÝ"<<setw(35)<<"VARIÞ YERÝ"<<setw(15)<<"KOLTUK SAYISI"<<setw(15)<<"BOÞ KOLTUK SAYISI"<<"\n";
			for(int l=0; l<bulundu; l++) 
			{
				int i=atoi(bulunanUcus[l].c_str());
				int adet=0;
				for(int m=1;m<atoi(getirMusteriId().c_str());m++)
				{
					if(musteriListesi[m].getirUcusNo()==ucakListesi[i].getirUcusNo())
					{
						adet++;
					}
				} 
				cout<<setw(10)<<ucakListesi[i].getirUcusNo()
				<<setw(35)<<ucakListesi[i].getirKalkisYeri()
				<<setw(35)<<ucakListesi[i].getirVarisYeri()
				<<setw(15)<<ucakListesi[i].getirKoltukSayisi()
				<<setw(15)<<atoi(ucakListesi[i].getirKoltukSayisi().c_str())-adet<<endl;
			}
			
			cout<<"\n\n";
			cout<<"Ýþleme devam etmek için uçuþ numarasýný giriniz: ";
			getline(cin,ucus);
			
			for(int l=0; l<bulundu; l++) 
			{
				int i=atoi(getirMusteriId().c_str());
				int s=atoi(bulunanUcus[l].c_str());

				if(ucus==bulunanUcus[l].c_str()) 
				{
					string koltukSonuc=koltukListe(ucakListesi[s].getirUcusNo(),musteriListesi,atoi(ucakListesi[s].getirKoltukSayisi().c_str()),0);
					
					if(koltukSonuc!="0") 
					{
						int indi = atoi(ucakListesi[s].getirUcusNo().c_str());

						musteriListesi[i].belirleMusteriId(getirMusteriId());
						musteriListesi[i].belirleKoltukNo(koltukSonuc);
						getchar();
						musteriListesi[i].belirleAd();
						musteriListesi[i].belirleSoyad();
						musteriListesi[i].belirleUcusNoMusteri(ucakListesi[s].getirUcusNo());

						fstream yolcu("Yolcular.txt", ios::app);
						yolcu.setf(ios::left);
						string a,b,c,d,e;
						
						a=musteriListesi[i].getirMusteriId()+";";
						b=musteriListesi[i].getirUcusNo()+";";
						c=musteriListesi[i].getirSoyad()+";";
						d=musteriListesi[i].getirAd()+";";
						e=musteriListesi[i].getirKoltukNo();
						
						yolcu<<a<<b<<c<<d<<e<<endl;
						yolcu.close();

						belirleMusteriId(i+1);
						cout<<"\nYeni yolcu kaydý oluþturuldu.\n\n";
						cout<<"Uçuþ numarasý: "<<indi<<" olan uçuþun:\nKalkýþ yeri: "<<ucakListesi[s].getirKalkisYeri()
						<<"\nVarýþ yeri: "<<ucakListesi[s].getirVarisYeri()
						<<"\nMüþteri adý: "<<musteriListesi[i].getirAd()
						<<"\nMüþteri Soyadý: "<<musteriListesi[i].getirSoyad()
						<<"\nKoltuk nosu:"<<musteriListesi[i].getirKoltukNo()<<endl;
					} 
					else 
					{
						cout<<"\nSeçtiðiniz uçuþda boþ koltuk bulunmamaktadýr!\n";
					}
					return;
				}
			}
		} 
		else 
		{
			cout<<"\nAradýðýnýz kriterlerde uçuþ bulunamamýþtýr!\n";
			return;
		}
	}
}
////////////////////////////////////////////// BÝLET SATIÞ BÝTÝÞ /////////////////////////////////////////////
