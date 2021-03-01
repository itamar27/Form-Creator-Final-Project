#pragma once

#include "./Field.h"

using namespace std;

/*----------------------------------------------------------------

    Class     : InputField

    Members   : string _defaultText

    Methods   : saveField(std::ofstream &oFile)
                loadField(std::ifstream &iFile)
                generateField()
                changeParameters(const vector<string> &params)
    
    Description: Implementing Field of type "Input (Text)", given a option to set a default text to it. 

----------------------------------------------------------------*/

class InputField : public Field
{

private:
    string _defaultText;

public:
    InputField(std::ifstream &iFile)
    {
        loadField(iFile);
    }
    InputField(const string &headLine) : Field(headLine), _defaultText("") {}
    InputField(const string &headLine, const string &defaultText) : Field(headLine), _defaultText(defaultText) {}
    ~InputField() {}

    void saveField(std::ofstream &oFile);
    void loadField(std::ifstream &iFile);
    std::string generateField();

    virtual void changeParameters(const vector<string> &params);
};