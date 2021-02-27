#pragma once

#include <string>
#include <vector>

#include "../Component/Component.h"
#include "../Field/Field.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace :  Form
    Memebers  : _name, _components
    Methods   : addComponent()
                removeComponent(field)
                adjustComponentorder(string name, int newPosition)
    
    Description: A class to set an interface for the form strcuture
                 controlling the components that compound the the form sections. 

----------------------------------------------------------------*/

class IForm
{

protected:
    string _name;
    vector<IComponent *> _components;

public:
    void changeName(string name) { _name = name;}
    virtual void addComponent(Component* component) = 0;
    virtual void addField(string componentName, Field* field) = 0;
    virtual void removeComponent(string name) = 0;
    virtual void adjustComponentOrder(string name, int newPosition) = 0;
    virtual void generateForm() = 0;
    virtual int containtsComponent(string name) = 0;
    virtual int containtsField(string componentName ,string fieldName) = 0;
    virtual void saveForm(std::ofstream &oFile) = 0;
    virtual void loadForm(std::ifstream &iFile) = 0;
    virtual void changeFieldData(string componentName, string fieldName, const vector<string>& params) = 0;
};