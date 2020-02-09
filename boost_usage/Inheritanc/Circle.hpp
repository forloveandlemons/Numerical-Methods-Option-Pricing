// circle.hpp

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
#include <string>

using namespace std;

class Circle:public Shape
{
private:
    
    Point center;	    // center point
    double radius;		// radius
    
public:
    
    // Constructors and destructor
    Circle();									// default constructor, center(0,0) and radious 0
    Circle(const Point& pt, const double& r);	// constructor with initiating values
    Circle(const Circle& c);				    // Copy constructor
    virtual ~Circle();						    // Destructor
    
    // Accesssing functions
    Point CenterPoint() const;                    // Access center point
    double Radius() const;                      // Access radius length
    
    // Modifiers
    void CenterPoint(const Point& pt);					// Set center point
    void Radius(const double& r);						// Set radius length
    
    // Diameter function, return the length of diameter
    double Diameter() const;
    
    // Area function, return the area of the circle
    double Area() const;
    
    // Circumference function, return the length of circumference
    double Circum() const;
    
    // ToString function, return a string description of the line
    string ToString() const;
    
    // Operator overloading
    bool operator == (const Circle & c) const; //Equally compare operator
    Circle & operator = (const Circle & source);//Assignment operator
    friend ostream& operator << (ostream& os, const Circle &c); //Send to ostream
    
    //draw function
    void Draw() const;
};

#endif