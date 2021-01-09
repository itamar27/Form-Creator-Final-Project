#pragma once

#include <string>
#include "../Field/IField.h"
#include <vector>

using namespace std;

/*----------------------------------------------------------------

    InterFace :  Component
    Memebers  : _name, _fields
    Methods   : addField()
                removeField(field)
                adjustOrder(string name, int newPosition)
    
    Description: A class to set an interface for every component 
                 that is part of the form's general structure. 

----------------------------------------------------------------*/

class IComponent
{

private:
    string _name;
    vector<IField> _fields;

public:
    virtual void addField(IField field) = 0;
    virtual void removeField(IField field) = 0;
    virtual void adjustFieldsOrder(string name, int newPosition) = 0;
};