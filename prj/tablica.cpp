#include"tablica.hh"

using namespace std;

/*!
 * \file
 * \brief Definicje funkcji klasy tablica
 *
 */


/*! \brief Sprawdza czy tablice sa sobie rowne
 * 
 * Operator porownuje kazdy element tablicy i zwraca wartosc true jesli wszystkie elementy sa rowne albo false gdy nie sa.
 */
bool tablica::operator ==(tablica &tab2)
  {
	for(int i=0; i<ilosc; i++){
		//cout<<"\nElementy: "<<tab2.tab_1[i]<<"   "<<tab_1[i]<<endl;
    	if(tab2.tab_1[i] == tab_1[i]) {
		//cout<<"Sa rowne"<<endl;
			}   
    	else {
		//cout<<"Nie sa rowne"<<endl;
    	return false; 
			}
	}
return true;
  }

/*! \brief Dodaje elementy dwoch tablic
 * 
 * Operator dodaje poszczegolne elementy dwoch tablic do siebie i zwraca tablice wynik.
 */
tablica& tablica::operator+ (tablica & tab2){
	static tablica wynik;
	for(int i=0; i<ilosc; i++) { wynik.tab_1[i]=tab_1[i]+tab2.tab_1[i]; }
	return wynik;	
	}

/*! \brief Przypisuje kazdy element tablicy do tab2 podanej jako argument funkcji
 * 
 */
tablica& tablica::operator= (tablica & tab2) {
	for(int i=0; i<ilosc; i++) { tab_1[i]=tab2.tab_1[i]; }
	}

/*! \brief Czyta ile jest elementow tablicy
 *
 * Czyta pierwszy znak z pliku i sprawdza czy nie jest mniejszy od 0. Jesli tak - program konczy dzialanie.
 */
int tablica::elementy(const char * name) {
	fstream plik(name);
	plik>>ilosc_pocz;
	if(ilosc_pocz>=0) {
		//cout<< "\nLiczba elementow tablicy: "<< ilosc_pocz <<endl;
		return ilosc_pocz;
		}
	else { 
		cout<< "BLAD! Liczba elementow tablicy "<< ilosc_pocz << " jest ujemna!"<<endl;
		exit(1);
		}
}

/*! \brief Zamienia element nr i oraz nr j miejscami
 *
 * Pomoc - pomocnicza zmienna
 */
void tablica::zamien_elementy(int i, int j) {
	int pomoc=tab_1[i];
	tab_1[i]=tab_1[j];
	tab_1[j]=pomoc;
	}

/*! \brief Odwraca kolejnosc tablicy
 *
 * Element ostatni staje sie pierwszym, przedostatni drugim itd.
 */
void tablica::odwroc_kolejnosc() {
	int poczatek = 0;
	int koniec = ilosc-1;

	while (poczatek < koniec) {
		int pomoc = tab_1[poczatek];
		tab_1[poczatek]  = tab_1[koniec];
		tab_1[koniec] = pomoc;
	poczatek++;
	koniec--;
	}
}

/*! \brief Dodaje element podany jako argument (e) funkcji
 * 
 * Tworzona jest tablica-bufor, przpisywana tablica na bufor, powiększana, przepisywana z buforu na tablice
 * a nastepnie nastepuje wpisanie nowego elemnetu na tablice i zwalnianie buforu.
 */
void tablica::dodaj_element(int e) {
	int *bufor = new int [ilosc]; 		
	for(int i=0; i<ilosc; i++)
        bufor[i]=tab_1[i];  			
		tab_1 = new int[ilosc+1]; 		
	for(int i=0; i<ilosc; i++)
        tab_1[i]=bufor[i];  			
	tab_1[ilosc]=e; 					
	delete [] bufor; 					
	ilosc++;
	}

/*!
 * \brief Dodaje elementy tablicy podanej jako argument funkcji (tab)
 *
 * Funkcja wykorzystuje metode dodaj_element
 */
void tablica::dodaj_elementy(tablica &tab) {	
	for (int i=0; i<ilosc_pocz; i++) {
		tablica::dodaj_element(tab.tab_1[i]);
		}
	}

/*!
 * \brief Mnozy kazdy element tablicy razy 2
 *
 * Funkcja podwaja kazdy z elementow tablicy tab_1 i zapisuje wynik w tej samej tablicy.
 *
 * \param tab_1[] - tablica, ktorej elementy sa wymnazane przez 2
 * \param bufor - tablica, do ktorej zapisywana jest kopia tab_1
 * \param ilosc - zmienna okreslajaca wielkosc tablicy
 */
void tablica::mnozenie() {
	int *bufor=new int [ilosc];
	for(int i=0; i<ilosc; i++)
        bufor[i]=tab_1[i];
	for(int i=0; i<ilosc; i++) { tab_1[i]=2*bufor[i]; }
	}

/*!
 * \brief Czyta dane z pliku i zapisuje w tablicy.
 *
 * Funkcja czyta dane z pliku, ignorujac pierwszy element (jest to liczba okreslajaca ilosc elementow tablicy), 
 * wpisuje je w poszczegolne elementy tablicy tab.
 *
 * \param tab_1[] - tablica, do ktorej zapisywane sa kolejne liczby z pliku
 * \param ilosc - zmienna okreslajaca wielkosc tablicy
 * \param nazwa - zmienna okreslajaca nazwe pliku, z ktorego czytane sa liczby
 */
void tablica::wypelnij() {
	plik.open(nazwa);
	plik.ignore(1000,'\n');
	for (int i=0; i<ilosc; i++)
	plik>>tab_1[i];
	plik.close();
	}

/*!
 * \brief Wyswietla tablice
 *
 * Funkcja wyswietla tablice wczytana przez funkcje wypelnij.
 *
 * \param tab_1[] - tablica, ktora ma zostac wyswietlona
 * \param ilosc - zmienna okreslajaca wielkosc tablicy
 */
void tablica::wyswietl() {
	for(int i=0; i<ilosc; i++) { cout<<tab_1[i]<<" "; }
	cout<<endl;
	}

