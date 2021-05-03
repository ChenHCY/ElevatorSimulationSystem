#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<cstdlib>
#include <map>
#include<cstring>
#include<iomanip>

using namespace std;

/*
Describe: The Lab1 was provided functions such as to calculate area, perimeter, surface area, and volume of common 2D and 3D shapes. It will include
SQUARE, RECTANGLE, CIRCLE, TRIANGLE, CUBE, BOX and CYLINDER. This Lab2 was changed the lab1 to use the objects calculate area and perimeter of the
shapes.
Lab4: Shapes.4
Programmer: ChenYu Yang    ID:1670203
Date: September 24,2018
*/

ostream &outFile(ostream &);

ostream &inputFile(ostream &);


class Shape {

};


class Square : public Shape 
{
    const double side;//the side of square

public:
    Square(const vector<string> token) : side(token[1].c_str() ? atof(token[1].c_str()) : 0) {}

    Square &operator=(const Square &rhs) 
    {
        return *this;
    }

    void output(ostream &out) const 
    {
        const double area = side * side;
        const double perimeter = side * 4;

        out << outFile << "SQUARE side=" << side;
        out << inputFile << " area=" << area << " perimeter=" << perimeter << endl;
    }


};

class Rectangle : public Shape 
{
    const double length;//the side of square
    const double width;

public:
    Rectangle(const vector<string> token) : length(token[1].c_str() ? atof(token[1].c_str()) : 0),
                                            width(token[1].c_str() ? atof(token[2].c_str()) : 0) {}

    Rectangle &operator=(const Rectangle &rhs) { return *this; }

    void output(ostream &out) const 
    {
        const double area = length * width;
        const double perimeter = (length + width) * 2;

        out << outFile << "RECTANGLE length=" << length << " width=" << width;
        out << inputFile << " area=" << area << " perimeter=" << perimeter << endl;
    }
};

class Circle : public Shape 
{
    const double radius;

public:
    Circle(const vector<string> token) : radius(token[1].c_str() ? atof(token[1].c_str()) : 0) {}

    Circle &operator=(const Circle &rhs) { return *this; }

    void output(ostream &out) const 
    {
        const double area = radius * radius * 3.14159;
        const double perimeter = radius * 3.14159 * 2;

        out << outFile << "CIRCLE radius=" << radius;
        out << inputFile << " area=" << area << " perimeter=" << perimeter << endl;
    }
};

class Triangle : public Shape 
{
    const double side;

public:
    Triangle(const vector<string> token) : side(token[1].c_str() ? atof(token[1].c_str()) : 0) {}

    Triangle &operator=(const Rectangle &rhs) { return *this; }

    void output(ostream &out) const
     {
        const double area = side * side * 1.732 / 4.0;
        const double perimeter = side * 3;

        out << outFile << "TRIANGLE side= " << side;
        out << inputFile << " area=" << area << " perimeter=" << perimeter << endl;
    }
};

class Cube : public Shape 
{
    const double side;

public:
    Cube(const vector<string> token) : side(token[1].c_str() ? atof(token[1].c_str()) : 0) {}

    Cube &operator=(const Cube &rhs) { return *this; }

    void output(ostream &out) const 
    {
        const double area = side * side * 6;
        const double volume = side * side * side;

        out << outFile << "CUBE side=" << side;
        out << inputFile << " area=" << area << " volume=" << volume << endl;
    }
};

class Box : public Shape 
{
    double length;//the length of Box
    double width;//the width of Box
    double height;//the height of Box
public:

    Box(const vector<string> token) : length(token[1].c_str() ? atof(token[1].c_str()) : 0),
                                      width(token[1].c_str() ? atof(token[2].c_str()) : 0),
                                      height(token[2].c_str() ? atof(token[3].c_str()) : 0) {}

    Box &operator=(const Cube &rhs) { return *this; }

    void output(ostream &out) const 
    {
        double area = 2 * (height * width) + 2 * (height * length) + 2 * (width * length);
        double volume = length * width * height;

        out << outFile << "Box length=" << length << " width=" << width << " height=" << height;
        out << inputFile << " area=" << area << " volume=" << volume << endl;
    }
};

class Cylinder : public Shape 
{
    double radius;
    double height;
public:

    Cylinder(const vector<string> token) : radius(token[1].c_str() ? atof(token[1].c_str()) : 0),
                                           height(token[1].c_str() ? atof(token[2].c_str()) : 0) {}

    Cylinder &operator=(const Cylinder &rhs) { return *this; }

    void output(ostream &out) const 
    {
        double area = (2 * 3.1415926 * radius * radius) + (2 * 3.1415926 * radius * height);
        double volume = 3.1415926 * radius * radius * height;

        out << outFile << "CYLINDER radius=" << radius << " height=" << height;
        out << inputFile << " area=" << area << " volume=" << volume << endl;
    }
};

class Prism : public Shape 
{
    double side;//the side of Prism
    double height;//the height of Prism
public:
    Prism(const vector<string> token) : side(token[1].c_str() ? atof(token[1].c_str()) : 0),
                                        height(token[1].c_str() ? atof(token[2].c_str()) : 0) {}

