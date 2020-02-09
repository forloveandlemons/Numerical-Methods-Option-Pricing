
// Point.cpp
// source function for Point.hpp, define functions declared in Point.hpp

#include "Point.hpp"
#include <sstream>
#include <cmath>

//Constructor and descructor

Point::Point():Shape(),x(0),y(0)
{// Default constructor
    //	x = y =0.0
    //cout << "default constructor called........." << endl;
};

Point::Point(double xval,double yval):Shape(),x(xval),y(yval)
{// Constructor initializing with values
    //cout << "constructor initializing with values called........." << endl;
};

Point::Point(double xyval):Shape(),x(xyval),y(xyval)
{//2.3.4 set constructor
    
}

Point::Point(const Point& p):Shape(p)
{// Copy constructor
    x = p.x;
    y = p.y;
    //cout << "copy constructor called........." << endl;
};
Point::~Point()
{// Destructor
    //cout << "point destructor........." << endl;
};

// Accessing functions

double Point::X() const
{// Getting the x-coordinate
    return x;
};

double Point::Y() const
{// Getting the y-coordinate
    return y;
};

// Setting functions

void Point::X(double newX)
{// set the x-coordinate
    x=newX;
};

void Point::Y(double newY)
{// set the y-coordinate
    y=newY;
};

// ToString function, return a string description of the point

string Point::ToString() const
{
    //string s0=Shape::ToString();
    stringstream sstr;
    string s;
    sstr << "Point("<<x<<','<<y<<")";   // read x&y-coordinate to stream
    s=sstr.str();       // extract x-coordinate from stream & insert into sstr
    return s;
};

// Distance functions

double Point::Distance() const
{// calculate the distance to the origin
    double dist=sqrt(x*x+y*y);
    return dist;
};
double Point::Distance(const Point &p) const
{// calculate the distance between two points
    //cannot change p here
    //p.SetX();
    double dx=x-p.x;
    double dy=y-p.y;
    double dist=sqrt(dx*dx+dy*dy);
    return dist;
};

// Operator overloading

Point Point::operator -() const
{// Negate the coordinates
    return Point(-x,-y);
};

Point Point::operator*(double factor) const
{// Scale the coordinates
    return Point(x*factor,y*factor);
};

Point Point::operator+(const Point& p) const
{// Add coordinates
    return Point(x+p.x,y+p.y);
};

bool Point::operator == (const Point &p) const
{// Equally compare operator
    return (x==p.x&&y==p.y);
};

Point& Point::operator= (const Point & source)
{//Assignment operator
    Shape::operator=(source);//copy data in the base class
    if(*this==source) return *this;
    
    x=source.x;
    y=source.y;
    return *this;
};

Point& Point::operator*=(double factor)
{//Scale the coordinates
    x=factor*x;
    y=factor*y;
    return *this;
};

ostream& operator << (ostream & os, const Point & p)
{//send to ostream for output
    os<<'('<<p.x<<','<<p.y<<')';
    return os;
};

void Point::Draw()const
{
    cout<<"draw in point class"<<endl;
};
