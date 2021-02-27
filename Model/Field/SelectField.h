#pragma once
#include "./Field.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace : SelectField
    Memebers  : values[]
    Methods   : changeParameters()
                addValue()
                removeValue()
    
    Description: Implementing Field for a all type of Select Fields.
                 By inheriting this class you must implement changeParameters
                 and include calls for addValue() and removeValue() in it.

----------------------------------------------------------------*/

class SelectField : public Field
{
protected:
    vector<string> _values;
    SelectField() {}
    
public:
    SelectField(string headLine) : Field(headLine) {}
    ~SelectField() {}

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
                removeValue(params.at(1));
            }
        }
    }

    virtual void addValue(string value)
    {
        if (value != "")
        {
            _values.push_back(value);
        }
    }

    virtual void removeValue(string val)
    {
        for(auto it = _values.begin(); it != _values.end(); it++){
            if((*it) == val) {
                _values.erase(it);
            }
        }
    }
};