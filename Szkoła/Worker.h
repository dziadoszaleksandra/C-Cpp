#pragma once
#include "Person.h"

#define KOSZT_UZYSKANIA_PRZYCHODU 111.25
#define PROCENT_PODATKU 0.18
#define KWOTA_WOLNA 46.34

class Worker : public Person
{
public:
	Worker( string name = "", int age = 0, double salary = 0.0, int years = 0 );
	Worker( const Worker& w );
	virtual ~Worker();

	void setSalary( double newSalary );
	double getSalary() const;

	void setYears( int newYears );
	int getYears() const;

	double calculateTax( double brutto, double kup );
	double calcBonusPercent( int lata );

	virtual void printInfo() = 0;
	virtual void calcSalary() = 0;

protected:
	double mSalary;
	int    mYears;
};

//===============inline==================
inline void Worker::setSalary( double newSalary )
{
	mSalary = newSalary;
}

inline double Worker::getSalary() const
{
	return mSalary;
}

inline void Worker::setYears( int newYears )
{
	mYears = newYears;
}

inline int Worker::getYears() const
{
	return mYears;
}