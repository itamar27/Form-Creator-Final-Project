#pragma once

#include <string>
#include <vector>

#include "../Component/Component.h"
#include "../Field/Field.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace :  IForm

    Members   :  string _name
                 vector<IComponent *> _components

    Methods   : generateForm()
                saveForm(std::ofstream &oFile)
                loadForm(std::ifstream &iFile)
                changeName(string name)
                getName()
                addComponent(Component *component)
                removeComponent(string name)
                changeComponentName(string componentName, string newName)
                adjustComponentOrder(string name, string replaceWith)
                containtsComponent(string name)
                addField(string componentName, Field *field)
                removeField(string componentName, string fieldName)
                adjustFieldOrder(string componentName, string fieldName, string replaceWith)
                changeFieldData(string componentName, string fieldName, const vector<string> &params)
                containtsField(string componentName, string fieldName)

    Description: A class to set an interface for the form structure,
                 controlling the components that compound the the form sections. 

----------------------------------------------------------------*/

class IForm
{

protected:
    string _name;
    vector<IComponent *> _components;

public:
    virtual void generateForm() = 0;
    virtual void saveForm(std::ofstream &oFile) = 0;
    virtual void loadForm(std::ifstream &iFile) = 0;
    void changeName(string name) { _name = name; }
    virtual void printForm() = 0;
    string getName()
    {
        return _name;
    }

public:
    virtual void addComponent(Component *component) = 0;
    virtual void removeComponent(string name) = 0;
    virtual void changeComponentName(string componentName, string newName) = 0;
    virtual void adjustComponentOrder(string name, string replaceWith) = 0;
    virtual int containtsComponent(string name) = 0;

public:
    virtual void addField(string componentName, Field *field) = 0;
    virtual void removeField(string componentName, string fieldName) = 0;
    virtual void adjustFieldOrder(string componentName, string fieldName, string replaceWith) = 0;
    virtual void changeFieldData(string componentName, string fieldName, const vector<string> &params) = 0;
    virtual int containtsField(string componentName, string fieldName) = 0;
};