// Rider.h (now it's complete)
#ifndef Rider_h
#define Rider_h

#include <iostream>
#include <string>
using namespace std;

struct Rider
{
	const int from, to;
	const bool goingUp, goingDown;
    public:
    Rider(int, int);
	Rider& operator =(const Rider&);
};

#endif 
