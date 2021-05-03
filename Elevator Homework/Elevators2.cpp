#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;

#include <cmath>
#include <cstdlib>
#include <ctime>

struct Rider
{
	const int from, to;
	const bool goingUp, goingDown;
public:
	Rider(int, int);
	Rider& operator =(const Rider&);
};

class Panel
{
	struct Button
	{
		string label;
		bool lit;
		int sequence;
		static int count;
	};

	vector<Button> buttons;
public:
	void addButton(string);
	void press(string);
	void clear(string);
	string getFirstLit() const;
	bool isLit(string) const;
	bool areAnyLit() const;
	friend ostream& operator<<(ostream&, const Panel&);
};

class Floor
{
	queue<Rider> upRiders, downRiders;
public:
	Floor(const int, const char* const, const char* const); // elevation (inches above ground) of floor, name and label
	operator int() const { return elevation; }

	static const char* const UP;
	static const char* const DOWN;
	static int TOP, BOTTOM;

	Panel panel;
	const string name; // name of floor, for example: Mezzanine
	const string label; // as it appears on the button panel
	const int elevation; // inches above ground level

	void addRider(const Rider& r);
	bool hasUpRider() const { return !upRiders.empty(); }
	bool hasDownRider() const { return !downRiders.empty(); }
	Rider removeUpRider();
	Rider removeDownRider();
	int getNumberOfUpRiders() const { return upRiders.size(); }
	int getNumberOfDownRiders() const { return downRiders.size(); }

	// for external reporting
	friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
};

class Elevator
{
	static const int IDLE = 0;
	static const int UP = 1;
	static const int DOWN = -1;
	static const int COURTESY_WAIT_TIME = 3;

	// elevator metrics
	int location; // inches above ground level
	int direction; // equal to IDLE, UP, DOWN
	int atFloorIndex;
	int timer;

	vector<Rider> riders;

public:
	Elevator(unsigned int, int, int);
	operator int() const { return location; }

	Panel panel;
	const int speed; // inches per second, up or down
	const unsigned int CAPACITY;

	// count-down timer before closing door
	void resetTimer() { timer = COURTESY_WAIT_TIME; }
	void tickTimer() { timer--; }
	bool timedOut() const { return timer == 0; }

	bool isOpen() const { return atFloorIndex >= 0; }
	void openDoorTo(int);
	void board(const Rider&);

	bool hasRiderForFloor() const;
	void removeRider();
	bool isFull() const { return CAPACITY == riders.size(); }
	bool goingUp() const { return direction == UP; }
	bool goingDown() const { return direction == DOWN; }
	int getFloorIndex() const { return atFloorIndex; }
	int getNumberOfRiders() const { return riders.size(); }

	// friend function
	friend ostream& operator<<(ostream&, const Elevator&);
};

struct Building
{
	static Floor floors[];
	static Elevator elevators[];
	static const int FLOORS;
	static const int ELEVATORS;

	// helper functions
	static void getDifferentInts(int&, int&);
	static int getPoisson(double);
	static void placeNewRiders(double);

	// actions
	static void action(double); // the main "action function"
	static bool openDoorToDisembarkRider(int); // step 1 of 9
	static bool disembarkRider(int); // parameter is an elevator's index
    static bool boardRider(int); // parameter is an elevator's index
};


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

int Panel::Button::count = 0;

void Panel::addButton(string label)
{
	Button temp = { label, false, -1 };
	buttons.push_back(temp);
}

void Panel::press(string label)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (this->buttons[i].label == label)
		{
			if (!buttons[i].lit)
			{
				this->buttons[i].lit = true;
				this->buttons[i].sequence == ++Button::count;
			}
		}
	}
}

void Panel::clear(string label)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (this->buttons[i].label == label)
		{
			if (buttons[i].lit)
			{
				this->buttons[i].lit = false;
			}
		}
	}
}

string Panel::getFirstLit() const
{
	int temp = 1000;
	int indet = 0;
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i].sequence < temp)
		{
			temp = buttons[i].sequence;
			i = indet;
		}
	}
	return buttons[indet].label;
}

ostream& operator << (ostream& out, const Panel& panel)
{
	for (int i = 0; i < panel.buttons.size(); i++)
	{
		if (panel.buttons[i].lit)
		{
			out << "[" << panel.buttons[i].label << "]";
		}
	}
	return out;
}

bool Panel::isLit(string label) const
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (this->buttons[i].label == label)
		{
			return buttons[i].lit;
			break;
		}
	}
	return false;
}

bool Panel::areAnyLit() const
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i].lit)
		{
			return true;
		}
	}
	return false;
}

const char* const Floor::UP = "Up";
const char* const Floor::DOWN = "Down";
int Floor::TOP = INT_MIN; // defined in climits
int Floor::BOTTOM = INT_MAX; // also in climits

Floor::Floor(const int elevation, const char* const name, const char* const label) :elevation(elevation), name(name), label(label)
{
	//add up and down buttons into the panel
	panel.addButton(UP);
	panel.addButton(DOWN);
	if (TOP < elevation)
	{
		TOP = elevation;
	}
	if (elevation < BOTTOM)
	{
		BOTTOM = elevation;
	}
}

