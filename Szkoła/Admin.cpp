#include "Admin.h"
#include <iostream>

static const char* adminPosToStr( AdminPosition p )
{
    switch( p )
    {
    case JUNIOR_SPEC:  return "mlodszy_specjalista";
    case REGULAR_SPEC: return "specjalista";
    case SENIOR_SPEC:  return "starszy_specjalista";
    default:           return "nieznane_stanowisko";
    }
}

Admin::Admin( string name, int age, double salary,
    int years, AdminPosition pos ) : Worker( name, age, salary, years )
{
    setPosition( pos );
}

void Admin::printInfo()
{
    cout << "Administracja: " << getName()
        << " (wiek: " << getAge()
        << ", stanowisko: " << adminPosToStr( mPosition )
        << ", staz: " << getYears() << " lat)"
        << endl;
}

void Admin::calcSalary()
{
    double podstawa = getSalary();
    int lata = getYears();
    double bonusPercent = calcBonusPercent( lata );
    double brutto = podstawa * (1.0 + bonusPercent);
    double tax = calculateTax( brutto, KOSZT_UZYSKANIA_PRZYCHODU );
    double netto = brutto - tax;
    cout << "Brutto: " << brutto << "    Netto: " << netto << endl;
}