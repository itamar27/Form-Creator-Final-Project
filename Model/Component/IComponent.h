#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "../Field/IField.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace :  IComponent
    Memebers  : _name, _fields
    Methods   : changeName(string name)
                addField(IField *field)
                removeField(string name)
                adjustFieldsOrder(string fieldName, string replaceWith)
                changeFieldParameter(string name, const vector<string> &params)
                saveComponent(std::ofstream &oFile)
                loadComponent(std::ifstream &iFile)
                generateComponent()
                containtsField(string fieldName)
                getName()
                printAllFields()
    
    Description: A class to set an interface for every component that is 
                 part of the form's general structure, all methods needs
                 to be implemented except getName() and printAllFields(). 

----------------------------------------------------------------*/

class IComponent
{

protected:
    string _name;
    vector<IField *> _fields;

public:
    virtual void changeName(string name) = 0;
    virtual void addField(IField *field) = 0;
    virtual void removeField(string name) = 0;
    virtual void adjustFieldsOrder(string fieldName, string replaceWith) = 0;
    virtual void changeFieldParameter(string name, const vector<string> &params) = 0;

public:
    virtual void saveComponent(std::ofstream &oFile) = 0;
    virtual void loadComponent(std::ifstream &iFile) = 0;
    virtual std::string generateComponent() = 0;
    virtual int containtsField(string fieldName) = 0;

    string getName()
    {
        return _name;
    }

    //The following are for testing!!!
    void printAllFields()
    {
        std::cout << "Component name: " << _name << std::endl;

        for (int i = 0; i < _fields.size(); i++)
        {
            std::cout << (i + 1) << ". ";
            std::cout << _fields[i]->getHeadLine() << std::endl;
        }
    }
};