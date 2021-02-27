#pragma once

#include <vector>

#include "./IComponent.h"
#include "../Field/IField.h"
#include "../Field/FreeTextField.h"
#include "../Field/InputField.h"
#include "../Field/ListSelectField.h"
#include "../Field/MultiChoiceField.h"
#include "../Field/SingleChoiceField.h"

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
    Component(std::ifstream &iFile) {
        loadComponent(iFile);
    }
    
    Component(string name)
    {
        if (name == "")
            throw "Not a proper name for a component";
        _name = name;
    }

public:
    virtual void addField(IField *field);
<<<<<<< Updated upstream
    virtual void removeField(int index);
    virtual void adjustFieldsOrder(string name, int newPosition);
    virtual void changeFieldParameter(int index) ;
    virtual void saveComponent() ;
    virtual void uploadComponent();
=======
    virtual void removeField(string name);
    virtual void adjustFieldsOrder(string fieldName, string replaceWith);
    virtual void changeFieldParameter(string name, const vector<string>& params);
    virtual void saveComponent(std::ofstream &oFile);
    virtual void loadComponent(std::ifstream &iFile);
>>>>>>> Stashed changes
    virtual std::string generateComponent();
    virtual int containtsField(string fieldName);

};