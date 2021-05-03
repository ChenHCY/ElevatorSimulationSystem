#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdlib.h>
#include<iomanip>
using namespace std;

/*
Describe: The Lab1 was provided functions such as to calculate area, perimeter, surface area, and volume of common 2D and 3D shapes. It will include
SQUARE, RECTANGLE, CIRCLE, TRIANGLE, CUBE, BOX and CYLINDER.
The Lab2 was changed the lab1 to use the objects calculate area and perimeter of the shapes.
The Lab3 was use the Member Function, Stream Manipulators, and Conditional Operators to change the Lab 2.
Lab2: Shapes.3
Programmer: ChenYu Yang    ID:1670203
Date: September 16,2018
*/

struct Square
{
	double side;//the side of square
	void output(vector<string> myBag, ostream&) const;
};

struct Rectangle
{
	double length;//the length of Rectangle
	double width;//the width of Rectangle
	void output(vector<string> myBag, ostream&) const;
};

struct Circle
{
	double radius;//the radius of Circle
	void output(vector<string> myBag, ostream&) const;
};

struct Triangle
{
	double side;//the side of Triangle
	void output(vector<string> myBag, ostream&) const;
};

struct Cube
{
	double side;//the side of Cube
	void output(vector<string> myBag, ostream&) const;
};

struct Box
{
	double length;//the length of Box
	double width;//the width of Box
	double height;//the height of Box
	void output(vector<string> myBag, ostream&) const;
};

struct Cylinder
{
	double radius;//the radius of Cylinder
	double height;//the height of Cylinder
	void output(vector<string> myBag, ostream&) const;
};

struct Prism
{
	double side;//the side of Prism 
	double height;//the height of Prism 
	void output(vector<string> myBag, ostream&) const;
};

// prototype
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


void Square::output(vector<string> myBag, ostream& out) const
{
	Square* s = new Square();
	s->side = ((myBag.size() > 1) ? atof(myBag[1].c_str()) : 0);
	double area = s->side * s->side;
	double perimeter = 4 * s->side;
	cout << "SQUARE side= " << roundingOff << s->side << " area= " << roundingTwo << area << " perimeter= " << perimeter << endl;
	out << "SQUARE side= " << roundingOff << s->side << " area= " << roundingTwo << area << " perimeter= " << perimeter << endl;
}

void Rectangle::output(vector<string> myBag, ostream& out) const
{
	Rectangle* r = new Rectangle();
	r->length = ((myBag.size() >= 2) ? atof(myBag[1].c_str()) : 0);
	r->width = ((myBag.size() >= 3) ? atof(myBag[2].c_str()) : 0);
	double area = r->length * r->width;
	double perimeter = 2 * r->length + 2 * r->width;
	cout << "Rectangle length= " << roundingOff << r->length << " width= " << r->width << " area= " << roundingTwo << area << " perimeter= " << perimeter << endl;
	out << "Rectangle length= " << roundingOff << r->length << " width= " << r->width << " area= " << roundingTwo << area << " perimeter= " << perimeter << endl;
}

void Circle::output(vector<string> myBag, ostream& out) const
{
	Circle* c = new Circle();
	c->radius = ((myBag.size() > 1) ? atof(myBag[1].c_str()) : 0);
	double pi = 3.14159;
	double area = pi * c->radius * c->radius;
	double perimeter = 2 * pi* c->radius;
	cout << "CIRCLE radius= " << roundingOff << c->radius << " area= " << roundingTwo << area << " perimeter= " << perimeter << endl;
	out << "CIRCLE radius= " << roundingOff << c->radius << " area= " << roundingTwo << area << " perimeter= " << perimeter << endl;
}

void Triangle::output(vector<string> myBag, ostream& out) const
{
	Triangle* t = new Triangle();
	t->side = ((myBag.size() > 1)? atof(myBag[1].c_str()) : 0);
	double area = (1.732 * t->side) / 4.0;
	double perimeter = 3 * t->side;
	cout << "TRIANGLE side= " << roundingOff << t->side << " area= " << roundingTwo << area << " perimeter= " << perimeter << endl;
	out << "TRIANGLE side= " << roundingOff << t->side << " area= " << roundingTwo << area << " perimeter= " << perimeter << endl;
}

void Cube::output(vector<string> myBag, ostream& out) const
{
	Cube* a = new Cube();
	a->side = ((myBag.size() > 1)? atof(myBag[1].c_str()) : 0);
	double volume = a->side * a->side * a->side;
	double surfaceArea = 6 * a->side * a->side;
	cout << "CUBE side= " << roundingOff << a->side << " Surface area= " << roundingTwo << surfaceArea << " volume= " << volume << endl;
	out << "CUBE side= " << roundingOff << a->side << " Surface area= " << roundingTwo << surfaceArea << " volume= " << volume << endl;
}

