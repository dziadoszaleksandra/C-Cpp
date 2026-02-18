#include <iostream>
#include "globalFifoInt.h"
using namespace std;

#define FIFO_ALLOC_ERROR 0x01
#define FIFO_EMPTY_ERROR 0x02
#define FIFO_OVERFLOW_ERROR 0x03
#define OTHER_ERROR 0x04

class FQueueException
{
public:
    inline FQueueException( int mErr = OTHER_ERROR ) { mErrCode = mErr; }
    inline const char* getReason();

private:
    int mErrCode;
};

inline const char* FQueueException::getReason()
{
    switch( mErrCode )
    {
    case FIFO_ALLOC_ERROR: return "Memory allocation error\n";
    case FIFO_EMPTY_ERROR: return "FQUEUE is empty\n";
    case FIFO_OVERFLOW_ERROR: return "FQUEUE is overlow\n";
    default: return" Other error";
    }
}
//--------------------------------------------------------------

class FQueue
{
public:
    FQueue( int nMaxElem = 2 );
    virtual ~FQueue();
    bool FQEmpty();
    void FQClear();
    void FQEnqueue( FQINFO* Info );
    FQINFO* FQDequeue();
    void FQprint();
    void FQDel();

private:
    FQINFO** nInfo;   // tablica wskaz na elem
    int nNoElem;
    int nHead;
    int nTail;
    int nMaxElem;
};