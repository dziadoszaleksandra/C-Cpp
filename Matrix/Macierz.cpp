#include "Vector.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {

    try
    {
        cout << "TEST VECTOR" << endl;

        Vector v1;
        cout << "v1 (domyslny 2-elementowy) = " << v1 << endl;

        Vector v2( 3, 1 );
        cout << "v2 = " << v2 << endl;

        Vector v3( 3, 2 );
        Vector v4( v3 );
        cout << "v4 (kopiowany z v3) = " << v4 << endl;

        v2 = v4;
        cout << "v2 = v4 -> v2 = " << v2 << endl;

        v1 = v2 + v3;
        cout << "v2 + v3 = " << v1 << endl;

        //wczytywanie 
        cout << "Podaj " << v3.getDim() << " elementy wektora v3: ";
        cin >> v3;
        cout << "v3 = " << v3 << endl;

        //operacje matematyczne
        v1 = v2 + v3 - 1.0;
        cout << "v1 = v2 + v3 - 1 = " << v1 << endl;
        cout << "Iloczyn skalarny v1 * v3 = " << v1 * v3 << endl;

        cout << "\nTEST MATRIX" << endl;

        Matrix m1;
        cout << "m1 (domyslna) = " << m1 << endl;

        Matrix m2( 2, 3, 2 );
        Matrix m3( 3, 2, 1 );
        Matrix m4( m2 );
        cout << "m2 = \n" << m2 << endl;
        cout << "m3 = \n" << m3 << endl;
        cout << "m4 (kopiowany z m2) = \n" << m4 << endl;

        Matrix m5 = m2;
        cout << "m5 = m2 -> m5 = \n" << m5 << endl;

        //wczytywanie
        cout << "Podaj elementy macierzy 2x3 (m2): ";
        cin >> m2;
        cout << "m2 po wczytaniu = \n" << m2 << endl;

        //operacje matematyczne
        Matrix m6 = m2 * m3;
        cout << "m2 * m3 = \n" << m6 << endl;

        Vector v5( 2, 1 );
        Vector v6 = m3 * v5;
        cout << "m3 * v5 = " << v6 << endl;

        //zmiana pojedynczego elementu
        m2[0][1] = 7;
        cout << "m2 po zmianie m2[0][1] = 7:\n" << m2 << endl;

        //porownnanie macierzy
        if( m1 == m4 )
            cout << "m1 == m4" << endl;
        else
            cout << "m1 != m4" << endl;

        cout << "\nkoniec testu" << endl;
    }
    catch( const VectorException& e )
    {
        cerr << "Wyjatek VectorException: " << e.getReason();
    }
    catch( const MatrixException& e )
    {
        cerr << "Wyjatek MatrixException: " << e.getReason();
    }
    //nieznany, dowolony wyjatek
    catch( ... )
    {
        cerr << "Nieznany wyjatek!" << endl;
    }

    return 0;
}
