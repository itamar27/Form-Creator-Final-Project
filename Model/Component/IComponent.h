#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "../Field/IField.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace :  IComponent

    Members   : string _name
                vector<IField *> _fields

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
    virtual void printComponent() = 0;

    string getName()
    {
        return _name;
    }
};