#pragma once

#include <string>

#include "./Form/IForm.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace : IFormModel
    Methods   : newForm(string name);
                loadForm(string name);
                saveForm(string name);
                changeFormName(string formName, string newName);
                addComponent(string name, string type);
                removeComponent(string name);
                changeComponentName(string componentName, string newName);
                adjustComponentOrder(string name, int newPoistion);
                addField(string name, string type);
                removeField(string name);
                adjustFieldOrder(string name, int newPoistion);

    Description: This is the interface for every model that is part of the form creator system,
                 through a simple contruct with this interface any model can be impleneted in this face;

----------------------------------------------------------------*/

class IFormModel
{

public:
    virtual void newForm(string name) = 0;
    virtual void loadForm(string name) = 0;
    virtual void saveForm(string name) = 0;
    virtual void changeFormName(string formName, string newName) = 0;

public:
    virtual void addComponent(string name, string type) = 0;
    virtual void removeComponent(string name) = 0;
    virtual void changeComponentName(string componentName, string newName) = 0;
    virtual void adjustComponentOrder(string name, int newPoistion) = 0;

public:
    virtual void addField(string name, string type) = 0;
    virtual void removeField(string name) = 0;
    virtual void adjustFieldOrder(string name, int newPoistion) = 0;
    virtual void setFieldData(string name, int index) = 0;

};
