#pragma once

#include <string>

#include "./IFormModel.h"
#include "./Form/HtmlForm.h"
#include "./Component/Component.h"
#include "./Field/FreeTextField.h"
#include "./Field/InputField.h"
#include "./Field/ListSelectField.h"
#include "./Field/MultiChoiceField.h"
#include "./Field/SingleChoiceField.h"

using namespace std;

/*----------------------------------------------------------------

    Class     : HtmlFormModel

    Members   : _form

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

    Description: This class implements the IFormModel interface for html forms.

----------------------------------------------------------------*/

class HtmlFormModel : public IFormModel
{
public:
    HtmlFormModel()
    {
        _form = nullptr;
    };
    ~HtmlFormModel()
    {
        saveForm(_form->getName());
        delete _form;
    }

public:
    virtual string newForm(string name);
    virtual string loadForm(string fileName);
    virtual string saveForm(string fileName);
    virtual string changeFormName(string newName);
    virtual string generateForm();

public:
    virtual string addComponent(string componentName);
    virtual string removeComponent(string componentName);
    virtual string changeComponentName(string componentName, string newName);
    virtual string adjustComponentOrder(string componentName, string replaceWith);

public:
    virtual string addField(string componentName, string fieldName, string type);
    virtual string removeField(string componentName, string fieldName);
    virtual string adjustFieldOrder(string componentName, string fieldName, string replaceWith);
    virtual string setFieldData(string componentName, string fieldName, const vector<string> &params);

public:
    int isFormExists()
    {
        if (_form)
            return true;
        else
            return false;
    }

    void removeForm()
    {
        delete _form;
        _form = nullptr;
    }

private:
    HtmlForm *_form;
};
