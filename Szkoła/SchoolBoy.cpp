#include "SchoolBoy.h"

SchoolBoy::SchoolBoy( string name, int age, string className ) :Pupil( name, age, className ) 
{
	Pupil::mID = "M_" + Pupil::mID;
}

void SchoolBoy::printOutfit() 
{
	cout << "biala koszula, szkolny krawat i szkolna marynarka, czarne /granatowe spodnie ,polbuty ";
}