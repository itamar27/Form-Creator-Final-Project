#include "./Component.h"

void Component::addField(IField *field) {
    if(field == nullptr){
        //throw exception
    }

    _fields.insert(_fields.end(), field);
}

void Component::removeField(int index) {
    if(_fields.at(index))
        _fields.erase(_fields.begin()+index);
}

void Component::adjustFieldsOrder(string name, int newPosition){}
void Component::changeFieldParameter(int index) {}
void Component::saveComponent() {}
void Component::uploadComponent(){}
