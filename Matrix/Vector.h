#pragma once
#include <iostream>
using namespace std;

//---------------------------------------------------------------------
//kody bledow
#define VEC_OTHER_ERROR 0xFF
#define VEC_ALLOC_ERROR 0x01
#define VEC_SIZE_ERROR 0x02
#define VEC_INDEX_OUT_OF_RANGE_ERROR 0x04
#define VEC_INCOMPATIBLE_ERROR 0x08

typedef unsigned short USHORT;

//--------------------------------------------------------------------------------------------------
//klasa wyjatku
class VectorException
{
public:
    VectorException( USHORT errCode = VEC_OTHER_ERROR ) { mErrCode = errCode; };
    const char* getReason() const;

private:
    USHORT mErrCode;// kod bledu
};

//--------------------------------------------------------------------------------------------------
inline const char* VectorException::getReason() const
{
    switch( mErrCode )
    {
    case VEC_ALLOC_ERROR: return "ERROR: Memory allocation error!\n";
    case VEC_SIZE_ERROR: return "ERROR: Improper vector size (min size 2)!\n";
    case VEC_INDEX_OUT_OF_RANGE_ERROR: return "ERROR: Index out of range!\n";
    case VEC_INCOMPATIBLE_ERROR: return "ERROR: Incompatible vector dimensions!\n";
    default: return "ERROR: Other error\n";
    }
}

//--------------------------------------------------------------------------------------------------
//glowna klasa
class Vector
{
public:
    explicit Vector( int nSize = 2, double nElem = 0 );
    Vector( const Vector& v );
    virtual ~Vector();

    int getDim() const;

    //assigment
    Vector& operator = ( const Vector& v );

    //we/wy
    friend istream& operator >> ( istream& in, Vector& v );
    friend ostream& operator << ( ostream& out, const Vector& v );

    //addition
    friend const Vector operator + ( const Vector& v1, const Vector& v2 );
    friend const Vector operator + ( const Vector& v, double x );
    friend const Vector operator + ( double x, const Vector& v );
    Vector& operator += ( const Vector& v );
    Vector& operator += ( double x );

    //substraction
    friend const Vector operator - ( const Vector& v1, const Vector& v2 );
    friend const Vector operator - ( const Vector& v, double x );
    Vector& operator -= ( const Vector& v );
    Vector& operator -= ( double x );

    //unary minus
    friend const Vector operator - ( const Vector& v );

    //multiplication
    friend const Vector operator * ( const Vector& v, double x );
    friend const Vector operator * ( double x, const Vector& v );
    Vector& operator *= ( double x );

    //scalar muliplication
    friend double operator * ( const Vector& v1, const Vector& v2 );

    //comparision
    friend bool operator == ( const Vector& v1, const Vector& v2 );
    friend bool operator != ( const Vector& v1, const Vector& v2 );

    //cast to double*
    explicit operator double* () const { return m_pCoord; }

    //indexation
    double& operator [] ( int ix );
    const double& operator [] ( int ix ) const;

private:
    void createVec( int nSize );
    void copyVec( const Vector& v );

private:
    double* m_pCoord; 
    int		mDim;      
};

//--------------------------------------------------------------------------------------------------
//inline functions
inline int Vector::getDim() const
{
    return mDim;
}


inline void Vector::createVec( int nSize )
{

    if( nSize < 2 )
    {
        throw VectorException( VEC_SIZE_ERROR );
    }
    mDim = nSize;
    m_pCoord = new double[mDim];
}

inline void Vector::copyVec( const Vector& v )
{
    memcpy( this->m_pCoord, v.m_pCoord, getDim() * sizeof( double ) );
}

inline double& Vector::operator [] ( int ix )
{
    if( ix < 0 || ix >= getDim() )
    {
        throw VectorException( VEC_INDEX_OUT_OF_RANGE_ERROR );
    }
    return this->m_pCoord[ix];
}

inline const double& Vector::operator [] ( int ix ) const
{
    if( ix < 0 || ix >= getDim() )
    {
        throw VectorException( VEC_INDEX_OUT_OF_RANGE_ERROR );
    }
    return this->m_pCoord[ix];
}
