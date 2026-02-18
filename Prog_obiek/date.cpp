#include "data.h"
#include <iostream>

Date::Date()
{
    setDate( 1, 1, 1901 );
}

Date::Date( int nDay, int nMonth, int nYear )
{
    setDate( nDay, nMonth, nYear );
}

Date::Date( const Date& d )
{
    *this = d;
}

Date& Date::operator=( const Date& d )
{
    setDate( d.getDay(), d.getMonth(), d.getYear() );
    return *this;
}

int Date::getDay() const { return this->m_nDay; }
int Date::getMonth() const { return this->m_nMonth; }
int Date::getYear() const { return this->m_nYear; }

void Date::setDay( int nDay ) { this->m_nDay = nDay; }
void Date::setMonth( int nMonth ) { this->m_nMonth = nMonth; }
void Date::setYear( int nYear ) { this->m_nYear = nYear; }
void Date::setDate( int nDay, int nMonth, int nYear )
{
    setMonth( nMonth );
    setDay( nDay );
    setYear( nYear );
}

std::istream& operator>>( std::istream& in, Date& d )
{
    int temp;
    char c;

    in >> temp >> c; d.setDay( temp );
    in >> temp >> c; d.setMonth( temp );
    in >> temp; d.setYear( temp );

    return in;
}

std::ostream& operator<<( std::ostream& out, const Date& d )
{
    out << d.getDay() << '/';
    out << d.getMonth() << '/';
    out << d.getYear();
    return out;
}
