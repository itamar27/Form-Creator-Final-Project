#pragma once

#include "./IField.h"

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

class Field : public IField
{

public:
    Field(const string &headLine)
    {
        if (headLine == "")
            throw "Not a proper headline"; // this should be impleneted next with an excepition class
        else
            _headLine = headLine;
    }
    ~Field() {}

public:
    virtual string getHeadLine() const { return _headLine; }
    virtual void setHeadLine(const string &headLine)
    {
        if (headLine != "")
            _headLine = headLine;
    }
};