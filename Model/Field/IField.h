#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*----------------------------------------------------------------

    InterFace : IField
    Memebers  : headLine
    Methods   : Field()
                getHeadLine()
                setHeadLine(string headLine)
                changeParameters()
                saveField()
                loadField()

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

public:
    virtual void changeParameters(const vector<string> &params) = 0;

public:
    virtual void saveField(std::string name, std::ofstream *oFile) = 0;
    virtual void loadField(std::ifstream *iFile, std::string name) = 0;
    virtual void generateField() = 0;
};
