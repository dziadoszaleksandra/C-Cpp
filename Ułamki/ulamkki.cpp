#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
    Rational u1( 1, 3 ); // pierwszy ulamek 1/3
    Rational u2;       // drugi ulamek od uzytkownika

    cout << "Podaj drugi ulamek (licznik i mianownik, oddzielone spacja): ";
    cin >> u2;


    //operatory arytm
    Rational suma = u1 + u2;
    Rational roznica = u1 - u2;
    Rational iloczyn = u1 * u2;
    Rational iloraz = u1 / u2;

    //wyniki
    cout << "\nWyniki:\n";
    cout << "Suma:      " << suma << " = " << suma.Value() << '\n';
    cout << "Roznica:   " << roznica << " = " << roznica.Value() << '\n';
    cout << "Iloczyn:   " << iloczyn << " = " << iloczyn.Value() << '\n';
    cout << "Iloraz:    " << iloraz << " = " << iloraz.Value() << '\n';

    return 0;
}


