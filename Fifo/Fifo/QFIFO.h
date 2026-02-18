#include "globall.h"

#define FIFO_ALLOC_ERROR	0x01
#define FIFO_EMPTY_ERROR	0x02
#define OTHER_ERROR	0x03

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
	default: return" Other error";
	}
}
//-----------------------------------------
class FQueue;
class FQItem	//elem kolejki
{
private:
	friend class FQueue;
	FQItem( FQINFO* Info );

	virtual ~FQItem();
	FQINFO* pInfo;
	FQItem* pNext;

};

class FQueue
{
public:
	FQueue();
	virtual ~FQueue();
	bool FQEmpty();
	void FQClear();
	void FQEnqueue( FQINFO* Info );
	FQINFO* FQDequeue();
	void FQprint();
	void FQDel();

private:
	FQItem* pHead;
	FQItem* pTail;
};