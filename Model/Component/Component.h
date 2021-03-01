#pragma once

#include <vector>

#include "./IComponent.h"
#include "../Field/IField.h"
#include "../Field/FreeTextField.h"
#include "../Field/InputField.h"
#include "../Field/ListSelectField.h"
#include "../Field/MultiChoiceField.h"
#include "../Field/SingleChoiceField.h"

/*----------------------------------------------------------------

    InterFace : Component
    
    Methods   : addField(IField *field)
                removeField(string name)
                adjustFieldsOrder(string fieldName, string replaceWith)
                changeFieldParameter(string name, const vector<string>& params)
                saveComponent(std::ofstream &oFile)
                loadComponent(std::ifstream &iFile)
                generateComponent()
                containtsField(string fieldName)
    
    Description: This class implements the IComponent interface for a component containing only an head line (name). 

----------------------------------------------------------------*/

class Component : public IComponent
{
public:
    Component(std::ifstream &iFile);
    Component(string name);

public:
    virtual void saveComponent(std::ofstream &oFile);
    virtual void loadComponent(std::ifstream &iFile);
    virtual void printComponent();
    virtual void changeName(string name);
    virtual std::string generateComponent();

public:
    virtual void addField(IField *field);
    virtual void removeField(string name);
    virtual void adjustFieldsOrder(string fieldName, string replaceWith);
    virtual void changeFieldParameter(string name, const vector<string> &params);
    virtual int containtsField(string fieldName);
};