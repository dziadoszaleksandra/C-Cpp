#pragma once
#include "Person.h"

#define MAXSUBJECTS NIEMIECKI + 1

enum Subjects { POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI };

class Pupil : public Person
{
public:
	Pupil( string name = "", int age = 0, string className = "" );
	Pupil( const Pupil& p );
	virtual ~Pupil();

	void setClassName( string newClassName );
	string getClassname() const;
	string getID() const;

	void clearNotes();
	double calcAve();
	double getAve() const;

	void setNote( Subjects subject, double note );

	void printPupil();
	virtual void printOutfit() = 0;

protected:
	string mID;

private:
	string className;
	double mAve;
	double mNotes[MAXSUBJECTS];
	static int baseID;
};

inline void Pupil::setClassName( string newClassName ) 
{
	this->className = newClassName;
}

inline string Pupil::getClassname() const 
{
	return this->className;
}

inline string Pupil::getID() const 
{
	return this->mID;
}

inline double Pupil::getAve() const 
{
	return  mAve;
}