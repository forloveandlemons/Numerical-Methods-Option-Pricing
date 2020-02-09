#ifndef OUTOFBOUNDSEXCEPTION_HPP
#define OUTOFBOUNDSEXCEPTION_HPP
#include "ArrayException.hpp"

using namespace std;
#include <string>

class OutOfBoundsException: public ArrayException
{
private:
    int m_index;
public:
    OutOfBoundsException(int);
    virtual string GetMessage();
    
};

inline OutOfBoundsException::OutOfBoundsException(int errindex)
{
    m_index=errindex;
};

inline string OutOfBoundsException::GetMessage()
{
    string str="The index is out of Bounds.";
    return str;
};


#endif