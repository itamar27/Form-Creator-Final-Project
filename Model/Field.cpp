#include <string>
#include <iostream>

using namespace std;


/*----------------------------------------------------------------

    InterFace :  Field
    Memebers  : headLine
    Methods   : Field()
                getHeadLine()
                setHeadLine(string headLine)
                changeParameters()
    
    Description: A class to set an interface for every field that can be in form 
                 in order to implement this class the 

----------------------------------------------------------------*/
class Field
{
private:
    string _headLine;

public:
    Field(string headLine) : _headLine(headLine) {}

public:
    virtual string getHeadLine() const { return _headLine; }
    virtual void setHeadLine(string headLine) { _headLine = headLine;}
    virtual void changeParameters() = 0;
}


class FreeTextField : public Field{
    
} 