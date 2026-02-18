#include "Pupil.h"
//using namespace std;

int Pupil::baseID = 10000;

Pupil::Pupil( string name, int age, string className ) :Person( name, age )
{
	setClassName( className );
	mID = to_string( baseID++ );
}

Pupil:: ~Pupil() 
{

}

Pupil::Pupil( const Pupil& p )
{
	*this = p;
}


void Pupil::clearNotes() 
{
	memset( mNotes, 0, MAXSUBJECTS * sizeof( double ) );
	mAve = 0;
}

double Pupil::calcAve() 
{
	int no = 0;
	double sum = 0;
	for( int subj = POLSKI; subj < MAXSUBJECTS; subj++ ) 
	{
		if( mNotes[subj] > 1 ) 
		{
			sum += mNotes[subj];
			no++;
		}
	}
	return mAve = (no) ? sum / no : 0;
}

void Pupil::setNote( Subjects subject, double note ) 
{
	if( subject >= POLSKI && subject <= NIEMIECKI )
		if( note > 1 )
			mNotes[subject] = note;
}

void Pupil::printPupil() 
{
	cout << getID() << ' ' << getName() << "(" << this->getClassname() << ")" << mAve << endl;
	cout << '\t';
	printOutfit();
}