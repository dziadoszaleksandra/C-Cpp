#pragma once
#include "CTime.h"
#include "Date.h"
#include "testDll.h"

class TESTDLL_API DateTime : public Time, public Date
{
public:
    DateTime();
    DateTime( int nHour, int nMinute, int nSecond, int nDay, int nMonth, int nYear );
    DateTime( const DateTime& td );
    DateTime& operator=( const DateTime& td );

    void setDateTime( int nHour, int nMinute, int nSecond, int nDay, int nMonth, int nYear );

    friend TESTDLL_API std::istream& operator>>( std::istream& in, DateTime& td );
    friend TESTDLL_API std::ostream& operator<<( std::ostream& out, const DateTime& td );
};