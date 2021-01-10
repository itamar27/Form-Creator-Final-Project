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
    SingleCoichField(string headLine) : SelectField(headLine) {}
    ~SingleCoichField() {}

    virtual void changeParameters(const vector<string> &params)
    {
        if (params.size() != 2)
        {
            throw "Bad numbers of parameters to method: changeParameters() inside SingleChoiceField ";
        }
        else
        {
            string action = params.at(0);
            if (action == "add")
            {
                addValue(params.at(1));
            }
            else if (action == "remove")
            {
                removeValue(stoi(params.at(1)));
            }
        }
    }
};