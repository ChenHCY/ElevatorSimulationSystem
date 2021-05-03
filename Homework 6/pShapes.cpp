#include "pShapes.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ostream>
using namespace std;

/*
Lab6:pShapes.cpp
Programmer: ChenYu Yang    ID : 1670203
Date : Novermber 04, 2018
*/;

ostream& roundingTwo(ostream&);
ostream& roundingOff(ostream&);

ostream& roundingTwo(ostream& out)
{
	out.setf(ios::fixed);
	out.precision(2); // 2 decimal digits
	return out;
}

ostream& roundingOff(ostream& out)
{
	out.unsetf(ios::fixed);
	out.precision(6); // the C++ default 
	return out;
}

void Square::output(ostream& out) const
{
	const double area = side * side;
	const double perimeter = side * 4.0;
	out << "SQUARE side=" << roundingOff << side << " area=" << roundingTwo << area << " Perimeter=" << perimeter << endl;
}

Square::Square(const vector<string> &s) : side(s.size() > 1 ? atof(s[1].c_str()) : 0)
{

}

Square& Square::operator=(const Square& s)
{
	Square& host = *this;
	if (this != &s)
	{
		const_cast<double&> (host.side) = s.side;
	}
	return host;
}
//-----------------------------------------------------------------------------
void Rectangle::output(ostream& out) const
{
	const double area = length * width;
	const double perimeter = (length + width) * 2;
	out << "RECTANGLE length=" << roundingOff << length << " width=" << width << " area=" << roundingTwo << area << " Perimeter=" << perimeter << endl;
}

Rectangle::Rectangle(vector<string> &r) : length(r.size() > 1 ? atof(r[1].c_str()) : 0), width(r.size() > 2 ? atof(r[2].c_str()) : 0)
{

}

Rectangle& Rectangle::operator=(const Rectangle& r)
{
	Rectangle& host = *this;
	if (this != &r)
	{
		const_cast<double&> (host.length) = r.length;
		const_cast<double&> (host.width) = r.width;
	}
	return host;
}
//---------------------------------------------------------------------------
void Circle::output(ostream& out) const
{
	const double area = radius * radius * 3.14159;
	const double perimeter = radius * 3.14159 * 2;
	out << "CIRCLE radius=" << roundingOff << radius << " area=" << roundingTwo << area << " perimeter=" << perimeter << endl;
}

Circle::Circle(vector<string> &i) : radius(i.size() > 1 ? atof(i[1].c_str()) : 0)
{

}

Circle& Circle::operator=(const Circle& i)
{
	Circle& host = *this;
	if (this != &i)
	{
		const_cast<double&> (host.radius) = i.radius;
	}
	return host;
}
//-----------------------------------------------------------------------------------
void Triangle::output(ostream& out) const
{
	const double area = (side * side * 1.732) / 4.0;
	const double perimeter = side * 3;
	out << "TRIANGLE side=" << roundingOff << side << " area=" << roundingTwo << area << " perimeter=" << perimeter << endl;
}

Triangle::Triangle(vector<string> &t) : side(t.size() > 1 ? atof(t[1].c_str()) : 0)
{

}

Triangle& Triangle::operator=(const Triangle& t)
{
	Triangle& host = *this;
	if (this != &t)
	{
		const_cast<double&> (host.side) = t.side;
	}
	return host;
}
//-----------------------------------------------------------------------------------
void Cube::output(ostream& out) const
{
	const double area = side * side * 6;
	const double volume = side * side * side;
	out << "CUBE side=" << roundingOff << side << " surface area=" << roundingTwo << area << " volume=" << volume << endl;
}

Cube::Cube(vector<string> &u) : Square(u)
{

}

Cube& Cube::operator=(const Cube& u)
{
	Cube& host = *this;
	if (this != &u)
	{
		const_cast<double&> (host.side) = u.side;
	}
	return host;
}
//-------------------------------------------------------------------------------------------------
void Box::output(ostream& out) const
{
	const double area = 2.0 * (height * width + height * length + width * length);
	const double volume = length * width * height;
	out << "BOX length=" << roundingOff << length << " width=" << width << " height=" << height << " surface area=" << roundingTwo << area << " volume=" << volume << endl;
}

Box& Box::operator=(const Box& b)
{
	Box& host = *this;
	if (this != &b)
	{
		const_cast<double&> (host.length) = b.length;
		const_cast<double&> (host.width) = b.width;
		const_cast<double&> (host.height) = b.height;
	}
	return host;
}

Box::Box(vector<string> &b) : Rectangle(b), height(b.size() > 3 ? atof(b[3].c_str()) : 0)
{

}
//------------------------------------------------------------------------------------------------

void Cylinder::output(ostream& out) const
{
	const double area = 2.0 * 3.14159 * radius * (radius + height);
	const double volume = 3.14159 * radius * radius * height;
	out << "CYLINDER radius=" << roundingOff << radius << " height=" << height << " surface area=" << roundingTwo << area << " volume=" << volume << endl;
}

Cylinder& Cylinder::operator=(const Cylinder& y)
{
	Cylinder& host = *this;
	if (this != &y)
	{
		const_cast<double&> (host.height) = y.height;
		const_cast<double&> (host.radius) = y.radius;
	}
	return host;
}

Cylinder::Cylinder(vector<string> &y) : Circle(y), height(y.size() > 2 ? atof(y[2].c_str()) : 0)
{

}

void Prism::output(ostream& out) const
{
	const double volume = (1.73 * side * side * height) / 4.0;
	const double area = 3.0 * (side * height) + (1.73 * side * side) / 2.0;
	out << "PRISM side=" << roundingOff << side << " height=" << height << " surface area=" << roundingTwo << area << " volume=" << volume << endl;
}

Prism::Prism(vector<string> &p) : Triangle(p), height(p.size() > 2 ? atof(p[2].c_str()) : 0)
{

}

Prism& Prism::operator=(const Prism& p)
{
	Prism& host = *this;
	if (this != &p)
	{
		const_cast<double&> (host.side) = p.side;
		const_cast<double&> (host.height) = p.height;
	}
	return host;
}
