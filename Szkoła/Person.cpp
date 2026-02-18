#include "Person.h"

Person::Person( string name, int age )
{
	setPerson( name, age );
}

void Person::setPerson( string newName, int newAge ) 
{
	setName( newName );
	setAge( newAge );
}

Person::Person ( const Person& p )
{
	*this = p;
}

Person::~Person() 
{

}