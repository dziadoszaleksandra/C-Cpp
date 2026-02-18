#include "QFIFO.h"

FQItem::~FQItem()
{

}

FQItem::FQItem( FQINFO* Info )
{
	pInfo = Info;
	pNext = nullptr;
}

//-------------------------------------------------------------

FQueue::FQueue()
{
	pHead = nullptr;
	pTail = nullptr;
}

FQueue::~FQueue()
{
	FQClear();
}

bool FQueue::FQEmpty()
{
	return !pHead;
}

void FQueue::FQClear()
{
	while( !FQEmpty() )
		delete FQDequeue();
}

void FQueue::FQEnqueue( FQINFO* Info )
{
	FQItem* p = new(nothrow) FQItem( Info );
	if( !p )
	{
		throw FQueueException( FIFO_ALLOC_ERROR );
	}
	if( FQEmpty() )
	{
		pHead = p;
	}
	else
	{
		pTail->pNext = p;
	}
	pTail = p;
}

FQINFO* FQueue::FQDequeue()
{
	if( FQEmpty() )
		throw FQueueException( FIFO_EMPTY_ERROR );

	QINFO* temp = pHead->pInfo;
	FQDel();
	return temp;
}


void FQueue::FQDel()
{
	if( FQEmpty() )
	{
		throw FQueueException( FIFO_EMPTY_ERROR );
	}
	FQItem* temp = pHead;
	pHead = temp->pNext;
	if( FQEmpty() )
		pTail = nullptr;
}

void FQueue::FQprint()
{
	if( FQEmpty() )
	{
		cout << "Kolejka jest pusta!" << endl;
		return;
	}
	FQItem* p = pHead;
	while( p )
	{
		cout << *(p->pInfo) << endl;
		p = p->pNext;
	}
}