#ifndef TABLICA_HH
#define TABLICA_HH
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/*!
 * \file
 * \brief Definicja klasy tablica
 *
 */
class tablica {
	
	int ilosc;
	int ilosc_pocz;
	int *tab_1;	
	const char * nazwa;
	fstream plik;

	int elementy(const char * name);
	
	public:
	void wypelnij();
	void wyswietl();
	void mnozenie();
	void zamien_elementy(int i, int j);
	void odwroc_kolejnosc();	
	void dodaj_element(int e);
	void dodaj_elementy(tablica& tab);
	bool operator ==(tablica& Arg2);
	tablica& operator+(tablica& tab2);
	tablica& operator=(tablica& tab2);

	tablica(const char * name) {nazwa=name, ilosc_pocz=elementy(nazwa), ilosc=ilosc_pocz, tab_1=new int [ilosc];}
	tablica() {nazwa="tablica", ilosc_pocz=elementy(nazwa), ilosc=ilosc_pocz, tab_1=new int [ilosc];}
	~tablica() {delete [] tab_1;}
};

#endif
