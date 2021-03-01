#pragma once

#include <fstream>

#include "./IField.h"

/*----------------------------------------------------------------

    Interface : Field
    Methods   : getHeadLine()
                setHeadLine(const string &headLine)
                loadHeadLine(std::ifstream &iFile)
                saveHeadLine(std::ofstream &oFile)


    Description: A class to set an interface for every field that can be in form 
                 in order to implement this class the. This class implements some
                 of the behavior for IField but needs to be extended with more behaivor.

----------------------------------------------------------------*/

class Field : public IField
{

public:
    Field() {}
    Field(const string &headLine)
    {
        setHeadLine(headLine);
    }
    ~Field() {}

public:
    virtual string getHeadLine() const { return _headLine; }

    virtual void setHeadLine(const string &headLine)
    {
        _headLine = headLine;
    }

protected:
    virtual void loadHeadLine(std::ifstream &iFile)
    {
        int n = 0;
        iFile.read((char *)&n, sizeof(n));

        char *temp = new char[n + 1];
        iFile.read(temp, n);
        temp[n] = '\0';

        _headLine = temp;
    }

    virtual void saveHeadLine(std::ofstream &oFile)
    {
        int n = _headLine.length();
        oFile.write((char *)&n, sizeof(n));
        oFile.write(_headLine.c_str(), n);
    }
};