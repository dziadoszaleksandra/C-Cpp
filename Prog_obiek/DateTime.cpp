#include "DateTime.h"
#include <iostream>

DateTime::DateTime() : Time(), Date() {}

DateTime::DateTime( int nHour, int nMinute, int nSecond, int nDay, int nMonth, int nYear )
    : Time( nHour, nMinute, nSecond ), Date( nDay, nMonth, nYear ) {
}

DateTime::DateTime( const DateTime& td ) : Time( (const Time&)td ), Date( (const Date&)td ) {}

DateTime& DateTime::operator=( const DateTime& td )
{
    (Time&)*this = (const Time&)td;
    (Date&)*this = (const Date&)td;
    return *this;
}

std::istream& operator>>( std::istream& in, DateTime& td )
{
    in >> (Time&)td;
    in >> (Date&)td;
    return in;
}

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
