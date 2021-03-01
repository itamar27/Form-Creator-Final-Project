#pragma once
#include <fstream>

#include "./IForm.h"

class HtmlForm : public IForm
{
public:

    HtmlForm(std::ifstream &iFile) {
        loadForm(iFile);
    }

    HtmlForm(std::string name)
    {
        _name = name;
    }

    void generate();

    virtual void addComponent(Component *component);
    virtual void addField(string componentName, Field* field);
    virtual void removeField(string componentName, string fieldName);
    virtual void removeComponent(string name);
    virtual void adjustFieldOrder(string componentName, string fieldName, string replaceWith);
    virtual void changeComponentName(string componentName, string newName);
    virtual void adjustComponentOrder(string name, string replaceWith);
    virtual void generateForm();
    virtual int containtsComponent(string name);
    virtual int containtsField(string componentName ,string fieldName);
    virtual void saveForm(std::ofstream &oFile);
    virtual void loadForm(std::ifstream &iFile);
    virtual void changeFieldData(string componentName, string fieldName, const vector<string>& params);


    ~HtmlForm()
    {
        for (auto it = _components.begin(); it != _components.end(); it++)
        {
            delete *it;
        }
    }

    //THIS IS FOR TESTING!!!!
    void printAllComponents()
    {
        std::cout << "Form name: " << _name << std::endl;
        for (int i = 0; i < _components.size(); i++)
        {
            _components[i]->printAllFields();
        }
    }
};