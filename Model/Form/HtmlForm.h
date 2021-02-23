#pragma once
#include <fstream>

#include "./IForm.h"

class HtmlForm : public IForm
{
public:
    HtmlForm(std::string name)
    {
        _name = name;
    }

    void generate();

    virtual void addComponent(Component *component);
    virtual void addField(string componentName, Field* field);
    virtual void removeComponent(string name);
    virtual void adjustComponentOrder(string name, int newPosition);
    virtual void generateForm();
    virtual int containtsComponent(string name);
    virtual int containtsField(string componentName ,string fieldName);


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