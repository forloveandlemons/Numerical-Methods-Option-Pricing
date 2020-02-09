
// Point.hpp
//
// Header file for Points in two dimensions.

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include "Shape.hpp"
using namespace std;


class Point:public Shape
{
private:
    double x;	// X coordinate
    double y;	// Y coordinate
    
public:
    // Constructor&Destructor
    Point();								// Default constructor
    Point(double xval,double yval);         // Constructor initializing with values
    explicit Point(double);    //2.4.3 add constructor
    Point(const Point&);                    // Copy constructor
    ~Point();                               // Destructor
    
    // Accessing functions
    double X() const ;					// The x-coordinate
    double Y() const;					// The y-coordinate
    
    // Setting functions
    void X(double newX);                 // set the x-coordinate
    void Y(double newY);                 // set the y-coordinate
    
    // ToString function, return a string description of the point
    string ToString() const;
    
    // Distance functions
    double Distance() const;                // calculate the distance to the origin
    double Distance(const Point &p) const;               // calculate the distance between two points
    
    // Operator overloading
    Point operator - () const;           // Negate the coordinates
    Point operator * (double factor) const;// Scale the coordinates
    Point operator + (const Point & p) const; //Add coordinates
    bool operator == (const Point & p) const; //Equally compare operator
    Point & operator = (const Point & source);//Assignment operator
    Point & operator *= (double factor); //Scale the coordinates and assign
    friend ostream& operator << (ostream & os, const Point & p);
    
    //draw function
    void Draw() const;
};


#endif