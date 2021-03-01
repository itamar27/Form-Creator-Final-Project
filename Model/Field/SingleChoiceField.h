#pragma once
#include "./SelectField.h"

using namespace std;

/*----------------------------------------------------------------

    Class : SingleChoiceField

    Methods   : saveField(std::ofstream &oFile)
                loadField(std::ifstream &iFile)
                generateField()
    
    Description: Implementing SelectField for a single choice option (radio buttons).

----------------------------------------------------------------*/

class SingleCoichField : public SelectField
{
public:
    SingleCoichField(std::ifstream &iFile)
    {
        loadField(iFile);
    }

    SingleCoichField(string headLine) : SelectField(headLine) {}
    ~SingleCoichField() {}

    virtual void saveField(std::ofstream &oFile);
    virtual void loadField(std::ifstream &iFile);
    virtual std::string generateField();
};