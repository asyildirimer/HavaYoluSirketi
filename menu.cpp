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
#include <time.h>
#include "menu.h"
using namespace std;

int anaMenu()
{
	cout<<"***********Created by Syntax04*********\n"
		<<"* * * * * * *   ANA MENÜ  * * * * * * *\n"
		<<"*   1 - UÇUÞ LÝSTELERÝ                *\n"
		<<"*   2 - BÝLET ÝÞLEMLERÝ               *\n"
		<<"*   3 - UÇAK ÝÞLEMLERÝ                *\n"
		<<"*   4 - FABRÝKA VERÝLERÝNE DÖNDÜR     *\n"
		<<"*   0 - PROGRAMDAN ÇIKIÞ              *\n"
		<<"* * * * * * * * * * * * * * * * * * * *\n";
		
	int islem=0,sayimi=1;
	char character[2];
	for(;sayimi==1;){
		cout<<"Yapmak istediðiniz iþlem: ";
		cin>>character;
		for(sayimi=0,islem=0;islem<2;islem++)
		{
			if(character[islem]!='\0')
			{
					if(!isdigit(character[islem]))
				{
					sayimi=1;
					break;
				}
			}
		}
		islem=atoi(character);
		if(sayimi==1){
			cout<<"Geçersiz karakter!\n";
		}
		
	}
	return islem;
}


int ucakMenu()
{
	cout<<"* * * * * * *  UÇAK MENÜSÜ  * * * * * * *\n"
		<<"*   1 - YENÝ UÇUÞ KAYDI                 *\n"
		<<"*   2 - UÇUÞ DÜZENLEME                  *\n"
		<<"*   3 - UÇUÞ SÝLME                      *\n"
		<<"*   0 - ÜST MENÜYE DÖN                  *\n"
		<<"* * * * * * * * * * * * * * * * * * * * *\n";
	int islem=0,sayimi=1;
	char character[2];
	for(;sayimi==1;){
		cout<<"Yapmak istediðiniz iþlem: ";
		cin>>character;
		for(sayimi=0,islem=0;islem<2;islem++)
		{
			if(character[islem]!='\0')
			{
					if(!isdigit(character[islem]))
				{
					sayimi=1;
					break;
				}
			}
		}
		islem=atoi(character);
		if(sayimi==1){
			cout<<"Geçersiz karakter!\n";
		}
		
	}
	return islem;
}
int biletMenu()
{
	cout<<"* * * * * * *  BÝLET MENÜSÜ * * * * * * *\n"
		<<"*   1 - YENÝ BÝLET SATIÞI               *\n"
		<<"*   2 - BÝLET DEÐÝÞTÝRME                *\n"
		<<"*   3 - BÝLET ÝPTAL ETME                *\n"
		<<"*   0 - ÜST MENÜYE DÖN                  *\n"
		<<"* * * * * * * * * * * * * * * * * * * * *\n";
	int islem=0,sayimi=1;
	char character[2];
	for(;sayimi==1;){
		cout<<"Yapmak istediðiniz iþlem: ";
		cin>>character;
		for(sayimi=0,islem=0;islem<2;islem++)
		{
			if(character[islem]!='\0')
			{
					if(!isdigit(character[islem]))
				{
					sayimi=1;
					break;
				}
			}
		}
		islem=atoi(character);
		if(sayimi==1){
			cout<<"Geçersiz karakter!\n";
		}
		
	}
	return islem;
}
int ucusListeMenu()
{
	cout<<"* * * * * UÇUÞ LÝSTELERÝ MENÜSÜ * * * * *\n"
		<<"*   1 - SEFER LÝSTESÝ                   *\n"
		<<"*   2 - TÜM YOLCULAR'IN LÝSTESÝ         *\n"
		<<"*   3 - UÇUÞLARA GÖRE YOLCU LÝSTESÝ     *\n"
		<<"*   0 - ÜST MENÜYE DÖN                  *\n"
		<<"* * * * * * * * * * * * * * * * * * * * *\n";
	int islem=0,sayimi=1;
	char character[2];
	for(;sayimi==1;){
		cout<<"Yapmak istediðiniz iþlem: ";
		cin>>character;
		for(sayimi=0,islem=0;islem<2;islem++)
		{
			if(character[islem]!='\0')
			{
					if(!isdigit(character[islem]))
				{
					sayimi=1;
					break;
				}
			}
		}
		islem=atoi(character);
		if(sayimi==1){
			cout<<"Geçersiz karakter!\n";
		}
		
	}
	return islem;
}

int musteriMenu()
{
	cout<<"* * * *  MüÞTERÝ DÜZENLEME MENÜSÜ * * * *\n"
		<<"*   1 - UÇUÞ GÜNCELLEME                 *\n"
		<<"*   2 - ÝSÝM-SOYÝSÝM GÜNCELLEME         *\n"
		<<"*   3 - KOLTUK GÜNCELLEME               *\n"
		<<"*   0 - ÜST MENÜYE DÖN                  *\n"
		<<"* * * * * * * * * * * * * * * * * * * * *\n";
	int islem=0,sayimi=1;
	char character[2];
	string a;
	getline(cin,a);
	a.copy(character,1);
	for(;sayimi==1;){
		cout<<"Yapmak istediðiniz iþlem: ";
		cin>>character;
		for(sayimi=0,islem=0;islem<2;islem++)
		{
			if(character[islem]!='\0')
			{
					if(!isdigit(character[islem]))
				{
					sayimi=1;
					break;
				}
			}
		}
		islem=atoi(character);
		if(sayimi==1){
			cout<<"Geçersiz karakter!\n";
		}
		
	}
	return islem;
}
