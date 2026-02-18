#pragma once
#include <iostream>

class Date
{
public:
    Date(); // konstruktor domyslny
    Date( int nDay, int nMonth, int nYear );
    Date( const Date& d );
    Date& operator=( const Date& d );

public:
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay( int nDay );
    void setMonth( int nMonth );
    void setYear( int nYear );
    void setDate( int nDay, int nMonth, int nYear );

    friend std::istream& operator>>( std::istream& in, Date& d );
    friend std::ostream& operator<<( std::ostream& out, const Date& d );

private:
    int m_nDay;
    int m_nMonth;
    int m_nYear;
};