    Prism &operator=(const Prism &rhs) { return *this; }

    void output(ostream &out) const 
    {
        double area = (1.73 * side * side * height) / 4.0;
        double volume = 3.0 * (side * height) + (1.73 * side * side) / 2.0;

        out << outFile << "CYLINDER radius=" << side << " height=" << height;
        out << inputFile << " area=" << area << " volume=" << volume << endl;
    }
};


class InvalidObj : public Shape 
{
public:
    const string name;

    InvalidObj(string name) : name(name) {}
};
const string SHAPES[8] = {"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"};

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) 
    {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    strs.erase(std::remove_if(
            strs.begin(), strs.end(), 
            [](const string& s) {
                return s == "" || s == "\r"; // put your condition here
            }
        ), strs.end());

    return strs.size();
}

bool valid_blank_all (string s) 
{
    bool all = true;
    for (int i = 0; i < s.size(); i++) {
        all = (s[i] == ' '); // false if
    }
    return all;
}
int main() 
{
    cout << "Programmer: ChenYu Yang." << endl;
    cout << "Programmer ID: 1670203." << endl;
    cout << "Lab4: Shapes.4 " << endl;

    ifstream infile("Shapes.input.txt");
    ofstream out;
    out.open("Shapes.output.txt");
    stringstream sstr;
    if (!infile.is_open()) 
    {
        cout << "Unable to open the files! " << endl;;
        exit(1);
    }

    string line;
    string shape;

    vector<Shape *> myBag;
    vector<char> myBagType;
    vector<InvalidObj*> invs;

    const int maxNum = 3;
    vector<string> batch;

    while (getline(infile, line)) 
    {
//        cout << line << endl;
        batch.clear();
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
//        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

        if (line.empty()) continue;
        split(line, batch, ' ');

        if (batch[0] == "SQUARE") 
        {
            Square *s = new Square(batch);
            myBag.push_back(s);
            myBagType.push_back('0');
        } 
        else if (batch[0] == "RECTANGLE") 
        {
            Rectangle *s = new Rectangle(batch);
            myBag.push_back(s);
            myBagType.push_back('1');
        }
        else if (batch[0] == "CIRCLE") 
        {
            Circle *s = new Circle(batch);
            myBag.push_back(s);
            myBagType.push_back('2');
        } 
        else if (batch[0] == "TRIANGLE") 
        {
            Triangle *s = new Triangle(batch);
            myBag.push_back(s);
            myBagType.push_back('3');
        } 
        else if (batch[0] == "CUBE") 
        {
            Cube *s = new Cube(batch);
            myBag.push_back(s);
            myBagType.push_back('4');
        }
        else if (batch[0] == "BOX") 
        {
            Box *s = new Box(batch);
            myBag.push_back(s);
            myBagType.push_back('5');
        }
        else if (batch[0] == "CYLINDER")
        {
            Cylinder *s = new Cylinder(batch);
            myBag.push_back(s);
            myBagType.push_back('6');
        }
        else if (batch[0] == "PRISM") 
        {
            Prism* s = new Prism(batch);
            myBag.push_back(s);
            myBagType.push_back('7');
        }
        else if (batch[0] == "EOF")
        {
            break;
        }
        else
        {
            invs.push_back(new InvalidObj(batch[0]));
        }
    }

    vector<Shape*> v_collects;
    vector<Shape*> iv_collects;

    for (int i = 0; i < invs.size(); i++) 
    {
        string name = invs[i]->name;
        if (!valid_blank_all(name)) 
        {
            cout << (invs[i]) -> name << "  invalid object" << endl;
        }
    }
    for (int i = 0; i < myBagType.size(); i++)
    {
        if (myBagType[i] == '0')
        {
            ((Square *) (myBag[i]))->output(cout);
        }
        else if (myBagType[i] == '1')
        {
            ((Rectangle *) (myBag[i]))->output(cout);
        }
        else if (myBagType[i] == '2')
        {
            ((Circle *) (myBag[i]))->output(cout);
        }
        else if (myBagType[i] == '3')
        {
            ((Triangle *) (myBag[i]))->output(cout);
        }
        else if (myBagType[i] == '4')
        {
            ((Cube *) (myBag[i]))->output(cout);
        }
        else if (myBagType[i] == '5')
        {
            ((Box *) (myBag[i]))->output(cout);
        }
        else if (myBagType[i] == '6')
        {
            ((Cylinder *) (myBag[i]))->output(cout);
        }
        else if (myBagType[i] == '7') {
            ((Prism *) (myBag[i]))->output(cout);
        }
    }
}

ostream &outFile(ostream &out) // requires iostream, using ostream
{
    out.unsetf(ios::fixed | ios::showpoint); // requires iostream, using ios
    out << setprecision(6); // requires iostream and iomanip, using setprecision
    return out;
}

ostream &inputFile(ostream &out) // requires iostream, using ostream
{
    out.setf(ios::fixed | ios::showpoint); // requires iostream, using ios
    out << setprecision(2); // requires iostream and iomanip, using setprecision
    return out;
}
