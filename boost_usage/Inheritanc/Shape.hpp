
// Shape.hpp
//
// Header file for base class

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <string>
#include "stdlib.h"
using namespace std;

class Shape
{
private:
    int id;
    
public:
    // Constructor&Destructor
    Shape();								// Default constructor
    Shape(const Shape &s);                  // Copy constructor
    virtual ~Shape();                               // Destructor
    
    // Accessing functions
    int ID() const ;					// Retrieve id number
    
    // ToString function, return a string description of the point
    virtual string ToString() const;
    
    // Operator overloading
    Shape & operator = (const Shape & source);//Assignment operator
    
    //Draw function
    virtual void Draw()const=0;
};

#endif