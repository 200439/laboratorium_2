#include <iostream>
#include <fstream>
using namespace std;

/*! \file Program czyszczacy plik z zapisanymi czasami wykonania algorytmu
 *
 */

int main() {
	cout<<"Kasujesz wyniki"<<endl;
	cin.ignore();
	ofstream kasuj("wynik.csv", ios::trunc);
	cout<<"Plik \"wynik.csv\" oprozniony."<<endl;
	return 0;
}
