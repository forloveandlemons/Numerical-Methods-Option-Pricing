#ifndef ARRAYEXCEPTION_HPP
#define ARRAYEXCEPTION_HPP

using namespace std;
#include <string>


class ArrayException
{
public:
    virtual string GetMessage()=0;
    
};


#endif