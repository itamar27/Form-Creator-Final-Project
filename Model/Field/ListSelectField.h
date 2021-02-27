#pragma once
#include "./SelectField.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace : ListSelectField
    Memebers  : None
    Methods   : changeParameters()
    
    Description: Implementing SelectField for a list of choices option.

----------------------------------------------------------------*/

class ListSelectField : public SelectField
{
public:
    ListSelectField(std::ifstream &iFile) {
        loadField(iFile);
    }
    ListSelectField(string headLine) : SelectField(headLine) {}
    ~ListSelectField() {}

    virtual void saveField(std::string name, std::ofstream *oFile);
    virtual void loadField(std::ifstream *iFile, std::string name);
    virtual std::string generateField();
};