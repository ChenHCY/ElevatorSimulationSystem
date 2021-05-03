#include<fstream>
#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
/*
   This program provided functions such as to calculate area, perimeter, surface area, and volume of common 2D and 3D shapes. It will include
   SQUARE, RECTANGLE, CIRCLE, TRIANGLE, CUBE, BOX, CYLINDER, and PRISM.
   Lab1: Shapes v.1
   Programmer: ChenYu Yang    ID:1670203
   Date: September 02,2018
*/

int main() 
{
  //Programmer's identification
  cout << "Programmer: ChenYu Yang." << endl;
  cout << "Programmer ID: 1670203." << endl;

  ifstream in("Shapes.input.txt");
  ofstream out("Shapes.output.txt");
  stringstream sstr;

  map<string, int> shapes;
  double L;//the length of graph
  double W;//the width of graph
  double H;//the height of graph
  double A;//the area of graph
  double P;//the perimeter of graph
  double V;//the volume of graph
  double pi = 3.14159;
  string line;
  string shape;

  shapes.insert(pair<string, int>("SQUARE", 1));
  shapes.insert(pair<string, int>("RECTANGLE", 2));
  shapes.insert(pair<string, int>("CIRCLE", 3));
  shapes.insert(pair<string, int>("TRIANGLE", 4));
  shapes.insert(pair<string, int>("CUBE", 5));
  shapes.insert(pair<string, int>("BOX", 6));
  shapes.insert(pair<string, int>("CYLINDER", 7));
  shapes.insert(pair<string, int>("PRISM", 8));

  if(!in || !out) 
    {
      cout << "Unable to open the files! " << endl;;
      exit(1);
    }

  while(getline(in, line)) 
  {
     L = W = H = 0;
     sstr << line;

     if(sstr>>shape) 
    {
       switch(shapes[shape]) 
      {
       case 1: //area and perimeter of a 2D Square
       sstr >> L;  
       P = 4.0 * L;
       A = L * L;
       cout << shape << " side=" << L << " area=" << fixed << setprecision(2) << A << " perimeter=" << fixed << setprecision(2) << P << endl;
       out << shape << " side=" << L << " area=" << fixed << setprecision(2) << A << " perimeter= " << fixed << setprecision(2) << P << endl;
       break;

       case 2: //area and perimeter of a 2D Rectangle
       sstr >> L >> W;
       P = 2.0 * (L + W);
       A = L * L;
       cout << shape << " length="<< L << " width=" << W << " area=" << fixed << setprecision(2) << A << " perimeter=" << fixed << setprecision(2) << P << endl;
       out << shape << " length=" << L << " width=" << W << " area=" << fixed << setprecision(2) << A << " perimeter=" << fixed << setprecision(2) << P << endl;
       break;

       case 3: //area and perimeter of a 2D Circle
       sstr >> L;
       P = 2 * pi * L;
       A = pi * (L * L);
       cout << shape << " radius=" << L << " area=" << fixed << setprecision(2) << A << " perimeter=" << fixed << setprecision(2) << P << endl;
       out << shape << " radius="<< L << " area=" << fixed << setprecision(2) << A << " perimeter=" << fixed << setprecision(2) << P << endl;
       break;

       case 4: //area and perimeter of an 2D equilateral Triangle
       sstr >> L; 
       P = 3.0 * L;
       A = (1.732 * L * L) / 4.0;
       cout << shape << " side=" << L << " area=" << fixed << setprecision(2) << A << " perimeter=" << fixed << setprecision(2) << P << endl;
       out << shape << " side=" << L << " area=" << fixed << setprecision(2) << A << " perimeter=" << fixed << setprecision(2) << P << endl;
       break;

       case 5: //surface area and volume of a 3D Cube (a 2D square with a 3rd dimension)
       sstr >> L;
       V = L * L * L;
       A = 6 * L * L;
       cout << shape << " side=" << L << " surface area=" << A << " volume=" << V << endl;
       out << shape << " side=" << L << " surface area=" << A << " volume=" << V << endl;
       break;

       case 6: //surface area and volume of a Box (a 2D rectangle with a 3rd dimension)
       sstr >> L >> W >> H;
       V = L * W * H;
       A = 2.0 * (L * W + L * H + W * H);
       cout << shape << " length=" << L << " widht=" << W << " height=" << H << " surface area=" << fixed << setprecision(2) << A << " volume=" << fixed << setprecision(2) << V << endl;
       out << shape << " length=" << L << " widht=" << W << " height=" << H << " surface area=" << fixed << setprecision(2) << A << " volume=" << fixed << setprecision(2) << V << endl;
       break;

       case 7: //surface area and volume of a Cylinder (a 2D circle with a 3rd dimension)
       sstr >> L >> H; 
       V = pi * L * L * H;
       A = 2.0 * pi * L * (L + H);
       cout << shape << " radius=" << L << " height=" << H << " surface area=" << fixed << setprecision(2) << A << " volume=" << fixed << setprecision(2) << V << endl;
       out << shape << " radius=" << L << " height=" << H << " surface area=" << fixed << setprecision(2) << A << " volume=" << fixed << setprecision(2) << V << endl;
       break;

       case 8: //surface area and volume of a Prism (a 2D equilateral triangle with a 3rd dimension)
       sstr >> L >> H;
       V = (1.732 * L * L * H) / 4.0;
       A = 3.0 * (L * H) + (1.732 * L * L) / 2.0;
       cout << shape << " side=" << L << " height=" << H << " surface area=" << fixed << setprecision(2) << A << " volume=" << fixed << setprecision(2) << V << endl;
       out << shape << " side=" << L <<" height=" << H << " surface area=" << fixed << setprecision(2) << A << " volume=" << fixed << setprecision(2) << V << endl;
       break;
     
       default:
       cout << shape << " Invalid Object!" << endl;
      }
    }
    sstr.str(string());
    sstr.clear();
  }
  in.close();
  out.close();
  return 0;
}