#include <iostream>
#include <string>
#include <boost/variant.hpp>
#include "shape_visitor.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"

using namespace std;

typedef boost::variant<Point, Line, Circle> ShapeType;

//function to create shape on user demand
ShapeType CreateShape()
{
    string usrType;//user defined types, stored in string
    ShapeType usrShape;
    
    //suggest the user to input the type to create
    cout<<"Please input the shape type to create: Point, Line or Circle"<<endl;
    cin>>usrType;//read from console
    
    if(usrType=="Point") usrShape=Point();
    //assume the point before moving is (0,0)
    
    else if(usrType=="Line") usrShape=Line(Point(0,0),Point(0,1));
    //assume the line before moving has startpoint(0,0)and endpoint(0,1)
    
    else if(usrType=="Circle") usrShape=Circle(Point(0,0),1);
    //assume the circle before moving has center(0,0) and radius=1
    else {
        cout<<"Wrong Type"<<endl;
        CreateShape();//suggest the user to input again
    }
    
    return usrShape;
}


int main()
{
    cout<<CreateShape()<<endl;//function creating shape on user demand
    
    try
    {
        ShapeType myLine=Line(Point(1,2),Point(3,4));
        //create variant with shapetype line
        boost::get<Line>(myLine);
        //assign the variant:Line with get<Line> function, should work
        //ShapeType myPoint=Point(Point(1,20));
        //create variant with shapetype point
        //boost::get<Line>(myPoint);
        //assign the variant:Point with get<Line> function, should throw a bad_get exception here
    }
    catch (boost::bad_get& err)
    {
        cout << "Error: " << err.what() << endl;
        
    }
    
    //use shape visitor to change the coordinates of shape
    cout<<endl<<"******Move the shape x,y coordinates by 1,2 units respectively******"<<endl<<endl;
    
    shape_visitor move(1,2);//create an instance of the visitor, move the shape by (1,2)
    
    ShapeType myShape;//create a point shape
    myShape=CreateShape();//suggest the user to select the type of the shape to be moved
    cout<<"Shape before move: "<<myShape<<endl;
    boost::apply_visitor(move, myShape);//move the Point
    cout<<"Shape after move: "<<myShape<<endl;
    
    
    return 0;
}