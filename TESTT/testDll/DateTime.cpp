#include "pch.h"
#include "DateTime.h"
#include <iostream>

DateTime::DateTime() : Time(), Date() {}

// konstruktor z parametrami
DateTime::DateTime( int nHour, int nMinute, int nSecond, int nDay, int nMonth, int nYear )
    : Time( nHour, nMinute, nSecond ), Date( nDay, nMonth, nYear ) {
}

// konstruktor kopiujacy
DateTime::DateTime( const DateTime& td ) : Time( (const Time&)td ), Date( (const Date&)td ) {}

// operator przypisania
DateTime& DateTime::operator=( const DateTime& td )
{
    (Time&)*this = (const Time&)td;
    (Date&)*this = (const Date&)td;
    return *this;
}

// wczytywanie
std::istream& operator>>( std::istream& in, DateTime& td )
{
    in >> (Time&)td;
    in >> (Date&)td;
    return in;
}

// wypisywanie
std::ostream& operator<<( std::ostream& out, const DateTime& td )
{
    out << (const Time&)td << " -- " << (const Date&)td;
    return out;
}

void DateTime::setDateTime( int nHour, int nMinute, int nSecond, int nDay, int nMonth, int nYear )
{
    setTime( nHour, nMinute, nSecond );
    setDate( nDay, nMonth, nYear );
}