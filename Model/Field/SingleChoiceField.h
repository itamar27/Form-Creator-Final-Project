#pragma once
#include "./SelectField.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace : SingleChoiceField
    Memebers  : None
    Methods   : changeParameters()
    
    Description: Implementing SelectField for a single choice option.

----------------------------------------------------------------*/

class SingleCoichField : public SelectField
{
public:
    SingleCoichField(std::ifstream &iFile) {
        loadField(iFile);
    }

    SingleCoichField(string headLine) : SelectField(headLine) {}
    ~SingleCoichField() {}

    virtual void saveField(std::ofstream &oFile);
    virtual void loadField(std::ifstream &iFile);
    virtual std::string generateField();
};