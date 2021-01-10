#pragma once

#include <string>
#include <vector>
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
class IField
{
protected:
    string _headLine;

public:
    virtual string getHeadLine() = 0;
    virtual void setHeadLine(const string &headLine) = 0;
    virtual void changeParameters(const vector<string>& params) = 0;
};
