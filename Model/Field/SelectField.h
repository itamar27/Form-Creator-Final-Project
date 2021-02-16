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

public:
    SelectField(string headLine) : Field(headLine) {}
    ~SelectField() {}

    virtual void addValue(string value)
    {
        if (value != "")
        {
            _values.push_back(value);
        }
    }

    virtual void removeValue(int index)
    {
        if (index >= 0 && index < _values.size())
        {
            _values.erase(_values.begin() + index);
        }
    }
};