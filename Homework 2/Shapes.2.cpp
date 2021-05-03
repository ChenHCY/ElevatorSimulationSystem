#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdlib.h>
#include<map>
#include<iomanip>
using namespace std;

/*
Describe: The Lab1 was provided functions such as to calculate area, perimeter, surface area, and volume of common 2D and 3D shapes. It will include
SQUARE, RECTANGLE, CIRCLE, TRIANGLE, CUBE, BOX and CYLINDER. This Lab2 was changed the lab1 to use the objects calculate area and perimeter of the
shapes.
Lab2: Shapes.2
Programmer: ChenYu Yang    ID:1670203
Date: September 09,2018
*/

struct Square
{
	double side;//the side of square
};

struct Rectangle
{
	double length;//the length of Rectangle
	double width;//the width of Rectangle
};

struct Circle
{
	double radius;//the radius of Circle
};

struct Triangle
{
	double side;//the side of Triangle
};

struct Cube
{
	double side;//the side of Cube
};

struct Box
{
	double length;//the length of Box
	double width;//the width of Box
	double height;//the height of Box
};

struct Cylinder
{
	double radius;//the radius of Cylinder
	double height;//the height of Cylinder
};

struct Prism
{
	double side;//the side of Prism 
	double height;//the height of Prism 
};

void outputSquare(ostream&, const Square&);
void outputRectangle(ostream&, const Rectangle&);
void outputCircle(ostream&, const Circle&);
void outputTriangle(ostream&, const Triangle&);
void outputCube(ostream&, const Cube&);
void outputBox(ostream&, const Box&);
void outputCylinder(ostream&, const Cylinder&);
void outputPrism(ostream&, const Prism&);

void outputSquare(ostream& out, const Square& s)
{
	double area = s.side * s.side;
	double perimeter = 4 * s.side;
	cout << "SQUARE side= " << s.side << " area= " << fixed << setprecision(2) << area << " perimeter= " << fixed << setprecision(2) << perimeter << endl;
	out << "SQUARE side= " << s.side << " area= " << fixed << setprecision(2) << area << " perimeter= " << fixed << setprecision(2) << perimeter << endl;
}

void outputRectangle(ostream& out, const Rectangle& r)
{
	double area = r.length * r.width;
	double perimeter = 2 * r.length + 2 * r.width;
	cout << "RECTANGLE length= " << r.length << " width= " << r.width << " area= " << fixed << setprecision(2) << area << " perimeter= " << fixed << setprecision(2) << perimeter << endl;
	out << "RECTANGLE length= " << r.length << " width= " << r.width << " area= " << fixed << setprecision(2) << area << " perimeter= " << fixed << setprecision(2) << perimeter << endl;
}

void outputCircle(ostream& out, const Circle& c)
{
	double pi = 3.14159;
	double area = pi * c.radius * c.radius;
	double perimeter = 2 * pi* c.radius;
	cout << "CIRCLE radius= " << c.radius << " area= " << fixed << setprecision(2) << area << " perimeter= " << fixed << setprecision(2) << perimeter << endl;
	out << "CIRCLE radius= " << c.radius << " area= " << fixed << setprecision(2) << area << " perimeter= " << fixed << setprecision(2) << perimeter << endl;
}

void outputTriangle(ostream& out, const Triangle& t)
{
	double area = (1.732 * t.side) / 4.0;
	double perimeter = 3 * t.side;
	cout << "TRIANGLE side= " << t.side << " area= " << fixed << setprecision(2) << area << " perimeter= " << fixed << setprecision(2) << perimeter << endl;
	out << "TRIANGLE side= " << t.side << " area= " << fixed << setprecision(2) << area << " perimeter= " << fixed << setprecision(2) << perimeter << endl;
}

void outputCube(ostream& out, const Cube& a)
{
	double volume = a.side * a.side * a.side;
	double area = 6 * a.side * a.side;
	cout << "CUBE side= " << a.side << " Surface area= " << fixed << setprecision(2) << area << " volume= " << fixed << setprecision(2) << volume << endl;
	out << "CUBE side= " << a.side << " Surface area= " << fixed << setprecision(2) << area << " volume= " << fixed << setprecision(2) << volume << endl;
}

void outputBox(ostream& out, const Box& b)
{
	double area = 2 * (b.height * b.width) + 2 * (b.height * b.length) + 2 * (b.width * b.length);
	double volume = b.length * b.width * b.height;
	cout << "BOX length= " << b.length << " width = " << b.width << " height = " << b.height << " Surface Area = " << fixed << setprecision(2) << area << " Volume = " << fixed << setprecision(2) << volume << endl;
	out << "BOX length= " << b.length << " width = " << b.width << " height = " << b.height << " Surface Area = " << fixed << setprecision(2) << area << " Volume = " << fixed << setprecision(2) << volume << endl;
}

