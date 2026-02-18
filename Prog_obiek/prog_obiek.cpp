/*
#include <iostream>
using namespace std;

#include "data.h"
#include "Time.h"
int main()
{

    DateTime dt1;
    cout << "dt1= " << dt1 << endl;
    DateTime dt2( 14, 10, 2025 );




    Date d2( 1, 11, 2025 );//konstruktor z parametrami

    Date d1;//zainicjowany domyslnie na 1 1 1990//konstruktor domyslny
    d1.setDate( 1, 10, 2025 );

    Date d3(d2);



    cout << "d1= "; d1.printDate( );
    cout << endl;

    d1.setDay( 7 );
    cout << "d1= "; d1.printDate( );
    cout << endl;


    cout << "podaj date w formacie dd//mmm//yyyy";
    d1.readDate( );
    cout << "d1= "; d1.printDate(  );
    cout << endl; 






    Time t2( 1, 11, 20 );//konstruktor z parametrami

    Time t1;
    t1.setTime( 1, 10, 20 );


   // Time t4( t2 );//konstruktor kopiujacy


    cout << "t1= "; t1.printTime();
    cout << endl;

    t1.setSec( 7 );
    cout << "t1= "; t1.printTime();
    cout << endl;


    cout << "podaj godzine w formacie hh:mm:ss";
    t1.readTime();
    cout << "t1= "; t1.printTime();
    cout << endl;



    return 0;
} */

#include <iostream>
#include "data.h"
#include "Time.h"
#include "DateTime.h"

int main()
{
    DateTime td1;
    DateTime td2( 16, 59, 30, 25, 10, 2021 );
    DateTime td3( td2 );

    std::cout << "td1 = " << td1 << std::endl;
    std::cout << "td2 = " << td2 << std::endl;
    std::cout << "td3 = " << td3 << std::endl;

    std::cout << "Podaj czas i date hh:mm:ss DD/MM/YYYY : ";
    std::cin >> td1;
    std::cout << "td1 = " << td1 << std::endl;
    td2 = td1;
    std::cout << "td2 = " << td2 << std::endl;

    return 0;
}
