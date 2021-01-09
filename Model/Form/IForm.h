#include <string>
#include <vector>

#include "../Component/IComponent.h"

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

private:
    string _name;
    vector<IComponent> _components;

public:
    virtual void addComponent(IComponent component) = 0;
    virtual void removeComponent(IComponent component) = 0;
    virtual void adjustComponentOrder(string name, int newPosition) = 0;
};