#include "./HtmlForm.h"

void HtmlForm::addComponent(Component* component) {
    if(component != nullptr) {
        //Throw exception
    }

    _components.push_back(component);
}

void HtmlForm::removeComponent(int index) {
    if(_components.at(index)){
        _components.erase(_components.begin() + index);
    }
}

void HtmlForm::adjustComponentOrder(string name, int newPosition) {}