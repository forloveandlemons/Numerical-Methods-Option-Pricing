

#define _USE_MATH_DEFINES

#include "Circle.hpp"
#include <cmath>
#include <sstream>
using namespace std;

//constructors and destructor

Circle::Circle():Shape(), center(),radius(0)
{// default constructor, center(0,0) and radious 0
    
};
Circle::Circle(const Point& pt, const double& r):Shape()
{// constructor with initiating values
    center=pt;
    radius=r;
};
Circle::Circle(const Circle& c):Shape(c)
{// Copy constructor
    center=c.center;
    radius=c.radius;
};
Circle::~Circle()
{// Destructor
    //cout<<"destructor"<<endl;
};

// Accesssing functions

Point Circle::CenterPoint() const
{// Access center point
    return center;
};

double Circle::Radius() const
{// Access radius length
    return radius;
};

// Modifiers

void Circle::CenterPoint(const Point& pt)
{// Set center point
    center=pt;
};

void Circle::Radius(const double& r)
{// Set radius length
    radius=r;
};

// Diameter function, return the length of diameter
double Circle::Diameter() const
{
    double dia=2*radius;
    return dia;
};

// Area function, return the area of the circle
double Circle::Area() const
{
    double area=M_PI*radius*radius;
    return area;
};

// Circumference function, return the length of circumference
double Circle::Circum() const
{
    double circum=2*M_PI*radius;
    return circum;
};

// ToString function, return a string description of the line
string Circle::ToString() const
{
    stringstream sstr;
    string s;
    sstr << "Circle with center: "<<center.ToString()<<" and radius: "<<radius;
    // read center point and radius length to stream
    s=sstr.str();       // extract start and end points from stream & insert into str
    return s;
    
};

// Operator overloading
bool Circle::operator == (const Circle & c) const
{//Equally compare operator
    return(center==c.center&&radius==c.radius);
};

Circle & Circle::operator = (const Circle & source)
{//Assignment operator
    Shape::operator=(source);//copy data in the base class
    if(*this==source) return *this;//excluding the case when source equal current object
    
    center=source.center;
    radius=source.radius;
    return *this;
};

ostream& operator << (ostream& os, const Circle &c)
{//Send to ostream
    os << "Circle: center point "<<(c.center).ToString()<<", radius "<<c.radius<<endl;
    return os;
};

void Circle::Draw() const
{
    cout<<"draw in circle class"<<endl;
};

