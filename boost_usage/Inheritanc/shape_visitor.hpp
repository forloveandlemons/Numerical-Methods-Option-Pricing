#ifndef SHAPE_VISITOR_HPP
#define SHAPE_VISITOR_HPP

#include <iostream>
#include <string>
#include <boost/variant.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"

class shape_visitor : public boost::static_visitor<void>
{
    //shift the x,y coordinate to right by m_dx and m_dy respectively
private:
    double m_dx;
    double m_dy;
public:
    shape_visitor(double dx,double dy):m_dx(dx),m_dy(dy){};//constructor
    
    void operator()(Point& p) const
    {//overload operator() for point
        p.X(p.X()+m_dx);//assign the moved x point to x
        p.Y(p.Y()+m_dy);//assign the moved y point to y
    }
    void operator()(Line& l) const
    {//overload operator()for line
        Point start((l.start()).X()+m_dx,(l.start()).Y()+m_dy);
        Point end((l.end()).X()+m_dx,(l.end()).Y()+m_dy);
        l.start(start);//assign the moved start point to new start
        l.end(end);//assign the moved end point to new end
    }
    void operator()(Circle& c) const
    {//overload operator() for circle
        Point center((c.CenterPoint()).X()+m_dx,c.CenterPoint().Y()+m_dy);
        c.CenterPoint(center);//assign the point after move to center
    }
};

#endif