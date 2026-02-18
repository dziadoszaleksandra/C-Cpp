#include <iostream>
#include "FifoInt.h"
using namespace std;

int main()
{
    try {
        FQueue queue( 5 );
        cout << "Dodanie elementow:" << endl;
        for( int i = 0; i < 5; i++ )
        {
            QINFO* p = new QINFO( i + 10 );
            queue.FQEnqueue( p );
        }
        queue.FQprint();

        cout << "Usuniecie 3 elementow:" << endl;

        cout << "Usuniete elementy: " << endl;
        for( int i = 0; i < 2; i++ )
        {
            QINFO* de = queue.FQDequeue();
            cout << *de;
            delete de;
        }
        cout << endl << "Kolejka po usunieciu elementow: " << endl;
        queue.FQprint();

        cout << "Dodaie 2 elementow:" << endl;
        for( int i = 20; i <= 21; i++ )
        {
            QINFO* p = new QINFO( i );
            queue.FQEnqueue( p );
        }
        queue.FQprint();

        queue.FQClear();
        queue.FQprint();

        cout << endl << "Dodanie 3 elementow:\n";
        for( int i = 100; i < 103; i++ )
        {
            QINFO* p = new QINFO( i );
            queue.FQEnqueue( p );
        }
        queue.FQprint();

        QINFO* p = queue.FQDequeue();
        cout << "Usuniecie elementu:" << endl;
        cout << *p;
        delete p;

        cout << endl << "Kolejka po usunieciu elementu: " << endl;
        queue.FQprint();
    }
    catch( FQueueException& e )
    {
        cerr << endl << e.getReason() << endl;
    }
    return 0;
}