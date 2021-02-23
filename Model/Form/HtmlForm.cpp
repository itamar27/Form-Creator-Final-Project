#include "./HtmlForm.h"

void HtmlForm::addComponent(Component *component)
{
    if (component != nullptr)
    {
        //Throw exception
    }

    _components.push_back(component);
}

void HtmlForm::addField(string componentName, Field* field) {
    for(auto it=_components.begin(); it != _components.end(); it++) {
        if((*it)->getName() == componentName) {
            (*it)->addField(field);
        }
    }    
}


void HtmlForm::removeComponent(string name)
{
    for(int i=0; i<_components.size(); i++) {
        if(_components[i]->getName() == name) {
            _components.erase(_components.begin() + i);
        }
    }
}

void HtmlForm::adjustComponentOrder(string name, int newPosition) {}

void HtmlForm::generateForm()
{
    std::string form("");
    std::string fileName("");

    form += "<!DOCTYPE html>\n";
    form += "<html>\n";
    form += "<head>\n";
    form += "<title>" + _name + "</title>\n";
    form += "</head>\n";
    form += "<body>\n";
    form += "<h1>" + _name + "</h1>\n";

    for (int i = 0; i < _components.size(); i++)
    {
        form += _components[i]->generateComponent();
    }

    form += "</body>\n";
    form += "</html>";

    fileName = _name + ".html";

    std::ofstream ofs;
    ofs.open(fileName, std::fstream::in | std::fstream::out | std::ofstream::trunc);

    ofs << form;

    ofs.close();
}

int HtmlForm::containtsComponent(string name) {
    auto it = _components.begin();
    while(it != _components.end()) {
        if((*it)->getName() == name)
            return 1;
        
        it++;
    }

    return 0;
}

int HtmlForm::containtsField(string componentName ,string fieldName) {
    auto it = _components.begin();
    while(it != _components.end()) {
        if((*it)->getName() == componentName)
            return (*it)->containtsField(fieldName);
        
        it++;
    }

    return 0;
}

