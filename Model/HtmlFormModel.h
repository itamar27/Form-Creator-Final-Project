#pragma once

#include <string>
#include <map>

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

    Class : HtmlFormModel
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

    Description: This class implements the IFormModel interface for html forms.

----------------------------------------------------------------*/

class HtmlFormModel : public IFormModel
{
public:
    HtmlFormModel() {
        _form = nullptr;
    };
    ~HtmlFormModel() {};

public:
    virtual string newForm(string name);
    virtual string loadForm(string fileName);
    virtual string saveForm(string fileName);
    virtual string changeFormName(string newName);
    virtual string generateForm();

public:
<<<<<<< Updated upstream
    virtual string addComponent(string formName, string componentName);
    virtual string removeComponent(string formName, string componentName);
    virtual string changeComponentName(string componentName, string newName);
    virtual string adjustComponentOrder(string name, int newPoistion);

public:
    virtual string addField(string formName, string componentName, string fieldName, string type);
    virtual string removeField(string name);
    virtual string adjustFieldOrder(string name, int newPoistion);
    virtual string setFieldData(string name, int index);
=======
    virtual string addComponent(string componentName);
    virtual string removeComponent(string componentName);
    virtual string changeComponentName(string componentName, string newName);
    virtual string adjustComponentOrder(string componentName, string replaceWith);

public:
    virtual string addField(string componentName, string fieldName, string type);
    virtual string removeField(string componentName, string fieldName);
    virtual string adjustFieldOrder(string componentName, string fieldName, string replaceWith);
    virtual string setFieldData(string componentName, string fieldName, const vector<string>& params);
>>>>>>> Stashed changes

private:
    HtmlForm* _form;
};