ostream& operator<<(ostream& out, const Floor& floor)
{

	out.width(3);
	out << floor.label;
	out.width(15);
	out << floor.name << " at ";
	out.width(6);//continue
	out << floor.elevation << "   Up/Down: " << floor.upRiders.size() << "/" << floor.downRiders.size() << "   Button: " << floor.panel;
	return out;
}

void Floor::addRider(const Rider& r)
{
	if (r.goingUp)
	{
		upRiders.push(r);
		panel.press(UP);
	}
	if (r.goingDown)
	{
		downRiders.push(r);
		panel.press(DOWN);;
	}
}

Rider Floor::removeUpRider()
{
  if(upRiders.empty())
  {
  	throw
  	"No Riders Up!";
  }
  Rider ptr = upRiders.front();
  upRiders.pop();
  return ptr;
}

Rider Floor::removeDownRider()
{
  if(downRiders.empty())
  {
  	throw
  	"No Riders Down!";
  }
  Rider ptr = downRiders.front();
  downRiders.pop();
  return ptr;
}

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
		out << " ";
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
	if (r.goingUp)
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

Floor Building::floors[] =
{
	Floor(0, "First Floor", "1"),
	Floor(100, "Second Floor", "2"),
	Floor(200, "Third Floor", "3"),
	Floor(305, "Fourth Floor", "4"),
	Floor(410, "Fifth Floor", "5")
};
const int Building::FLOORS = sizeof(floors) / sizeof(Floor);

Elevator Building::elevators[] =
{
	Elevator(12, 5, 0),
	Elevator(12, 5, 100),
	Elevator(12, 5, 200),
};
const int Building::ELEVATORS = sizeof(elevators) / sizeof(Elevator);

// used by Building::placeNewRiders
void Building::getDifferentInts(int& a, int& b)
{
	do
	{
		a = rand() % FLOORS; // range is 0 to (FLOORS-1)
		b = rand() % FLOORS; // range is 0 to (FLOORS-1)    
	} while (a == b); // try again if they are the same
}

// used by Building::placeNewRiders
int Building::getPoisson(double avg)
{
	int arrivals = 0;
	double probOfnArrivals = exp(-avg); // requires cmath
	for (double randomValue = (rand() % 1000) / 1000.0; // requires cstdlib
		(randomValue -= probOfnArrivals) > 0.0;
		probOfnArrivals *= avg / ++arrivals);
	return arrivals;
}

// given an arrival rate, randomly select #of riders to add...
// ...and add them to randomly selected floors with random destinations
void Building::placeNewRiders(double arrivalsPerSecond)
{
	int n = getPoisson(arrivalsPerSecond);
	for (int i = 0; i < n; i++)
	{
		int from, to;
		getDifferentInts(from, to);
		Rider rider(from, to);
		floors[from].addRider(rider);
	}
}

// STEP 1 of 9, "Open their door if there is a rider to disembark"
bool Building::openDoorToDisembarkRider(int e)
{
	if (!elevators[e].isOpen()) // if the door is closed...
		for (int f = 0; f < FLOORS; f++) // check each floor to see if its elevation matches 
			if (floors[f] == elevators[e] &&
				elevators[e].panel.isLit(floors[f].label)) // ...and the elevator's panel has that floor lit
			{
				elevators[e].openDoorTo(f); // then open the door to that floor
				return true; // ...and report that an action was taken
			}
	return false; // if I get this far, no action was taken in this function
}

// the "action function" to perform one action per elevator per time step
void Building::action(double arrivalsPerSecond)
{
	placeNewRiders(arrivalsPerSecond);

	// one action per elevator
	for (int e = 0; e < ELEVATORS; e++)
	{
		if (openDoorToDisembarkRider(e)) continue; // step 1 of 9
		if (disembarkRider(e)) continue;
        if (boardRider(e)) continue;
	}
}

bool Building::disembarkRider(int e) // lab 9
{
  // if open and rider to disembark, do that
  if (elevators[e].isOpen() && elevators[e].hasRiderForFloor())
  {
    elevators[e].removeRider();
    return true;
  }
    return false;
}

bool Building::boardRider(int e) // lab 9
{
  // if door is open and not full and rider to load, load
  if (elevators[e].isOpen() && !elevators[e].isFull())
  {
    Floor& floor = floors[elevators[e].getFloorIndex()];
    if (elevators[e].goingUp() && floor.hasUpRider())
    {
      Rider rider = floor.removeUpRider();
      elevators[e].board(rider);
      return true;
    }
    else if (elevators[e].goingDown() && floor.hasDownRider())
    {
      Rider rider = floor.removeDownRider();
      elevators[e].board(rider);
      return true;
    }
  }
  return false;
}

int main()
{
  srand(time(0)); rand();

  // Seed elevators with riders so their doors open for riders to disembark
  for (int i = 0; i < 3; i++)
  {
    Building::elevators[1].board(Rider(4, 1));
    Building::elevators[2].board(Rider(0, 2));
  }
  
  for (int i = 0;; i++)
  {
    cout << "-----------------------------------------------\n";
    cout << "-- Time " << i << " ---------------------------\n";
    for (int elevator = 0; elevator < Building::ELEVATORS; elevator++)
      cout << Building::elevators[elevator] << endl;

    for (int floor = 0; floor < Building::FLOORS; floor++)
      cout << Building::floors[floor] << endl;

    // 20 riders per second from time 10 to time 20 -- approx 200 total riders
    Building::action(10 < i && i < 20 ? 20 : 0);

    cin.get();
  }
} 