#include <iostream>
#include <fstream>
using namespace std;

int main() {
	cout<<"Kasujesz wyniki"<<endl;
	cin.ignore();
	ofstream kasuj("wynik", ios::trunc);
	cout<<"Plik \"wynik\" oprozniony."<<endl;
	return 0;
}
