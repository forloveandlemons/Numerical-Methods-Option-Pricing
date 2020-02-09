// MP Implementation of the Line segment .cpp

#include "Line.hpp"
#include <cmath>
#include <sstream>
using namespace std;



Line::Line():Shape(),startPoint(),endPoint()
{
    //cout<<"default constructor called..."<<endl;
};

Line::~Line()
{
    //cout<<"line destructor........."<<endl;
};

Line::Line(const Point& p1, const Point& p2):Shape(),startPoint(p1),endPoint(p2)
{
};

Line::Line(const Line& l):Shape(l)
{
    startPoint=l.startPoint;
    endPoint=l.endPoint;
};

Point Line::start() const
{
    return startPoint;
};

Point Line::end() const
{
    return endPoint;
};

void Line::start(const Point& pt)
{
    startPoint=pt;
};

void Line::end(const Point& pt)
{
    endPoint=pt;
};

string Line::ToString() const
{//tostring giving discription of line
    stringstream sstr;
    string str;
    sstr << "Line connecting "<<startPoint.ToString() << " and "<< endPoint.ToString()<<endl;
    // read start and end points to stream
    str=sstr.str();       // extract start and end points from stream & insert into str
    return str;
};

double Line::Length() const
{//length function for line
    double length=startPoint.Distance(endPoint);
    return length;
};

/*
 // Operator overloading
 bool operator == (const Line & l) const; //Equally compare operator
 Line & operator = (const Line & source);//Assignment operator
 friend ostream& operator << (ostream& os, const Line &l); //Send to ostream
 */

bool Line::operator == (const Line &l) const
{//Equally compare operator
    return (startPoint==l.startPoint&&endPoint==l.endPoint);
};

Line& Line::operator=(const Line & source)
{//Assignment operator
    Shape::operator=(source);//copy data in the base class
    if(*this==source) return *this;
    startPoint=source.startPoint;
    endPoint=source.endPoint;
    return *this;
};

ostream& operator << (ostream& os,const Line& l)
{//Send to ostream
    os << "Line: startpoint "<<(l.startPoint).ToString()<<", endpoint "<<(l.endPoint).ToString()<<endl;
    return os;
};

void Line::Draw() const
{//draw line
    cout<<"draw in line class"<<endl;
};