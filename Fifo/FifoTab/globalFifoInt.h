using namespace std;
#include <iostream>
#define FQINFO QINFO

struct QINFO
{
public:
	QINFO ( int pKey = 0 );
	virtual ~QINFO();
	friend ostream& operator << ( ostream& out, const QINFO& FQI );

private:
	int* pTab;
	int key;
};