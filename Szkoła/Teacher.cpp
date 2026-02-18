#include "Teacher.h"
#include <iostream>

static const char* subjectToStr( TeachSubject s )
{
    switch( s )
    {
    case TS_POLSKI:       return "jezyk polski";
    case TS_MATEMATYKA:   return "matematyka";
    case TS_FIZYKA:       return "fizyka";
    case TS_CHEMIA:       return "chemia";
    case TS_INFORMATYKA:  return "informatyka";
    case TS_ANGIELSKI:    return "jezyk angielski";
    case TS_NIEMIECKI:    return "jezyk niemiecki";
    default:              return "nieznany przedmiot";
    }
}

Teacher::Teacher( string name, int age, double salary, int years,
    TeachSubject subject, bool tutor, string className ) : Worker( name, age, salary, years )
{
    setSubject( subject );
    setTutor( tutor );
    setClassName( className );
}

Teacher::Teacher( const Teacher& t )
{
    *this = t;
}

void Teacher::printInfo()
{
    cout << "Nauczyciel: " << getName()
        << " (wiek: " << getAge()
        << ", przedmiot: " << subjectToStr( mSubject )
        << ", staz: " << getYears() << " lat";

    if( isTutor() )
        cout << ", wychowawca klasy: " << mClassName;
    cout << ")" << endl;
}

void Teacher::calcSalary()
{
    double podstawa = getSalary();
    int lata = getYears();
    double bonusPercent = calcBonusPercent( lata );
    double brutto = podstawa * (1.0 + bonusPercent);
    if( isTutor() )
    {
        brutto += 400.0;
    }
    double brutto80 = 0.8 * brutto;
    double teacherKup = (brutto80 * 0.5);
    double tax = calculateTax( brutto80, teacherKup ) + calculateTax( 0.2 * brutto, KOSZT_UZYSKANIA_PRZYCHODU );
    double netto = brutto - tax;
    cout << "brutto: " << brutto << "    netto : " << netto << endl;
}