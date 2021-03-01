#pragma once
#include "./SelectField.h"

using namespace std;

/*----------------------------------------------------------------

    Class     : ListSelectField
    
    Methods   : saveField(std::ofstream &oFile)
                loadField(std::ifstream &iFile)
                generateField()
    
    Description: Implementing SelectField for a drop list of choices option.

----------------------------------------------------------------*/

class ListSelectField : public SelectField
{
public:
    ListSelectField(std::ifstream &iFile)
    {
        loadField(iFile);
    }
    ListSelectField(string headLine) : SelectField(headLine) {}
    ~ListSelectField() {}

    virtual void saveField(std::ofstream &oFile);
    virtual void loadField(std::ifstream &iFile);
    virtual std::string generateField();
};