void outputCylinder(ostream& out, const Cylinder& y)
{
	double pi = 3.14159;
	double area = (2 * pi * y.radius * y.radius) + (2 * pi * y.radius * y.height);
	double volume = pi * y.radius * y.radius * y.height;
	cout << "CYLINDER radius= " << y.radius << " height= " << y.height << " Surface Area= " << fixed << setprecision(2) << area << " Volume= " << fixed << setprecision(2) << volume << endl;
	out << "CYLINDER radius= " << y.radius << " height= " << y.height << " Surface Area= " << fixed << setprecision(2) << area << " Volume= " << fixed << setprecision(2) << volume << endl;
}

void outputPrism(ostream& out, const Prism& p)
{
	double volume = (1.73 * p.side * p.side * p.height) / 4.0;
	double area = 3.0 * (p.side * p.height) + (1.73 * p.side * p.side) / 2.0;
	cout << "Prism side= " << p.side << " height=" << p.height << " surface area=" << fixed << setprecision(2) << area << " volume=" << fixed << setprecision(2) << volume << endl;
	out << "Prism side= " << p.side << " height=" << p.height << " surface area=" << fixed << setprecision(2) << area << " volume=" << fixed << setprecision(2) << volume << endl;
}

int main()
{
	//Programmer's identification
	cout << "Programmer: ChenYu Yang." << endl;
	cout << "Programmer ID: 1670203." << endl;
	cout << "Lab2: Shapes.2 " << endl;

	ifstream infile("Shapes.input.txt");
	ofstream out("Shapes.output.txt");

	if (!infile || !out)
	{
		cout << "Unable to open the files! " << endl;;
		exit(1);
	}

	string shape;
	vector<void*> myBag;
	vector<char> myBagType;
	Square *s = new Square();
	Rectangle *r = new Rectangle();
	Circle *c = new Circle();
	Triangle *t = new Triangle();
	Cube *a = new Cube();
	Box *b = new Box();
	Cylinder *y = new Cylinder();
	Prism *p = new Prism();

	map<string, int> shapes;
	shapes.insert(pair<string, int>("SQUARE", 1));
	shapes.insert(pair<string, int>("RECTANGLE", 2));
	shapes.insert(pair<string, int>("CIRCLE", 3));
	shapes.insert(pair<string, int>("TRIANGLE", 4));
	shapes.insert(pair<string, int>("CUBE", 5));
	shapes.insert(pair<string, int>("BOX", 6));
	shapes.insert(pair<string, int>("CYLINDER", 7));
	shapes.insert(pair<string, int>("PRISM", 8));

	for (string line; getline(infile, line);)
	{
		string tok;
		stringstream sstr;
		while (getline(sstr, tok, ''))
		{
			if (tok == "")
				continue;
			myBag.push_back(tok);
		}
		if (sstr >> shape)
		{
			switch (shapes[shape])
			{
			case 1: //area and perimeter of a 2D Square
				myBag.push_back(s);
				myBagType.push_back('s');
				sstr >> s->side;
				break;

			case 2: //area and perimeter of a 2D Rectangle
				myBag.push_back(r);
				myBagType.push_back('r');
				sstr >> r->length >> r->width;
				break;

			case 3: //area and perimeter of a 2D Circle
				myBag.push_back(c);
				myBagType.push_back('c');
				sstr >> c->radius;
				break;

			case 4: //area and perimeter of an 2D equilateral Triangle
				myBag.push_back(t);
				myBagType.push_back('t');
				sstr >> t->side;
				break;

			case 5: //surface area and volume of a 3D Cube (a 2D square with a 3rd dimension)
				myBag.push_back(a);
				myBagType.push_back('a');
				sstr >> a->side;
				break;

			case 6: //surface area and volume of a Box (a 2D rectangle with a 3rd dimension)
				myBag.push_back(b);
				myBagType.push_back('b');
				sstr >> b->length >> b->width >> b->height;
				break;

			case 7: //surface area and volume of a Cylinder (a 2D circle with a 3rd dimension)
				myBag.push_back(y);
				myBagType.push_back('y');
				sstr >> y->radius >> y->height;
				break;

			case 8: //surface area and volume of a Prism (a 2D equilateral triangle with a 3rd dimension)
				myBag.push_back(p);
				myBagType.push_back('p');
				sstr >> p->side >> p->height;

			default:
				cout << myBag[0] << " Invalid Object!" << endl;
				out << myBag[0] << " Invalid Object!" << endl;
			}
		}

			for (int i = 0; i < myBag.size(); i++)
			{
				if (myBagType[i] == 's')
				{
					outputSquare(out, *s);
				}
				else if (myBagType[i] == 'r')
				{
					outputRectangle(out, *r);
				}
				else if (myBagType[i] == 'c')
				{
					outputCircle(out, *c);
				}
				else if (myBagType[i] == 't')
				{
					outputTriangle(out, *t);
				}
				else if (myBagType[i] == 'c')
				{
					outputCube(out, *a);
				}
				else if (myBagType[i] == 'b')
				{
					outputBox(out, *b);
				}
				else if (myBagType[i] == 'c')
				{
					outputCylinder(out, *y);
				}
				else if (myBagType[i] == 'p')
				{
					outputPrism(out, *p);
				}
	         }
		infile.close();
		out.close();
	}
	return 0;
}