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
std::string Component::generateComponent() {

    std::string component("");
    component += "<h2>" + _name + "</h2>\n";
    for(int i=0; i<_fields.size(); i++) {
        component += _fields[i]->generateField();
        component += "<br>";
    }

    return component;
}

int Component::containtsField(string name) {
    auto it = _fields.begin();
    while(it != _fields.end()) {
        if((*it)->getName() == name)
            return 1;
        
        it++;
    }

    return 0;
}

