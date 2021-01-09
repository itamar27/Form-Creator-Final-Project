#include "./Field.h"

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

class FreeTextField : public Field
{

private:
    string _defaultText;

public:
    FreeTextField(const string &headLine) : Field(headLine) {}
    FreeTextField(const string &headLine, const string &defaultText) : Field(headLine), _defaultText(defaultText) {}
    ~FreeTextField() {}

public:
    virtual void changeParameters(vector<string> params)
    {
        if(params.size() != 1)
            throw "Not a valid input";
        else{
            _defaultText = params[0];
        }
    }
};