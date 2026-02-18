#include "globalFifoInt.h"

QINFO::QINFO ( int pKey )
{
	key = pKey;
	pTab = new int[2];
	pTab[0] = pTab[1] = key;
}

QINFO::~QINFO()
{
	delete[] pTab;
}

ostream& operator << ( ostream& out, const QINFO& FQI )
{
	out << "Key: " << FQI.key << ", values: pTab[0] " << FQI.pTab[0] << ", pTab[1] " << FQI.pTab[1] << endl;
	return out;
}