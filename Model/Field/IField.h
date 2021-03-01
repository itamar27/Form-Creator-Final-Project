#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*----------------------------------------------------------------

    InterFace : IField
    Memebers  : _headLine
    Methods   : getHeadLine()
                setHeadLine(const string &headLine)
                changeParameters(const vector<string> &params)
                saveField(std::ofstream &oFile)
                loadField(std::ifstream &iFile)
                generateField()
                getName()

    Description: A class to set an interface for every field that can be in form.

----------------------------------------------------------------*/
class IField
{
protected:
    string _headLine;

public:
    virtual string getHeadLine() const = 0;
    virtual void setHeadLine(const string &headLine) = 0;

public:
    virtual void changeParameters(const vector<string> &params) = 0;

public:
    virtual void saveField(std::ofstream &oFile) = 0;
    virtual void loadField(std::ifstream &iFile) = 0;
    virtual std::string generateField() = 0;

    string getName()
    {
        return _headLine;
    }
};
