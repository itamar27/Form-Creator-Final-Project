#pragma once

#include "./Field.h"

using namespace std;

/*----------------------------------------------------------------

    Class     : FreeTextField

    Members   : string _defaultText

    Methods   : saveField(std::ofstream &oFile)
                loadField(std::ifstream &iFile)
                generateField()
                changeParameters(const vector<string> &params)
    
    Description: Implementing Field of type "Free Text", given a option to set a default text to it.
----------------------------------------------------------------*/

class FreeTextField : public Field
{

private:
    string _defaultText;

public:
    FreeTextField(std::ifstream &iFile)
    {
        loadField(iFile);
    }
    FreeTextField(const string &headLine) : Field(headLine), _defaultText("") {}
    FreeTextField(const string &headLine, const string &defaultText) : Field(headLine), _defaultText(defaultText) {}
    ~FreeTextField() {}

    void saveField(std::ofstream &oFile);
    void loadField(std::ifstream &iFile);
    std::string generateField();
    virtual void changeParameters(const vector<string> &params);
};