#include "Rider.h"
#include "Building.h"
#include "Floor.h"
#include "Panel.h"

#include <iostream>
using namespace std;

Rider::Rider(int from, int to) :from(from), to(to), goingDown((Building::floors[from] > Building::floors[to]) ? true : false), goingUp((Building::floors[to] > Building::floors[from]) ? true : false)
{
}

Rider& Rider::operator=(const Rider& rhs)
{
    const_cast<bool & > (this->goingUp) = rhs.goingUp;
    const_cast<bool & > (this->goingDown) = rhs.goingDown;
    const_cast<int & > (this->from) = rhs.from;
    const_cast<int & > (this->to) = rhs.to;
    return *this;
}
