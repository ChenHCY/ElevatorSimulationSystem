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
Describe: The Lab1 was provided functions such as to calculate area, perimeter, surface area, and volume of common 2D and 3D shapes. It will include
SQUARE, RECTANGLE, CIRCLE, TRIANGLE, CUBE, BOX and CYLINDER.
The Lab2 was changed the lab1 to use the objects calculate area and perimeter of the shapes.
The Lab3 was use the Member Function, Stream Manipulators, and Conditional Operators to change the Lab 2.
Lab6: Shapes.6
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

ostream& operator<<(ostream& out, const Shape* const c)
{
    c->output(out);
    return out;
}

int main()
{
	//Programmer's identification
	cout << "Programmer: ChenYu Yang." << endl;
	cout << "Programmer ID: 1670203." << endl;
	cout << "Lab6: Shapes.6 " << endl;

	vector <const Shape*> myBag;
	string line = " ";
	string tempBase = " ";
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
		}

		else if (tempBase == "TRIANGLE")
		{
			const Shape* const t = new Triangle(tokens);
			myBag.push_back(t);
		}

		else if (tempBase == "RECTANGLE")
		{
			const Shape* const r = new Rectangle(tokens);
			myBag.push_back(r);
		}

		else if (tempBase == "CYLINDER")
		{
			const Shape* const y = new Cylinder(tokens);
			myBag.push_back(y);
		}

		else if (tempBase == "BOX")
		{
			const Shape* const b = new Box(tokens);
			myBag.push_back(b);
		}

		else if (tempBase == "CIRCLE")
		{
			const Shape* const i = new Circle(tokens);
			myBag.push_back(i);
		}

		else if (tempBase == "PRISM")
		{
			const Shape* const p = new Prism(tokens);
			myBag.push_back(p);
		}

		else if (tempBase == "CUBE")
		{
			const Shape* const u = new Cube(tokens);
			myBag.push_back(u);
		}

		else
		{
			cout << tokens[0] << " INVALID OBJECT" << endl;
			out << tokens[0] << " INVALID OBJECT" << endl;
		}

	}
	//console output loop
	for (int i = 0; i < myBag.size(); i++)
	{
        cout << myBag[i];
	}

	//TXT input
	for (int i = 0; i < myBag.size(); i++)
	{
		out << myBag[i];
	}

	out << "EOF";
	out.close();

	for (int i = 0; i < myBag.size(); i++)
	{
		delete myBag[i];
	}
	return 0;
}
