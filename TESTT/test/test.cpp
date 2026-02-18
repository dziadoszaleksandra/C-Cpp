#include <iostream>
#include "testDll.h"
#include "Date.h"     
#include "CTime.h"    
#include "DateTime.h"

using namespace std;

int main()
{
    DateTime td1;
    // parametry: godzina, minuta, sekunda, dzien, miesiac, rok
    DateTime td2( 16, 59, 30, 25, 10, 2021 );
    DateTime td3( td2 );

    cout << "td1 = " << td1 << endl;
    cout << "td2 = " << td2 << endl;
    cout << "td3 = " << td3 << endl;

    cout << "Podaj czas i date hh:mm:ss DD/MM/YYYY : ";

    if( cin >> td1 ) {
        cout << "td1 = " << td1 << endl;
        td2 = td1;
        cout << "td2 = " << td2 << endl;
    }
    else {
        cout << "Blad wczytywania" << endl;
    }

    return 0;
}