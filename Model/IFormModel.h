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
    virtual string newForm(string name) = 0;
    virtual string loadForm(string name) = 0;
    virtual string saveForm(string name) = 0;
    virtual string changeFormName(string formName, string newName) = 0;
    virtual string generateForm(string name) = 0;

public:
    virtual string addComponent(string formName, string componentName) = 0;
    virtual string removeComponent(string formName, string componentName) = 0;
    virtual string changeComponentName(string componentName, string newName) = 0;
    virtual string adjustComponentOrder(string name, int newPoistion) = 0;

public:
    virtual string addField(string formName, string componentName, string fieldName, string type) = 0;
    virtual string removeField(string name) = 0;
    virtual string adjustFieldOrder(string name, int newPoistion) = 0;
    virtual string setFieldData(string name, int index) = 0;

};
