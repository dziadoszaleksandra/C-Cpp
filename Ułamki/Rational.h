#pragma once
#include <iostream>
#include <cmath>
using namespace std;


class Rational
{
public:
    Rational( int numerator = 0, int denominator = 1 );   //konstruktor domyslny (nuemrator = 0, denominator = 1)
    Rational( const Rational& u ); //konstruktor kopiujacy

    virtual ~Rational(); //wirtualny destruktor

    Rational& operator=( const Rational& u ); //operator przypisania

    //settery i gettery
    void SetNumerat( int Num );
    void SetDenominat( int Denum );
    int GetNumerat() const;
    int GetDenominat() const;

    void SetRational( int num, int denum );

    //operatory we/wy
    friend istream& operator>>( istream& in, Rational& u );
    friend ostream& operator<<( ostream& out, const Rational& u );

    //operatory atrytmetyczne
    friend Rational operator + ( const Rational& u1, const Rational& u2 );
    friend Rational operator-( const Rational& u1, const Rational& u2 );
    friend Rational operator*( const Rational& u1, const Rational& u2 );
    friend Rational operator/( const Rational& u1, const Rational& u2 );

    //operatory z przypisaniem
    Rational& operator+=( const Rational& u );
    Rational& operator-=( const Rational& u );
    Rational& operator*=( const Rational& u );
    Rational& operator/=( const Rational& u );

    double Value() const;//zwrca wart ulamka jako double

private:
    int mNumerator; //licznik
    int mDenominator; // mianownik

    int nwp( int a, int b ); //nwp
    void shorten(); //skracanie
};


//------------------------------
//inline settery i gettery

inline int Rational::GetNumerat() const
{
    return mNumerator;
}

inline int Rational::GetDenominat() const
{
    return mDenominator;
}

inline void Rational::SetNumerat( int Num )
{
    mNumerator = Num;
}

inline void Rational::SetDenominat( int Denum )
{
    if( Denum == 0 )
    {
        Denum = 1; //jesli zero to ustawiamy 1
        cerr << "ERROR: Mianownik nie moze byc rowny 0!!!!\n";
    }
    mDenominator = Denum;
}
