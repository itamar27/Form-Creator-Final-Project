#pragma once
#include <fstream>
#include "./IForm.h"

/*----------------------------------------------------------------

    InterFace :  HtmlForm

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

    Description: A class to that implements the IForm interface into an HtmlForm. 

----------------------------------------------------------------*/

class HtmlForm : public IForm
{
public:
    HtmlForm(std::ifstream &iFile);
    HtmlForm(std::string name);
    ~HtmlForm();

public:
    virtual void generateForm();
    virtual void saveForm(std::ofstream &oFile);
    virtual void loadForm(std::ifstream &iFile);
    virtual void printForm();

public:
    virtual void addComponent(Component *component);
    virtual void removeComponent(string name);
    virtual void changeComponentName(string componentName, string newName);
    virtual void adjustComponentOrder(string name, string replaceWith);
    virtual int containtsComponent(string name);

public:
    virtual void addField(string componentName, Field *field);
    virtual void removeField(string componentName, string fieldName);
    virtual void adjustFieldOrder(string componentName, string fieldName, string replaceWith);
    virtual int containtsField(string componentName, string fieldName);
    virtual void changeFieldData(string componentName, string fieldName, const vector<string> &params);
};