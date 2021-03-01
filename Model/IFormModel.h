#pragma once

#include <string>

#include "./Form/IForm.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace : IFormModel

    Methods   : newForm(string name)
                loadForm(string fileName)
                saveForm(string fileName)
                changeFormName(string newName)
                generateForm()
                addComponent(string componentName)
                removeComponent(string componentName)
                changeComponentName(string componentName, string newName)
                adjustComponentOrder(string componentName, string replaceWith)
                addField(string componentName, string fieldName, string type)
                removeField(string componentName, string fieldName)
                adjustFieldOrder(string componentName, string fieldName, string replaceWith)
                setFieldData(string componentName, string fieldName, const vector<string> &params)
                isFormExists()
                removeForm()

    Description: This is the interface for every model that is part of the form creator system,
                 through a simple contruct with this interface any model can be impleneted in this interface.
                 It will be used for the MVC as the facade of the model.

----------------------------------------------------------------*/

class IFormModel
{
public:
    virtual string newForm(string name) = 0;
    virtual string loadForm(string fileName) = 0;
    virtual string saveForm(string fileName) = 0;
    virtual string changeFormName(string newName) = 0;
    virtual string generateForm() = 0;

public:
    virtual string addComponent(string componentName) = 0;
    virtual string removeComponent(string componentName) = 0;
    virtual string changeComponentName(string componentName, string newName) = 0;
    virtual string adjustComponentOrder(string componentName, string replaceWith) = 0;

public:
    virtual string addField(string componentName, string fieldName, string type) = 0;
    virtual string removeField(string componentName, string fieldName) = 0;
    virtual string adjustFieldOrder(string componentName, string fieldName, string replaceWith) = 0;
    virtual string setFieldData(string componentName, string fieldName, const vector<string> &params) = 0;

public:
    virtual int isFormExists() = 0;
    virtual void removeForm() = 0;
};