void Box::output(vector<string> myBag, ostream& out) const
{
	Box* b = new Box();
	b->length = ((myBag.size() >= 2)? atof(myBag[1].c_str()) : 0);
	b->width = ((myBag.size() >= 3)? atof(myBag[2].c_str()) : 0);
	b->height = ((myBag.size() >= 4)? atof(myBag[3].c_str()) : 0);
	double surfaceArea = 2 * (b->height * b->width) + 2 * (b->height * b->length) + 2 * (b->width * b->length);
	double volume = b->length * b->width * b->height;
	cout << "BOX length= " << roundingOff << b->length << " width = " << b->width << " height = " << b->height << " Surface Area = " << roundingTwo << surfaceArea << " Volume = " << volume << endl;
	out << "BOX length= " << roundingOff << b->length << " width = " << b->width << " height = " << b->height << " Surface Area = " << roundingTwo << surfaceArea << " Volume = " << volume << endl;
}

void Cylinder::output(vector<string> myBag, ostream& out) const
{
	Cylinder* y = new Cylinder();
	y->radius = ((myBag.size() >= 2)? atof(myBag[1].c_str()) : 0);
	y->height = ((myBag.size() >= 3)? atof(myBag[2].c_str()) : 0);
	double pi = 3.14159;
	double surfaceArea = (2 * pi * y->radius * y->radius) + (2 * pi * y->radius * y->height);
	double volume = pi * y->radius * y->radius * y->height;
	cout << "CYLINDER radius= " << roundingOff << y->radius << " height= " << y->height << " Surface Area= " << roundingTwo << surfaceArea << " Volume= " << volume << endl;
	out << "CYLINDER radius= " << roundingOff << y->radius << " height= " << y->height << " Surface Area= " << roundingTwo << surfaceArea << " Volume= " << volume << endl;
}

void Prism::output(vector<string> myBag, ostream& out) const
{
	Prism* p = new Prism();
    p->side = ((myBag.size() >= 2)? atof(myBag[1].c_str()) : 0);
	p->height = ((myBag.size() >= 3)? atof(myBag[2].c_str()) : 0);
	double volume = (1.732 * p->side * p->side * p->height) / 4.0;
	double area = 3.0 * (p->side * p->height) + (1.732 * p->side * p->side) / 2.0;
	cout << "Prism side= " << roundingOff << p->side << " height=" << p->height << " surface area=" << roundingTwo << area << " volume=" << volume << endl;
	out << "Prism side= " << roundingOff << p->side << " height=" << p->height << " surface area=" << roundingTwo << area << " volume=" << volume << endl;
}

int main()
{
	//Programmer's identification
	cout << "Programmer: ChenYu Yang." << endl;
	cout << "Programmer ID: 1670203." << endl;
	cout << "Lab3: Shapes.3 " << endl;

	ifstream infile("Shapes.input.txt");
	ofstream out;
	out.open("Shapes.output.txt");
	Square square;
	Rectangle rectangle;
	Circle circle;
	Triangle triangle;
	Cube cube;
	Box box;
	Cylinder cylinder;
	Prism prism;

	if (!infile || !out)
	{
		cout << "Unable to open files" << endl;
		exit(1);
	}

	for (string line; getline(infile, line);)
	{
		string tok;
		stringstream ss(line);
		vector<string> myBag;
		vector<char> myBagType;
		while (getline(ss, tok, ' '))
		{
			if (tok == "")
				continue;
			myBag.push_back(tok);
		}
		for (int i = 0; i < myBag.size(); i--)
		{
			if (myBag[i] == "SQUARE")
			{
				square.output(myBag, out);
			}
			else if (myBag[i] == "RECTANGLE")
			{
				rectangle.output(myBag, out);
			}
			else if (myBag[i] == "CIRCLE")
			{
				circle.output(myBag, out);
			}
			else if (myBag[i] == "TRIANGLE")
			{
				triangle.output(myBag, out);
			}
			else if (myBag[i] == "CUBE")
			{
				cube.output(myBag, out);
			}
			else if (myBag[i] == "BOX")
			{
				box.output(myBag, out);
			}
			else if (myBag[i] == "CYLINDER")
			{
				cylinder.output(myBag, out);
			}
			else if (myBag[i] == "PRISM")
			{
				prism.output(myBag, out);
			}
			else if (myBag[i] == "EOF")
			{
				break;
			}
			else
			{
				cout << myBag[i] << " Invalid Object" << endl;
				out << myBag[i] << " Invalid Object" << endl;
			}
		}
	}
	infile.close();
	out.close();
	return 0;
}