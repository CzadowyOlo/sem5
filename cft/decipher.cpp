#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <time.h>


using namespace std;
int main()
{
FILE *we, *wy;
char znak;       //znak odczytany z pliku
//Przed uruchomieniem programu nalezy utworzyc 2 pliki - 1. z tekstem zaszyfrowanym, 2. pusty na t.odszyfrowany
char plik_jawny[20];  //nazwa pliku z tekstem jawnym
char plik_zaszyfrowany[20];  //nazwa pliku z tekstem zaszyfrownym
cout<<"Podaj nazwe pliku zawierajacego tekst zaszyfrowany: ";
cin>>plik_zaszyfrowany;
cout<<"Podaj nazwe pliku,w ktorym zapisany ma byc tekst odszyfrowany: " ;
cin>>plik_jawny;
 
if((we=fopen(plik_zaszyfrowany,"rt"))!=NULL)    //otwieranie pliku 1. do odczytu
{
if((wy=fopen(plik_jawny,"wt"))!=NULL)  //otwieranie pliku 2. do zapisu
{
while((znak=getc(we))!=EOF)   //pobieranie znaku z pliku 1. tak dlugo az nie nastapi znak konca pliku
//Kazdy odczytywany znak wg kodow ASCII jest przydzielany do 3 grup duze litery, male litery, cyfry
{
if ((znak>=65)&&(znak<=90))
{
znak-=65;
znak-=13;
if (znak<0)
znak=26-fabs(znak);
znak+=65;
putc(znak,wy);
}
else if ((znak>=97)&&(znak<=122))
{
znak-=97;
znak-=13;
if (znak<0)
znak=26-fabs(znak);
znak+=97;
putc(znak,wy);
}
else if ((znak>=48)&&(znak<=57))
{
znak-=48;
znak-=3;
if (znak<0)
znak=10-fabs(znak);
znak+=48;
putc(znak,wy);
}
}
fclose(wy);
}
fclose(we);
}
cout<<"Deszyfrowanie zostalo zakonczone";
return 0;
}