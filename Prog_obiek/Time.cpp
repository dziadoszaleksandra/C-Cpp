#include "Time.h"
#include <iostream>

Time::Time()
{
    setTime( 0, 0, 0 );
}

Time::Time( int nHour, int nMinute, int nSecond )
{
    setTime( nHour, nMinute, nSecond );
}

Time::Time( const Time& t )
{
    *this = t;
}

Time& Time::operator=( const Time& t )
{
    setTime( t.m_nHour, t.m_nMinute, t.m_nSecond );
    return *this;
}

int Time::getHour() const
{
    return this->m_nHour;
}

int Time::getMinute() const
{
    return this->m_nMinute;
}

int Time::getSecond() const
{
    return this->m_nSecond;
}

int Time::setHour( int nHour )
{
    if(!(nHour >= 0 && nHour < 24))
        return 1;
    this->m_nHour = nHour;
    return 0;
}

int Time::setMinute( int nMinute )
{
    if(!(nMinute >= 0 && nMinute < 60))
        return 1;
    this->m_nMinute = nMinute;
    return 0;
}

int Time::setSecond( int nSecond )
{
    if(!(nSecond >= 0 && nSecond < 60))
        return 1;
    this->m_nSecond = nSecond;
    return 0;
}

int Time::setTime( int nHour, int nMinute, int nSecond )
{
    int t1 = this->m_nHour;

    if(setHour( nHour ))
        return 1;

    int t2 = this->m_nMinute;

    if(setMinute( nMinute ))
    {
        setHour( t1 );
        return 1;
    }

    if(setSecond( nSecond ))
    {
        setHour( t1 );
        setMinute( t2 );
        return 1;
    }
    return 0;
}

std::istream& operator>>( std::istream& in, Time& t )
{
    int temp;
    int t1 = t.getHour();
    int t2 = t.getMinute();
    char c;

    in >> temp >> c; // c == ':', c == '-'
    if(c != ':' && c != '-')
    {
        std::cerr << "Niepoprawny format danych po godzinach, czas nie zostanie ustawiony" << std::endl;
        return in;
    }
    if(t.setHour( temp ))
    {
        std::cerr << "Niepoprawna godzina, czas nie zostanie ustawiony" << std::endl;
        return in;
    }

    in >> temp >> c; // c == ':', c == '-'
    if(c != ':' && c != '-')
    {
        std::cerr << "Niepoprawny format danych po minutach, czas nie zostanie ustawiony" << std::endl;
        t.setHour( t1 );
        return in;
    }
    if(t.setMinute( temp ))
    {
        std::cerr << "Niepoprawna minuta, czas nie zostanie ustawiony" << std::endl;
        t.setHour( t1 );
        return in;
    }

    in >> temp;
    if(t.setSecond( temp ))
    {
        std::cerr << "Niepoprawna sekunda, czas nie zostanie ustawiony" << std::endl;
        t.setHour( t1 );
        t.setMinute( t2 );
        return in;
    }

    return in;
}

std::ostream& operator<<( std::ostream& out, const Time& t )
{
    int n;
    if((n = t.getHour()) < 10)
        out << 0;
    out << n << ':';
    if((n = t.getMinute()) < 10)
        out << 0;
    out << n << ':';
    if((n = t.getSecond()) < 10)
        out << 0;
    out << n;

    return out;
}
