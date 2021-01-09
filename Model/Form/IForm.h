#include <string>
#include <vector>

#include "../Component/IComponent.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace :  Component
    Memebers  : _name, _fields
    Methods   : addField()
                removeField(field)
                adjustOrder(string name, int newPosition)
    
    Description: A class to set an interface for every component 
                 that is part of the form's general structure. 

----------------------------------------------------------------*/

class IForm
{

private:
    string _name;
    vector<IComponent> _components;

public:
    virtual void addComponent(IComponent component) = 0;
    virtual void removeComponent(IComponent component) = 0;
};