#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
#include <string>
using namespace std;

class Line:public Shape
{
private:
    
    Point startPoint;	// e1
    Point endPoint;		// e2
    
public:
    
    // Constructors
    Line();									// Line with both end Points at the origin
    Line(const Point& p1, const Point& p2);	// Line with end Points [p1, p2]
    Line(const Line& l); 				    // Copy constructor
    virtual ~Line();						// Destructor
    
    // Accesssing functions
    Point start() const;                    // Access start point
    Point end() const;                      // Access end point
    
    // Modifiers
    void start(const Point& pt);					// Set Point pt1
    void end(const Point& pt);						// Set Point pt2
    
    // ToString function, return a string description of the line
    string ToString() const;
    
    // Length function
    double Length() const;
    
    // Operator overloading
    bool operator == (const Line & l) const; //Equally compare operator
    Line & operator = (const Line & source);//Assignment operator
    friend ostream& operator << (ostream& os, const Line& l); //Send to ostream
    
    //Draw function
    void Draw() const;
};

#endif