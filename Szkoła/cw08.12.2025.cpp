#include <iostream>
using namespace std;

#include "SchoolGirl.h"
#include "SchoolBoy.h"
#include "Teacher.h"
#include "Admin.h"

void printAllPupils( Pupil** pupils, int pupilsNo );
void printAllWorkers( Worker** workers, int workersNo );
void sortByBrutto( Worker** workers, int workersNo );

int main()
{
    //uczniowie
    SchoolGirl g1( "Nowak Agnieszka", 17, "3A" );
    g1.setNote( POLSKI, 3.5 );
    g1.setNote( MATEMATYKA, 4.5 );
    g1.setNote( CHEMIA, 4 );
    g1.setNote( ANGIELSKI, 3.5 );
    g1.setNote( NIEMIECKI, 3.0 );

    SchoolGirl g2( "Sobota Paulina", 18, "4B" );
    g2.setNote( POLSKI, 3.5 );
    g2.setNote( INFORMATYKA, 4.5 );
    g2.setNote( FIZYKA, 4.5 );
    g2.setNote( NIEMIECKI, 4.0 );

    SchoolGirl g3( "Kozub Maria", 17, "3A" );
    g3.setNote( MATEMATYKA, 4.5 );
    g3.setNote( FIZYKA, 4 );
    g3.setNote( INFORMATYKA, 3.5 );

    SchoolBoy b1( "Kowalski Marcin", 17, "3B" );
    b1.setNote( INFORMATYKA, 5.0 );
    b1.setNote( FIZYKA, 5.0 );
    b1.setNote( ANGIELSKI, 4.0 );

    SchoolBoy b2( "Pawelek Krzysztof", 18, "4B" );
    b2.setNote( POLSKI, 5.0 );
    b2.setNote( MATEMATYKA, 3.5 );
    b2.setNote( NIEMIECKI, 4.0 );
    b2.setNote( ANGIELSKI, 4.0 );

    Pupil* pupils[] = { &g1, &g2, &g3, &b1, &b2 };
    cout << "---LISTA UCZNIOW---\n";
    printAllPupils( pupils, sizeof( pupils ) / sizeof( Pupil* ) );

    cout << "\n---PRACOWNICY (POSORTOWANI MALEJACO WG BRUTTO)---\n";

    //pracownicy
    Admin a1( "Wojcik Marek", 50, 4800, 12, REGULAR_SPEC );
    Admin a2( "Krawczyk Ewa", 42, 5300, 18, SENIOR_SPEC );

    Teacher t1( "Zielinski Adam", 47, 5100, 20, TS_FIZYKA, true, "2B" );
    Teacher t2( "Nowak Elzbieta", 33, 4400, 6, TS_POLSKI );
    Teacher t3( "Kaminski Robert", 55, 6000, 28, TS_MATEMATYKA, true, "4C" );
    Teacher t4( "Szymanska Ola", 29, 4100, 3, TS_CHEMIA );
    Teacher t5( "Wozniak Pawel", 45, 5400, 15, TS_INFORMATYKA );

    Worker* workers[] = { &a1, &a2, &t1, &t2, &t3, &t4, &t5 };
    int workersCount = sizeof( workers ) / sizeof( Worker* );

    //najpierw liczymy pensje zeby sortowanie mialo dobre dane
    for( int i = 0; i < workersCount; i++ )
    {
        workers[i]->calcSalary();
    }

    //sortujemy przeliczone wyplaty
    sortByBrutto( workers, workersCount );

    //wynik
    printAllWorkers( workers, workersCount );

    return 0;
}

//================implementacja==================

void printAllPupils( Pupil** pupils, int pupilsNo )
{
    for( int i = 0; i < pupilsNo; i++ )
    {
        //liczymy srednia przed wyswietleniem
        pupils[i]->calcAve();
        pupils[i]->printPupil();
        cout << endl;
    }
}

void sortByBrutto( Worker** workers, int workersNo )
{
    //proste sortowanie bablekowe wska
    for( int i = 0; i < workersNo - 1; i++ )
    {
        for( int j = i + 1; j < workersNo; j++ )
        {
            if( workers[j]->getSalary() > workers[i]->getSalary() )
                swap( workers[i], workers[j] );
        }
    }
}

void printAllWorkers( Worker** workers, int workersNo )
{
    for( int i = 0; i < workersNo; i++ )
    {
        workers[i]->printInfo();
        //pensja juz policzona wczesniej w main wiec tu tylko wyswietlamy
        cout << "Wynagrodzenie brutto: " << workers[i]->getSalary() << " PLN" << endl;
        cout << endl;
    }
}