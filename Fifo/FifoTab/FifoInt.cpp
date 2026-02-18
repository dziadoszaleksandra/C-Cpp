#include "FifoInt.h"

FQueue::FQueue( int nMaxElem )
{
    if( nMaxElem < 2 )
    {
        throw FQueueException( FIFO_EMPTY_ERROR );
    }
    this->nMaxElem = nMaxElem;
    nInfo = new (nothrow) QINFO * [nMaxElem];
    if( !nInfo )
    {
        throw FQueueException( FIFO_ALLOC_ERROR );
        this->nMaxElem = 0;
    }
    nHead = nTail = 0;
    nNoElem = 0;
}

FQueue::~FQueue()
{
    FQClear();
    delete[] nInfo;
}

bool FQueue::FQEmpty()
{
    return !nNoElem;
}

void FQueue::FQEnqueue( FQINFO* Info )
{
    if( nMaxElem == nNoElem ) 
    {
        throw FQueueException( FIFO_OVERFLOW_ERROR );
    }
    nInfo[nTail] = Info;
    nTail = (nTail + 1) % nMaxElem;
    nNoElem++;
}

FQINFO* FQueue::FQDequeue()
{
    if( FQEmpty() )
        throw FQueueException( FIFO_EMPTY_ERROR );

    FQINFO* pInfo = nInfo[nHead];
    FQDel();
    return pInfo;
}


void FQueue::FQClear()
{
    while( !FQEmpty() )
        delete FQDequeue();
}

void FQueue::FQprint()
{
    if( FQEmpty() )
    {
        cout << "Kolejka jest pusta!" << endl;
        return;
    }

    int curr = nHead;
    for( int i = 0; i < nNoElem; i++ )
    {
        cout << *(nInfo[curr]) << endl;
        curr = (curr + 1) % nMaxElem;
    }
    cout << endl;
}

void FQueue::FQDel() 
{
    if( FQEmpty() )
        throw FQueueException( FIFO_EMPTY_ERROR );

    nInfo[nHead] = nullptr;
    nHead = (nHead + 1) % nMaxElem;
    nNoElem--;
}