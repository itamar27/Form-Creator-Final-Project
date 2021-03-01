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

class SingleChoiceField : public SelectField
{
public:
    SingleChoiceField(std::ifstream &iFile)
    {
        loadField(iFile);
    }

    SingleChoiceField(string headLine) : SelectField(headLine) {}
    ~SingleChoiceField() {}

    virtual void saveField(std::ofstream &oFile);
    virtual void loadField(std::ifstream &iFile);
    virtual std::string generateField();
};