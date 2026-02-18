#pragma once
#include "Worker.h"

enum TeachSubject 
{
    TS_POLSKI,
    TS_MATEMATYKA,
    TS_FIZYKA,
    TS_CHEMIA,
    TS_INFORMATYKA,
    TS_ANGIELSKI,
    TS_NIEMIECKI
};

class Teacher : public Worker
{
public:
    Teacher( string name = "", int age = 0, double salary = 0.0, int years = 0,
        TeachSubject subject = TS_POLSKI, bool tutor = false, string className = "" );

    Teacher( const Teacher& t );

    void setSubject( TeachSubject s );
    TeachSubject getSubject() const;

    void setTutor( bool t );
    bool isTutor() const;

    void setClassName( string c );
    string getClassName() const;

    virtual void printInfo();
    virtual void calcSalary();

private:
    TeachSubject mSubject;
    bool mTutor;
    string mClassName;
};

inline void Teacher::setSubject( TeachSubject s )
{
    mSubject = s;
}

inline TeachSubject Teacher::getSubject() const
{
    return mSubject;
}

inline void Teacher::setTutor( bool t )
{
    mTutor = t;
}

inline bool Teacher::isTutor() const
{
    return mTutor;
}

inline void Teacher::setClassName( string c )
{
    mClassName = c;
}

inline string Teacher::getClassName() const
{
    return mClassName;
}