#pragma once
#include "./SelectField.h"

using namespace std;

/*----------------------------------------------------------------

    Class     : MultiChoiceField

    Methods   : saveField(std::ofstream &oFile)
                loadField(std::ifstream &iFile)
                generateField()
    
    Description: Implementing SelectField for a multi choice option (check boxes).

----------------------------------------------------------------*/

class MultiChoiceField : public SelectField
{
public:
    MultiChoiceField(std::ifstream &iFile)
    {
        loadField(iFile);
    }
    MultiChoiceField(string headLine) : SelectField(headLine) {}
    ~MultiChoiceField() {}

    virtual void saveField(std::ofstream &oFile);
    virtual void loadField(std::ifstream &iFile);
    virtual std::string generateField();
};