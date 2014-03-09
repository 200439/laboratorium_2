#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <cstdlib>

using namespace std;

/*! \file
 * \brief Plik z kodem programu liczacym statystyki czasu wykonania algorytmow
 */

/*! \brief Definicja klasy statystyki
 * 
 */
class statystyki {
	const char * nazwa;
	fstream plik;
	int zlicz();	
public:	
	int ilosc;
	int ilosc_max;
	int *tab_max, *tab_wyniki;
	
	void wyswietl();
	void wypelnij();
	long double srednia();
	long double suma();


	statystyki(const char * name) {nazwa=name, ilosc_max=9999, tab_max=new int [ilosc_max], ilosc=zlicz(), delete [] tab_max, tab_wyniki=new int [ilosc];}
	statystyki() {nazwa="wynik.csv", ilosc_max=9999, tab_max=new int [ilosc_max], ilosc=zlicz(), delete [] tab_max, tab_wyniki=new int [ilosc];}
	~statystyki() {delete [] tab_wyniki;}
};

/*! \brief Funkcja liczaca srednia
 */
long double statystyki::srednia() {
	long double wynik=0;
	
	for(int i=0; i<ilosc; i++)
		wynik+=tab_wyniki[i];
	wynik=wynik/ilosc;
	return wynik; }

/*! \brief Funkcja liczaca caly czas wykonania algorytmu
 */
long double statystyki::suma() {
	long double wynik=0;
	
	for(int i=0; i<ilosc; i++)
		wynik+=tab_wyniki[i];
		return wynik; }

/*! \brief Zlicza ilosc elementow tablicy
 *
 * Przepisuje elementy z pliku do tab_max, przy kazdym elemencie zwiekszajac licznik ilosc.
 */
int statystyki::zlicz() {
	plik.open(nazwa);
	ilosc=0;

	for (int i=0; i<ilosc_max; i++) {
		plik>>tab_max[i];
		ilosc=i;
	if(plik.eof()) {
		plik.close();
		return ilosc; }
	}
}

/*! \brief Przepisuje dane z pliku do tablicy tab_wyniki
 */
void statystyki::wypelnij() {
	plik.open(nazwa);
	for(int i=0; i<ilosc_max; i++) { plik>>tab_wyniki[i]; }
	plik.close();
	}

/*! \brief wyswietla elementy tablicy tab_wyniki
 */
void statystyki::wyswietl() {
	for(int i=0; i<ilosc; i++) { cout<<tab_wyniki[i]<<" "; }
	}

/*! \brief Funkcja glowna programu statystyki
 */
int main() {
	statystyki pierwsza;
pierwsza.wypelnij();
cout<<"Poszczegolne czasy wykonania programu: "<<endl;
pierwsza.wyswietl();
cout<<"\nSredni czas wykonania algorytmu: "<<pierwsza.srednia()<<" mikrosekund."<<endl;
cout<<"\nLaczny czas wykonania algorytmu: "<<pierwsza.suma()<<" mikrosekund"<<endl;

//cout<<"\npierwsza.ilosc_max "<<pierwsza.ilosc_max<<endl;
//cout<<"\npierwsza.ilosc "<<pierwsza.ilosc<<endl;


return 0;
}
