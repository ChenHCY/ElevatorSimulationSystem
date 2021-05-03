#include "Elevator.h"
#include "Panel.h"
#include "Building.h"

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

#include <cstdlib>

Elevator::Elevator(unsigned int capacity, int speed, int start) :speed(speed), CAPACITY(capacity), location(start)
{
	start = Building::floors[start];
	atFloorIndex = -1;
	direction = IDLE;
	timer = 0;

	for (int i = 0; i < Building::FLOORS; i++)
	{
		panel.addButton(Building::floors[i].label);
	}
}

ostream& operator<<(ostream& out, const Elevator& e)
{
	out << "Elevator at ";
	out.width(5);
	out << e.location;
	out.width(11);
	switch (e.direction)
	{
	case 1:
		cout << "going UP";
		break;
	case -1:
		cout << "going DOWN";
		break;
	case 0:
		cout << "      IDLE";
		break;
	}
	out.width(3);
	out << e.riders.size() << " riders";
	out.width(16);
	if (e.atFloorIndex == -1)
	{
		return out;
	}
	else
	{
		out << "door is open|" << e.timer;
	}

	out << " " << e.panel;
	return out;
}

void Elevator::openDoorTo(int i)
{
   panel.clear(Building::floors[i].label);
   atFloorIndex = i;
   resetTimer();
}

void Elevator::board(const Rider& r)
{
	riders.push_back(r);
	this->panel.press(Building::floors[r.to].label);
	if(r.goingUp)
	{
		this->direction = this->UP;
	}
	else
	{
		this->direction = this->DOWN;
	}
	resetTimer();
}

bool Elevator::hasRiderForFloor() const
{
	if(atFloorIndex == -1)
	{
		return false;
	}
	for(int i = 0; i < riders.size(); i++)
	{
		if(riders[i].to == atFloorIndex)
		{
			return true;
		}
		return false;
	}
}

void Elevator::removeRider()
{
	vector<Rider>::iterator it;
	for(it=riders.begin(); it != riders.end(); ++it)
	{
		if(it->to == atFloorIndex)
		{
			this->panel.clear(Building::floors[atFloorIndex].label);
		}
	riders.erase(it);
	resetTimer();
	break;
	}
}
