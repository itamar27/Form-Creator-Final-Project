#pragma once

#include <vector>

#include "./IComponent.h"

/*----------------------------------------------------------------

    InterFace :  Component
    Memebers  : _name, _fields
    Methods   : addField()
                removeField(field)
                adjustOrder(string name, int newPosition)
    
    Description: This class is a general abstract class that implements
                 some of the components common behaviors. 

----------------------------------------------------------------*/

class Component : public IComponent
{
public:
    Component(string name)
    {
        if (name == "")
            throw "Not a proper name for a component";
        _name = name;
    }

public:
    virtual void addField(IField *field);
    virtual void removeField(int index);
    virtual void adjustFieldsOrder(string name, int newPosition);
    virtual void changeFieldParameter(int index) ;
    virtual void saveComponent() ;
    virtual void uploadComponent();
    virtual std::string generateComponent();
};