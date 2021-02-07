#pragma once

#include "./IForm.h"

class HtmlForm : public IForm
{
public:
    HtmlForm(std::string name)
    {
        _name = name;
    }

    void generate();

    virtual void addComponent(Component* component);
    virtual void removeComponent(int index);
    virtual void adjustComponentOrder(string name, int newPosition);

    ~HtmlForm()
    {
        for (auto it = _components.begin(); it != _components.end(); it++)
        {
            delete *it;
        }
    }
};