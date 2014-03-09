#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <cstdlib>
#include "tablica.hh"
#include "zegar.hh"
using namespace std;

/*! \file Glowny plik programu
 *
 * Wywolanie funkcji main testuje wszystkie funkcje i przeciazenia zawarte w programie
 */
int main() {

	tablica pierwsza("tablica");
pierwsza.wypelnij();
cout<<"\nPIERWSZA: "<<endl;
pierwsza.wyswietl();

	tablica druga("tablica2");
druga.wypelnij();
cout<<"\nDRUGA: "<<endl;	
druga.wyswietl();

cout<<"\nczy sa rowne? (0-nie, 1-tak): ";
int rownosc;
rownosc=pierwsza==druga;
cout<<rownosc<<endl;

cout<<"\npierwsza=druga: "<<endl;
pierwsza=druga;
pierwsza.wyswietl();
druga.wyswietl();

cout<<"\nczy sa rowne? (0-nie, 1-tak): ";
rownosc=pierwsza==druga;
cout<<rownosc<<endl;

cout<<"\nwynik=druga+pierwsza: "<<endl;
tablica wynik;
wynik=druga+pierwsza;
wynik.wyswietl();

cout<<"\npierwsza.odwroc_kolejnosc(): "<<endl;
pierwsza.odwroc_kolejnosc();
pierwsza.wyswietl();

////////////////////
	zegar watch;
	watch.start();
////////////////////
pierwsza.mnozenie();
cout<<"\npierwsza.mnozenie():"<<endl;
pierwsza.wyswietl();
//////////////////////
	watch.stop();
	watch.wyswietl();
//////////////////////

cout<<"\ndruga.zamien_elementy(1, 2): "<<endl;
druga.zamien_elementy(1, 2);
druga.wyswietl();

cout<<"\npierwsza.dodaj_elementy(druga): "<<endl;
pierwsza.dodaj_elementy(druga);
pierwsza.wyswietl();

cout<<"\ndruga.dodaj_element(222): "<<endl;
druga.dodaj_element(222);
druga.wyswietl();

watch.zapisz_wynik();

return 0;
}
