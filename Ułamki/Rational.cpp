#include "Rational.h"
using namespace std;

//konstruktor z wartosciami domyslnymi
Rational::Rational( int numerator, int denominator )
{
    SetRational( numerator, denominator ); // ustawia licznik i mianownik i skraca
}

//konstruktor kopiujacy
Rational::Rational( const Rational& u )
{
    *this = u;
}

//wirtualny destruktor
Rational::~Rational()
{
    //pusty
}

//operator przypisania
Rational& Rational::operator=( const Rational& u )
{
    SetRational( u.GetNumerat(), u.GetDenominat() );
    return *this;
}

//ustawienie ulamka, licznik i mianownik w tym samym momencie
void Rational::SetRational( int num, int denum )
{
    SetNumerat( num );
    SetDenominat( denum );
    shorten(); //skracanie
}

//operator wczytywania we
istream& operator>>( istream& in, Rational& u )
{
    int num, denum;
    in >> num >> denum; // wczytujemy dwie liczby rozdzielone spacja
    u.SetRational( num, denum );
    return in;
}

//operator wypisywania
ostream& operator<<( ostream& out, const Rational& u )
{
    out << u.GetNumerat() << '/' << u.GetDenominat();
    return out;
}

//operator dodawania
Rational operator+( const Rational& u1, const Rational& u2 )
{
    Rational result(
        u1.mNumerator * u2.mDenominator + u2.mNumerator * u1.mDenominator,
        u1.mDenominator * u2.mDenominator
    );
    result.shorten(); //skracamy wynik
    return result;
}

//operator odejmowania
Rational operator-( const Rational& u1, const Rational& u2 )
{
    Rational result(
        u1.mNumerator * u2.mDenominator - u2.mNumerator * u1.mDenominator,
        u1.mDenominator * u2.mDenominator
    );
    result.shorten();
    return result;
}

//operator mnozenia
Rational operator*( const Rational& u1, const Rational& u2 )
{
    Rational result(
        u1.mNumerator * u2.mNumerator,
        u1.mDenominator * u2.mDenominator
    );
    result.shorten();
    return result;
}

//operator dzielenia
Rational operator/( const Rational& u1, const Rational& u2 )
{
    Rational result(
        u1.mNumerator * u2.mDenominator,
        u1.mDenominator * u2.mNumerator
    );
    result.shorten();
    return result;
}

//operatory przypisania z dzialaniem
Rational& Rational::operator+=( const Rational& u ) { *this = *this + u; return *this; }
Rational& Rational::operator-=( const Rational& u ) { *this = *this - u; return *this; }
Rational& Rational::operator*=( const Rational& u ) { *this = *this * u; return *this; }
Rational& Rational::operator/=( const Rational& u ) { *this = *this / u; return *this; }

//zwraca wart ulamka jako double
double Rational::Value() const
{
    return (double)mNumerator / mDenominator; //mozna uzyc static -> return static_cast<double>(mNumerator) / mDenominator;
}

//NWP
int Rational::nwp( int a, int b )
{
    //abs to wartosc bezwzgledna
    a = abs( a );
    b = abs( b );
    if( a == 0 ) return b;
    if( b == 0 ) return a;

    while( b != 0 )
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

//skracanie 
void Rational::shorten()
{
    //jesli licznik to 0 to 0/1
    if( mNumerator == 0 )
    {
        mDenominator = 1;
        return;
    }

    int t = nwp( mNumerator, mDenominator );
    mNumerator /= t;
    mDenominator /= t;

    //jak jest mianownik minus to przenosimy znak do licznika 
    if( mDenominator < 0 )
    {
        mNumerator = -mNumerator;
        mDenominator = -mDenominator;
    }
}
