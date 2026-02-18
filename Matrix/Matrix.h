#pragma once
#include <iostream>
#include "Vector.h"
using namespace std;

//--------------------------------------------------------------------------------------------------
//kody bledow
#define MAT_OTHER_ERROR 0xFF
#define MAT_ALLOC_ERROR 0x01
#define MAT_SIZE_ERROR 0x02
#define MAT_INDEX_OUT_OF_RANGE_ERROR 0x04
#define MAT_INCOMPATIBLE_ERROR 0x08

typedef unsigned short USHORT;

//--------------------------------------------------------------------------------------------------
//klasa wyjatku
class MatrixException
{
public:
    MatrixException( USHORT errCode = MAT_OTHER_ERROR ) { mErrCode = errCode; };
    const char* getReason() const;

private:
    USHORT mErrCode;
};

//--------------------------------------------------------------------------------------------------
inline const char* MatrixException::getReason() const
{
    switch( mErrCode )
    {
    case MAT_ALLOC_ERROR: return "ERROR: Memory allocation error!\n";
    case MAT_SIZE_ERROR: return "ERROR: Improper matrix size (min size 2)!\n";
    case MAT_INDEX_OUT_OF_RANGE_ERROR: return "ERROR: Index out of range!\n";
    case MAT_INCOMPATIBLE_ERROR: return "ERROR: Incompatible matrix dimensions!\n";
    default: return "ERROR: Other error\n";
    }
}

//--------------------------------------------------------------------------------------------------
//glowna klasa
class Matrix
{
public:
    explicit Matrix( int nRow = 2, int nCol = 2, double nElem = 0 );
    Matrix( const Matrix& mx );
    virtual ~Matrix();

    int getRowNo() const;
    int getColNo() const;

    //assigment
    Matrix& operator = ( const Matrix& mx );

    //we/wy
    friend istream& operator >> ( istream& in, Matrix& mx );
    friend ostream& operator << ( ostream& out, const Matrix& mx );

    //operatory indeksowania
    Vector& operator [] ( int ix );
    const Vector& operator [] ( int ix ) const;

    //operator rzutowania do Vector*
    explicit operator Vector* () const { return m_pRows; }

    //operatory porownania
    friend bool operator == ( const Matrix& mx1, const Matrix& mx2 );
    friend bool operator != ( const Matrix& mx1, const Matrix& mx2 );

    //operator mnozenia macierzy
    friend const Matrix operator * ( const Matrix& mx1, const Matrix& mx2 );

    //operator mnozenia macierzy przez wektor
    friend const Vector operator * ( const Matrix& mx, const Vector& v );

private:
    void createMatrix( int nRow, int nCol );
    void copyMatrix( const Matrix& mx );

private:
    Vector* m_pRows;  
    int m_nRows;      
    int m_nCols;      
};

//--------------------------------------------------------------------------------------------------
//inline functions
inline int Matrix::getRowNo() const
{
    return m_nRows;
}

inline int Matrix::getColNo() const
{
    return m_nCols;
}

inline void Matrix::createMatrix( int nRow, int nCol )
{
    if( nRow < 2 || nCol < 2 )
    {
        throw MatrixException( MAT_SIZE_ERROR );
    }
    m_nRows = nRow;
    m_nCols = nCol;
    m_pRows = new Vector[m_nRows];
}

inline void Matrix::copyMatrix( const Matrix& mx )
{
    for( int i = 0; i < m_nRows; i++ )
    {
        m_pRows[i] = mx.m_pRows[i];
    }
}

inline Vector& Matrix::operator [] ( int ix )
{
    if( ix < 0 || ix >= getRowNo() )
    {
        throw MatrixException( MAT_INDEX_OUT_OF_RANGE_ERROR );
    }
    return m_pRows[ix];
}

inline const Vector& Matrix::operator [] ( int ix ) const
{
    if( ix < 0 || ix >= getRowNo() )
    {
        throw MatrixException( MAT_INDEX_OUT_OF_RANGE_ERROR );
    }
    return m_pRows[ix];
}