// Shape.cpp
// source function for Shape.hpp, define functions for base class

#include "Shape.hpp"
#include <sstream>
#include <cmath>
#include "stdlib.h"
using namespace std;

//Constructor and descructor

Shape::Shape()
{// Default constructor
    id=rand();
    //cout << "default constructor called........." << endl;
};


Shape::Shape(const Shape& s)
{// Copy constructor
    id=s.id;
    //cout << "copy constructor called........." << endl;
};

Shape::~Shape()
{// Destructor
    //cout << "shape destructor called........." << endl;
};

// Accessing functions

int Shape::ID() const
{// Getting the id
    return id;
};

// ToString function, return a string description of the shape id
string Shape::ToString() const
{
    stringstream sstr;
    string str;
    sstr << "ID: "<<id;   // read id to stream
    str=sstr.str();       // extract id from stream & insert into sstr
    return str;
};

//operator overloading
Shape& Shape::operator= (const Shape & source)
{//Assignment operator
    if(this==&source) return *this;
    id=source.id;
    return *this;
};

//draw function
void Shape::Draw() const
{
    //cout<<"draw in shape class"<<endl;
};

