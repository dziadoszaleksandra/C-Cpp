#pragma once
#include "Worker.h"

enum AdminPosition { JUNIOR_SPEC, REGULAR_SPEC, SENIOR_SPEC };

class Admin : public Worker
{
public:
    Admin( string name = "", int age = 0, double salary = 0.0,
        int years = 0, AdminPosition pos = JUNIOR_SPEC );

    AdminPosition getPosition() const;
    void setPosition( AdminPosition newPos );

    virtual void printInfo();
    virtual void calcSalary();

private:
    AdminPosition mPosition;
};

inline AdminPosition Admin::getPosition() const
{
    return mPosition;
}

inline void Admin::setPosition( AdminPosition newPos )
{
    mPosition = newPos;
}