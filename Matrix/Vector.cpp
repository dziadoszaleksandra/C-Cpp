#include "Vector.h"
#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------------------------
//uzycei try,catch i throw
Vector::Vector( int nSize, double nElem )
{
    try {
        createVec( nSize );
    }
    catch( const VectorException& e ) {
        //jesli createVec wyrzuci wyjatek to wypisujemy powod bledu
        cerr << e.getReason();
        //ponownie wyrzucamy wyjatek dalej, zeby wyzej tez mozna bylo go obsluzyc
        throw;
    }

    // jesli createvec sie udal to wypelniamy wszystkie elementy wartoscia nElem
    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] = nElem;
}

//--------------------------------------------------------------------------------------------------
Vector::Vector( const Vector& v )
{
    m_pCoord = nullptr;
    mDim = 0;
    *this = v;
}

//--------------------------------------------------------------------------------------------------
Vector::~Vector()
{
    delete[] m_pCoord;
}

//--------------------------------------------------------------------------------------------------
Vector& Vector::operator=( const Vector& v )
{
    if( this != &v )
    {
        if( this->getDim() != v.getDim() )
        {
            delete[] m_pCoord;
            try {
                createVec( v.getDim() );
            }
            catch( const VectorException& e ) {
                cerr << e.getReason();
                throw;  
            }
        }
        copyVec( v );
    }
    return *this;
}

//--------------------------------------------------------------------------------------------------
istream& operator>>( istream& in, Vector& v )
{
    for( int i = 0; i < v.getDim(); i++ )
        in >> v.m_pCoord[i];
    return in;
}

//--------------------------------------------------------------------------------------------------
ostream& operator<<( ostream& out, const Vector& v )
{
    out << "[ ";
    for( int i = 0; i < v.getDim(); i++ )
    {
        out << v.m_pCoord[i];
        if( i < v.getDim() - 1 )
            out << " , ";
    }
    out << " ]";
    return out;
}

//--------------------------------------------------------------------------------------------------
const Vector operator+( const Vector& v1, const Vector& v2 )
{
    Vector res( v1 );
    return res += v2;
}

//--------------------------------------------------------------------------------------------------
const Vector operator+( const Vector& v, double x )
{
    Vector res( v );
    return res += x;
}

//--------------------------------------------------------------------------------------------------
const Vector operator+( double x, const Vector& v )
{
    return v + x;
}

//--------------------------------------------------------------------------------------------------
Vector& Vector::operator+=( const Vector& v )
{
    if( this->getDim() != v.getDim() )
        throw VectorException( VEC_INCOMPATIBLE_ERROR );

    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] += v.m_pCoord[i];

    return *this;
}

//--------------------------------------------------------------------------------------------------
Vector& Vector::operator+=( double x )
{
    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] += x;
    return *this;
}

//--------------------------------------------------------------------------------------------------
const Vector operator-( const Vector& v1, const Vector& v2 )
{
    Vector res( v1 );
    return res -= v2;
}

//--------------------------------------------------------------------------------------------------
const Vector operator-( const Vector& v, double x )
{
    Vector res( v );
    return res -= x;
}

//--------------------------------------------------------------------------------------------------
Vector& Vector::operator-=( const Vector& v )
{
    if( this->getDim() != v.getDim() )
        throw VectorException( VEC_INCOMPATIBLE_ERROR );

    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] -= v.m_pCoord[i];

    return *this;
}

//--------------------------------------------------------------------------------------------------
Vector& Vector::operator-=( double x )
{
    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] -= x;
    return *this;
}

//--------------------------------------------------------------------------------------------------
const Vector operator-( const Vector& v )
{
    Vector res( v );
    for( int i = 0; i < res.getDim(); i++ )
        res.m_pCoord[i] = -res.m_pCoord[i];
    return res;
}

//--------------------------------------------------------------------------------------------------
const Vector operator*( const Vector& v, double x )
{
    Vector res( v );
    return res *= x;
}

//--------------------------------------------------------------------------------------------------
const Vector operator*( double x, const Vector& v )
{
    return v * x;
}

//--------------------------------------------------------------------------------------------------
Vector& Vector::operator*=( double x )
{
    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] *= x;
    return *this;
}

//--------------------------------------------------------------------------------------------------
double operator*( const Vector& v1, const Vector& v2 )
{
    if( v1.getDim() != v2.getDim() )
        throw VectorException( VEC_INCOMPATIBLE_ERROR );

    double res = 0;
    for( int i = 0; i < v1.getDim(); i++ )
        res += v1.m_pCoord[i] * v2.m_pCoord[i];

    return res;
}

//--------------------------------------------------------------------------------------------------
bool operator==( const Vector& v1, const Vector& v2 )
{
    if( v1.getDim() != v2.getDim() )
        return false;

    for( int i = 0; i < v1.getDim(); i++ )
        if( v1.m_pCoord[i] != v2.m_pCoord[i] )
            return false;

    return true;
}

//--------------------------------------------------------------------------------------------------
bool operator!=( const Vector& v1, const Vector& v2 )
{
    return !(v1 == v2);
}
