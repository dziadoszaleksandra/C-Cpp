#pragma once
#include <iostream>

class Time
{
public:
    Time(); // konstruktor domyœlny
    Time( int nHour, int nMinute, int nSecond );
    Time( const Time& t );
    Time& operator=( const Time& t ); // t1 = t2;

public:
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    int setHour( int nHour );
    int setMinute( int nMinute );
    int setSecond( int nSecond );
    int setTime( int nHour, int nMinute, int nSecond );

    friend std::istream& operator>>( std::istream& in, Time& t );
    friend std::ostream& operator<<( std::ostream& out, const Time& t );

private:
    int m_nHour;
    int m_nMinute;
    int m_nSecond;
};
