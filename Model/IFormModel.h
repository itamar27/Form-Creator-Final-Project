#include <string>

#include "./Form/IForm.h"

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

class IFormModel
{

public:
    virtual void newForm(string name) = 0;
    virtual void loadForm(string name) = 0;
    virtual void saveForm(string name) = 0;
    virtual void changeFormName(string formName, string newName) = 0;

public:
    virtual void addComponent(string name, string type) = 0;
    virtual void removeComponent(string name) = 0;
    virtual void changeComponentName(string componentName, string newName) = 0;
    virtual void adjustComponentOrder(string name, int newPoistion) = 0;

public:
    virtual void addField(string name, string type) = 0;
    virtual void removeField(string name) = 0;
    virtual void adjustFieldOrder(string name, int newPoistion) = 0;

    //virtual setFieldData(string name, int index) = 0;  ------------> what is this method using for?

};
