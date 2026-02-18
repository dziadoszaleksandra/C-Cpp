#pragma once
using namespace std;
#include <string>
#include <iostream>

class Person
{
public:
	Person( string name = " ", int age = 0 );
	Person ( const Person& p );
	virtual ~Person();

	Person& operator= ( const Person& p ) = default;

	string getName() const;
	int getAge() const;

	void setName( string newName );
	void setAge( int newAge );

	void setPerson( string newName, int newAge );

private:
	string mName;
	int    mAge;
};

inline void Person::setName( string newName ) 
{
	mName = newName;
}

inline void Person::setAge( int newAge ) 
{
	mAge = newAge;
}

inline string Person::getName() const 
{
	return mName;
}

inline int Person::getAge() const 
{
	return mAge;
}