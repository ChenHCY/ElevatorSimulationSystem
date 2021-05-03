#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<algorithm>//for swap()
#include<vector>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

/*
Describe:A classic problem in mathematics is the linear programming problem of finding the shortest route through a network of interconnected points.
Applications include finding the shortest distance from one city to another, and finding the critical path in a project. Write Routes.1.cpp, to design 
and test a class that represents a leg of a route between two adjacent cities. 
Lab7: Route.3
Programmer: ChenYu Yang    ID:1670203
Date: September 24,2018
*/

class Leg
{
    const char* const startCity;
    const char* const endCity;
    const int distance;
public:
    Leg(const char* const, const char* const, double);
    Leg& operator=(const Leg&);//for swap()
    int getDistance() const {return distance;}
    void output(ostream&) const;
    friend class Route;
    friend class ShortestRoute;
};

class Route
{
    vector<const Leg*> legs;
    const int totalDis;
public:
    Route(const Leg&);
    Route(const Route&, const Leg&);
    Route& operator=(const Route&);
    int getDistance() const {return totalDis;}
    void output(ostream&) const;
    friend bool operator<(const Route&, const Route&);
};

class ShortestRoute
{
    static const int legSize;
    static const Leg allLegs[];
public:
    static const Route anyRoute(const char* const, const char* const);
    static const Route shortestRoute(const char* const, const char* const);
};

const Leg ShortestRoute::allLegs[] =
{
    Leg("Memphis", "Orlando", 684),
    Leg("Miles City", "Fargo", 430),
    Leg("Fargo", "Minneapolis", 214),
    Leg("Fargo", "Chicago", 569),
    Leg("Denver", "Omaha", 484),
    Leg("Denver", "Oklahoma City", 504),
    Leg("Memphis", "Washington", 763),
    Leg("New Orleans", "Orlando", 533),
    Leg("San Francisco", "Las Angeles", 312),
    Leg("Minneapolis", "Cleveland", 630),
    Leg("Chicago", "Cleveland", 307),
    Leg("Cleveland", "Pittsburgh", 115),
    Leg("Pittsburgh", "New York City", 315),
    Leg("Chicago", "Pittsburgh", 409),
    Leg("San Francisco", "Portland", 536),
    Leg("Reno", "Salt Lake City", 427),
    Leg("Las Angeles", "Phoenix", 357),
    Leg("San Francisco", "Reno", 186),
    Leg("El Paso", "Houston", 674),
    Leg("El Paso", "  Oklahoma City", 576),
    Leg("Helena", "Miles City", 294),
    Leg("Helena", "Fargo", 721),
    Leg("Miles City", "Omaha", 606),
    Leg("Reno", "Phoenix", 601),
    Leg("Portland", "Helena", 516),
    Leg("Salt Lake City", "Denver", 371),
    Leg("Salt Lake City", "Miles City", 494),
    Leg("Omaha", "Chicago", 435),
    Leg("Omaha", "St.Louis", 357),
    Leg("Omaha", "Memphis", 531),
    Leg("Oklahoma City", "Memphis", 421),
    Leg("Houston", "Memphis", 485),
    Leg("Houston", "New Orleans", 318),
    Leg("St.Louis", "Philadelphia", 809),
    Leg("Reno", "Phoenix", 601),
    Leg("Phoenix", "Denver", 586),
    Leg("Phoenix", "El Paso", 345),
    Leg("Chicago", "Philadelphia", 664),
    Leg("Memphis", "Philadelphia", 879),
    Leg("Orlando", "Washington", 759),
    Leg("Washington", "New York City", 203),
    Leg("Philadelphia", "New York City", 80),
    Leg("San Francisco", "New York City", 21000)
};

const int ShortestRoute::legSize = sizeof(ShortestRoute::allLegs)/ sizeof(ShortestRoute::allLegs[0]);

Leg::Leg(const char* const startCity, const char* const endCity, double distance):startCity(startCity), endCity(endCity), distance(distance)
{
    
}

Route::Route(const Leg& leg1) : totalDis(leg1.getDistance())
{
  legs.push_back(&leg1);
}

Route::Route(const Route& exRoute, const Leg& leg1):legs(exRoute.legs), totalDis(strcmp(exRoute.legs.back()->endCity, leg1.startCity) == 0 ? exRoute.getDistance()+ leg1.getDistance() : exRoute.getDistance())
{
   try
   {
     if(strcmp(exRoute.legs.back()->endCity, leg1.startCity) != 0)
     {
        throw "Cities don't mtach !!";
     }
     legs.push_back(&leg1);
   }
   catch(const char* ex)
   {
     cout << ex << endl;
   }
}

bool operator<(const Route& route1, const Route& route2)
{
  return route1.totalDis < route2.totalDis;
}


Route& Route::operator=(const Route& rhs)
{
    this->legs = rhs.legs;
    const_cast<int & > (this->totalDis) = rhs.totalDis;
    return *this;
}

const Route ShortestRoute::anyRoute(const char* const start, const char* const end)
{
    for(int i = 0; i < ShortestRoute::legSize; i++)
    {
      if(strcmp(ShortestRoute::allLegs[i].endCity, end) == 0) 
        {
         if(strcmp(ShortestRoute::allLegs[i].startCity, start) == 0)
          {
            return Route(ShortestRoute::allLegs[i]);
          }
        else
          {
            return Route(ShortestRoute::anyRoute(start, ShortestRoute::allLegs[i].startCity), allLegs[i]);
          }
        }
    }
    throw "Can not find a possible route!!";
}

const Route ShortestRoute::shortestRoute(const char* const start, const char* const end)
{
   set<Route> allRoutes;// auto sort
   for(int h = 0; h < ShortestRoute::legSize; h++)
    { 
      if(strcmp(ShortestRoute::allLegs[h].endCity, end) == 0)
        {
          if(strcmp(ShortestRoute::allLegs[h].startCity, start) == 0)
           {
             allRoutes.insert(Route(ShortestRoute::allLegs[h]));
           }
           else
           {
            allRoutes.insert(Route(ShortestRoute::shortestRoute(start, ShortestRoute::allLegs[h].startCity), allLegs[h]));
           }
        }
    }
    if(!allRoutes.empty()) return *(allRoutes.begin());
    throw "Can not find the shortest route!!";
}

void Route::output(ostream& cout) const
{
	  cout << legs[0]->startCity;
    for(int k = 0; k < legs.size(); k++)
    {
        cout << " to "<< legs[k]->endCity;
    }
    cout << "," << this->totalDis << " miles" << endl;
}

int main()
{
    cout << "Programmer: ChenYu Yang." << endl;
    cout << "Programmer ID: 1670203." << endl;
    cout << "Lab7: Route.3 " << endl;

    cout << "Shortest route: " << endl;
    const Route route1 = ShortestRoute::shortestRoute("San Francisco", "New York City");
    route1.output(cout);
    
    cout << "Any route: " << endl;
    const Route route2 = ShortestRoute::anyRoute("San Francisco", "New York City");
    route2.output(cout);

    return 0;
}
