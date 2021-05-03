#include "iShapes.h"

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
Describe: The Lab1 was provided functions such as to calculate area, perimeter, surface area, and volume of common 2D and 3D shapes. It will include
SQUARE, RECTANGLE, CIRCLE, TRIANGLE, CUBE, BOX and CYLINDER.
The Lab2 was changed the lab1 to use the objects calculate area and perimeter of the shapes.
The Lab3 was use the Member Function, Stream Manipulators, and Conditional Operators to change the Lab 2.
Lab5: Shapes.5
Programmer: ChenYu Yang    ID:1670203
Date: Novermber 04,2018
*/

vector<string> parseString(string); // prototype
									//Gets tokens and places them in a vector
vector<string> parseString(string str)
{
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}

int main()
{
	//Programmer's identification
	cout << "Programmer: ChenYu Yang." << endl;
	cout << "Programmer ID: 1670203." << endl;
	cout << "Lab5: Shapes.5 " << endl;

	vector <const Shape*> myBag;
	vector <char> myBagType;
	string line = " ";
	string tempBase = " ";
	string tempHeight = " ";
	string tempWidth = " ";
	ifstream infile;
	ofstream out;
	infile.open("Shapes.input.txt");
	out.open("Shapes.output.txt");

	//checks if file is open
	if (!infile)
	{
		cout << "ERROR: unable to open file" << endl;
	}

	// Checks each shape 1 by 1 and calculates accordingly; ignores spaces
	while (getline(infile, line))
	{
		vector<string> tokens = parseString(line);

		if (tokens.size() == 0)
		{
			cout << "";
			continue;
		}
		tempBase = tokens[0];
		while (tempBase == " ")
		{
			vector<string> tokens = parseString(line);
			tempBase = tokens[0];
			cout << tempBase << endl;
		}
		if (tempBase == "SQUARE")
		{
			const Shape* const s = new Square(tokens);
			myBag.push_back(s);
			myBagType.push_back('s');
		}

		else if (tempBase == "TRIANGLE")
		{
			const Shape* const t = new Triangle(tokens);
			myBag.push_back(t);
			myBagType.push_back('t');
		}

		else if (tempBase == "RECTANGLE")
		{
			const Shape* const r = new Rectangle(tokens);
			myBag.push_back(r);
			myBagType.push_back('r');
		}

		else if (tempBase == "CYLINDER")
		{
			const Shape* const y = new Cylinder(tokens);
			myBag.push_back(y);
			myBagType.push_back('y');
		}

		else if (tempBase == "BOX")
		{
			const Shape* const b = new Box(tokens);
			myBag.push_back(b);
			myBagType.push_back('b');
		}

		else if (tempBase == "CIRCLE")
		{
			const Shape* const i = new Circle(tokens);
			myBag.push_back(i);
			myBagType.push_back('i');
		}

		else if (tempBase == "PRISM")
		{
			const Shape* const p = new Prism(tokens);
			myBag.push_back(p);
			myBagType.push_back('p');
		}

		else if (tempBase == "CUBE")
		{
			const Shape* const u = new Cube(tokens);
			myBag.push_back(u);
			myBagType.push_back('u');
		}

		else
		{
			tempBase == tokens[0];
			cout << tempBase << " INVALID OBJECT" << endl;
		}

	}

	//console output loop
    for (int i = 0; i < myBag.size(); i++)
	{
		if (myBagType[i] == 's')
		{
			const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
			const Square& rSquare = *pSquare;
			rSquare.output(cout);
		}

		if (myBagType[i] == 't')
		{
			const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
			const Triangle& rTriangle = *pTriangle;
			rTriangle.output(cout);
		}

		if (myBagType[i] == 'r')
		{
			const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
			const Rectangle& rRectangle = *pRectangle;
			rRectangle.output(cout);
		}

		if (myBagType[i] == 'i')
		{
			const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
			const Circle& rCircle = *pCircle;
			rCircle.output(cout);
		}

		if (myBagType[i] == 'b')
		{
			const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
			const Box& rBox = *pBox;
			rBox.output(cout);
		}

		if (myBagType[i] == 'y')
		{
			const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
			const Cylinder& rCylinder = *pCylinder;
			rCylinder.output(cout);
		}

		if (myBagType[i] == 'p')
		{
			const Prism* pPrism = reinterpret_cast<const Prism*>(myBag[i]);
			const Prism& rPrism = *pPrism;
			rPrism.output(cout);
		}

		if (myBagType[i] == 'u')
		{
			const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
			const Cube& rCube = *pCube;
			rCube.output(cout);
		}
	}

	//TXT input
	for (int i = 0; i < myBag.size(); i++)
	{
		if (myBagType[i] == 's')
		{
			const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
			const Square& rSquare = *pSquare;
			rSquare.output(out);
		}

		if (myBagType[i] == 't')
		{

			const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
			const Triangle& rTriangle = *pTriangle;
			rTriangle.output(out);
		}

		if (myBagType[i] == 'r')
		{
			const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
			const Rectangle& rRectangle = *pRectangle;
			rRectangle.output(out);
		}

		if (myBagType[i] == 'i')
		{
			const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
			const Circle& rCircle = *pCircle;
			rCircle.output(out);
		}

		if (myBagType[i] == 'b')
		{
			const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
			const Box& rBox = *pBox;
			rBox.output(out);
		}

		if (myBagType[i] == 'y')
		{
			const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
			const Cylinder& rCylinder = *pCylinder;
			rCylinder.output(out);
		}

		if (myBagType[i] == 'p')
		{
			const Prism* pPrism = reinterpret_cast<const Prism*>(myBag[i]);
			const Prism& rPrism = *pPrism;
			rPrism.output(out);
		}

		if (myBagType[i] == 'u')
		{
			const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
			const Cube& rCube = *pCube;
			rCube.output(out);
		}
	}

	out.close();

	const Square* s;
	const Cylinder* y;
	const Rectangle* r;
	const Triangle* t;
	const Cube* u;
	const Prism* p;
	const Circle* i;
	const Box* b;

	for (int j = myBag.size(); !myBag.empty(); j++)
	{
		if (myBagType[j] == 's')
		{
			s = reinterpret_cast<const Square*>(myBag[j]);
			delete s;
		}

		if (myBagType[j] == 'r')
		{
			r = reinterpret_cast<const Rectangle*>(myBag[j]);
			delete r;
		}

		if (myBagType[j] == 'i')
		{
			i = reinterpret_cast<const Circle*>(myBag[j]);
			delete i;
		}

		if (myBagType[j] == 't')
		{
			t = reinterpret_cast<const Triangle*>(myBag[j]);
			delete t;
		}

		if (myBagType[j] == 'u')
		{
			u = reinterpret_cast<const Cube*>(myBag[j]);
			delete u;
		}

		if (myBagType[j] == 'b')
		{
			b = reinterpret_cast<const Box*>(myBag[j]);
			delete b;
		}

		if (myBagType[j] == 'y')
		{
			y = reinterpret_cast<const Cylinder*>(myBag[j]);
			delete y;
		}

		if (myBagType[j] == 'p')
		{
			p = reinterpret_cast<const Prism*>(myBag[j]);
			delete p;
		}
	}
	s = NULL;
	y = NULL;
	r = NULL;
	t = NULL;
	u = NULL;
	p = NULL;
	i = NULL;
	b = NULL;
	return 0;
}