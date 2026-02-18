#include "Matrix.h"
#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------------------------
//uzycei try,catch i throw
Matrix::Matrix( int nRow, int nCol, double nElem )
{
    try {
        createMatrix( nRow, nCol );
    }
    catch( const MatrixException& e ) {
        // jesli creatematrix wyrzuci wyjatek to wypisujemy powod bledu
        cerr << e.getReason();     
        // ponownie wyrzucamy wyjatek dalej, zeby wyzej tez mozna bylo go obsluzyc
        throw;
    }

    /// jesli createMatrix sie udal to kazdy wiersz uzupelniamy wektorem zawierajacym nElem
    for( int i = 0; i < getRowNo(); i++ )
        m_pRows[i] = Vector( nCol, nElem );
}

//--------------------------------------------------------------------------------------------------
Matrix::Matrix( const Matrix& mx )
{
    m_pRows = nullptr;
    m_nRows = 0;
    m_nCols = 0;
    *this = mx;
}

//--------------------------------------------------------------------------------------------------
Matrix::~Matrix()
{
    delete[] m_pRows;
}

//--------------------------------------------------------------------------------------------------
Matrix& Matrix::operator=( const Matrix& mx )
{
    if( this != &mx )
    {
        if( this->getRowNo() != mx.getRowNo() || this->getColNo() != mx.getColNo() )
        {
            delete[] m_pRows;
            try {
                createMatrix( mx.getRowNo(), mx.getColNo() );
            }
            catch( const MatrixException& e ) {
                cerr << e.getReason();
                throw;
            }
        }
        copyMatrix( mx );
    }
    return *this;
}

//--------------------------------------------------------------------------------------------------
istream& operator>>( istream& in, Matrix& mx )
{
    for( int i = 0; i < mx.getRowNo(); i++ )
        in >> mx.m_pRows[i];
    return in;
}

//--------------------------------------------------------------------------------------------------
ostream& operator<<( ostream& out, const Matrix& mx )
{
    for( int i = 0; i < mx.getRowNo(); i++ )
    {
        out << mx.m_pRows[i];
        if( i < mx.getRowNo() - 1 )
            out << "\n";
    }
    return out;
}

//--------------------------------------------------------------------------------------------------
bool operator==( const Matrix& mx1, const Matrix& mx2 )
{
    if( mx1.getRowNo() != mx2.getRowNo() || mx1.getColNo() != mx2.getColNo() )
        return false;

    for( int i = 0; i < mx1.getRowNo(); i++ )
    {
        if( mx1.m_pRows[i] != mx2.m_pRows[i] )
            return false;
    }
    return true;
}

//--------------------------------------------------------------------------------------------------
bool operator!=( const Matrix& mx1, const Matrix& mx2 )
{
    return !(mx1 == mx2);
}

//--------------------------------------------------------------------------------------------------
const Matrix operator*( const Matrix& mx1, const Matrix& mx2 )
{
    if( mx1.getColNo() != mx2.getRowNo() )
        throw MatrixException( MAT_INCOMPATIBLE_ERROR );

    Matrix res( mx1.getRowNo(), mx2.getColNo(), 0 );

    for( int i = 0; i < mx1.getRowNo(); i++ )
    {
        for( int j = 0; j < mx2.getColNo(); j++ )
        {
            double sum = 0.0; 
            for( int k = 0; k < mx1.getColNo(); k++ )
            {
                sum += mx1.m_pRows[i][k] * mx2.m_pRows[k][j];
            }
            res.m_pRows[i][j] = sum;
        }
    }
    return res;
}

//--------------------------------------------------------------------------------------------------
const Vector operator*( const Matrix& mx, const Vector& v )
{
    if( mx.getColNo() != v.getDim() )
        throw MatrixException( MAT_INCOMPATIBLE_ERROR );

    Vector res( mx.getRowNo(), 0 );

    for( int i = 0; i < mx.getRowNo(); i++ )
        res[i] = mx.m_pRows[i] * v;

    return res;
}