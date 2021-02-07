#pragma once

#include <string>
#include <vector>

#include "../Component/Component.h"

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
    virtual void addComponent(Component* component) = 0;
    virtual void removeComponent(int index) = 0;
    virtual void adjustComponentOrder(string name, int newPosition) = 0;
};