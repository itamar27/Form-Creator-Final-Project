#pragma once

#include "./Field.h"

using namespace std;

/*----------------------------------------------------------------

    Class     : FreeTextField
    Memebers  : defaultText
    Methods   : changeParameters()
    
    Description: Implementing Field of type "Free Text", given a option to set
                 a default text to it. 

----------------------------------------------------------------*/

class InputField : public Field
{

private:
    string _defaultText;

public:
    InputField(const string &headLine) : Field(headLine), _defaultText("") {}
    InputField(const string &headLine, const string &defaultText) : Field(headLine), _defaultText(defaultText) {}
    ~InputField() {}

    void saveField(std::string name, std::ofstream *oFile);
    void loadField(std::ifstream *iFile, std::string name);
    std::string generateField();
    
    virtual void changeParameters(const vector<string>& params);
};