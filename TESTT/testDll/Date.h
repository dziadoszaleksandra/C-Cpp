#pragma once
#include <iostream>
#include "testDll.h"

class TESTDLL_API Date
{
public:
    Date(); // konstruktor domyslny
    Date( int nDay, int nMonth, int nYear );
    Date( const Date& d ); // konstruktor kopiujacy
    Date& operator=( const Date& d ); // operator przypisania

public:
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay( int nDay );
    void setMonth( int nMonth );
    void setYear( int nYear );
    void setDate( int nDay, int nMonth, int nYear );

    friend TESTDLL_API std::istream& operator>>( std::istream& in, Date& d );
    friend TESTDLL_API std::ostream& operator<<( std::ostream& out, const Date& d );

private:
    int m_nDay;
    int m_nMonth;
    int m_nYear;
};