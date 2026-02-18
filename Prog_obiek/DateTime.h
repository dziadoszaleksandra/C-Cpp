#pragma once
#include "Time.h"
#include "data.h"

class DateTime : public Time, public Date
{
public:
    DateTime();
    DateTime( int nHour, int nMinute, int nSecond, int nDay, int nMonth, int nYear );
    DateTime( const DateTime& td );
    DateTime& operator=( const DateTime& td );

    void setDateTime( int nHour, int nMinute, int nSecond, int nDay, int nMonth, int nYear );

    friend std::istream& operator>>( std::istream& in, DateTime& td );
    friend std::ostream& operator<<( std::ostream& out, const DateTime& td );
};
