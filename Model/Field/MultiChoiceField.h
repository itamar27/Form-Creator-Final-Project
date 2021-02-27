#pragma once
#include "./SelectField.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace : MultiChoiceField
    Memebers  : None
    Methods   : changeParameters()
    
    Description: Implementing SelectField for a multio choice option.

----------------------------------------------------------------*/

class MultiChoiceField : public SelectField
{
public:
    MultiChoiceField(std::ifstream &iFile) {
        loadField(iFile);
    }
    MultiChoiceField(string headLine) : SelectField(headLine) {}
    ~MultiChoiceField() {}

    virtual void saveField(std::ofstream &oFile);
    virtual void loadField(std::ifstream &iFile);
    virtual std::string generateField();
};