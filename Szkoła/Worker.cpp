#include "Worker.h"

Worker::Worker( string name, int age, double salary, int years ) : Person( name, age )
{
    setSalary( salary );
    setYears( years );
}

Worker::Worker( const Worker& w )
{
    *this = w;
}

Worker::~Worker()
{

}

double Worker::calculateTax( double brutto, double kup )
{
    double tax = (brutto - kup) * PROCENT_PODATKU - KWOTA_WOLNA;
    if( tax < 0 )
        return 0;
    return tax;
}

double Worker::calcBonusPercent( int lata )
{
    double bonusPercent = 0;
    if( lata >= 5 && lata <= 20 )
        bonusPercent = lata * 0.01;
    if( lata > 20 )
        bonusPercent = 0.20;
    return bonusPercent;
}