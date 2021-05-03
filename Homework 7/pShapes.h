#ifndef PSHAPES_H
#define PSHAPES_H

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
Lab6: pShapes.h
Programmer: ChenYu Yang    ID : 1670203
Date : Novermber 04, 2018
*/

struct Shape
{
	virtual void output(ostream&) const = 0;
	virtual ~Shape() {}
};

ostream& operator<<(ostream&, const Shape* const);

class Square : public Shape
{
protected:
	const double side;
public:
	void output(ostream&) const;
	Square& operator=(const Square&);
	Square(const vector<string>&);
};

namespace comsc
{
   class Rectangle : public Shape
	{
	protected:
		const double length;
		const double width;

	public:
		Rectangle & operator=(const Rectangle&);
		Rectangle(vector<string>&);
		void output(ostream&) const;
	};
}

class Circle : public Shape
{
protected:
	const double radius;

public:
	Circle & operator=(const Circle&);
	Circle(vector<string>&);
	void output(ostream&) const;
};

class Triangle : public Shape
{
protected:
	const double side;
public:
	Triangle & operator=(const Triangle&);
	Triangle(vector<string>&);
	void output(ostream&) const;
};

class Cube : public Square
{
public:
	Cube & operator=(const Cube&);
	Cube(vector<string>&);
	void output(ostream&) const;
};

class Box : public comsc::Rectangle
{
protected:
	const double height;

public:
	Box & operator=(const Box&);
	Box(vector<string>&);
	void output(ostream&) const;
};

class Cylinder : public Circle
{
protected:
	const double height;

public:
	Cylinder & operator=(const Cylinder&);
	Cylinder(vector<string>&);
	void output(ostream&) const;
};

class Prism : public Triangle
{
protected:
	const double height;

public:
	Prism & operator=(const Prism&);
	Prism(vector<string>&);
	void output(ostream&) const;
};

#endif
