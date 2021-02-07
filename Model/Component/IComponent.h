#pragma once

#include <string>
#include "../Field/IField.h"
#include <vector>

using namespace std;

/*----------------------------------------------------------------

    InterFace :  IComponent
    Memebers  : _name, _fields
    Methods   : addField()
                removeField(field)
                adjustOrder(string name, int newPosition)
    
    Description: A class to set an interface for every component 
                 that is part of the form's general structure. 

----------------------------------------------------------------*/

class IComponent
{

protected:
    string _name;
    vector<IField*> _fields;

public:
    virtual void addField(IField *field) = 0;
    virtual void removeField(int index) = 0;
    virtual void adjustFieldsOrder(string name, int newPosition) = 0;
    virtual void changeFieldParameter(int index) = 0;

public:
    virtual void saveComponent() = 0;
    virtual void uploadComponent() = 0;
};