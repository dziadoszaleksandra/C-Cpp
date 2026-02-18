#pragma once

#include "Time.h"
#include "data.h"
class DateTime; public Date,public Time
{
public:
	DateTime( int D = 1, int M = 1, int Y = 1990, int h, int m = 0, int s = 0 );
	DateTime( const DataTime& dt );

	DateTime& operator= ( const DateTime& dt );

	friend istream& operator >> ( istream& in, DateTime dt );
	friend istream& operator << ( ostream& out, const DateTime& dt );

	void setDateTime( int D, int M, int Y, int h, int m, int s );


};



/
DateTime::DateTime( int D, int M, int Y, int h, int m, int s ) :Date( D, M, Y ), Time( h, m, s );
{
	
	
	}
DateTime( const DataTime& dt ) :Date( (Date&)dt ), Time( (const Time&)dt ); {

	}

DateTime& DateTime:: operator = ( const DateTime& dt ) {
	(Date&)*this = (Date&)dt;

	*(Time*)this = (const Time&)dt;
	return in;
	}

istream& operator >> ( istream& in, DateTime dt ) {
	in >> (Date&)dt;
	in >> (Time&)dt;
	return in;

	}
istream& operator << ( ostream& out, const DateTime& dt ) {
	out << (Date&)dt << "---" << (const Time&)dt;
	return out;

	}

void setDateTime( int D, int M, int Y, int h, int m, int s ) {

	}




*/