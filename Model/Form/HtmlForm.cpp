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

void HtmlForm::saveForm(std::ofstream &oFile) {
    int n = 0;
    
    // Write form name
    n = _name.length();
    oFile.write((char*)&n, sizeof(n));
    oFile.write(_name.c_str(), n);

    // Write all components
    int compLen = _components.size();
    oFile.write((char*)&compLen, sizeof(compLen));
    for(auto it = _components.begin(); it != _components.end(); it++) {
        (*it)->saveComponent(oFile);
    }
}

void HtmlForm::loadForm(std::ifstream &iFile) {
    int n = 0;

    // Read form name
    iFile.read((char*)&n, sizeof(n));
    char* temp = new char[n+1];
    iFile.read(temp, n);
    temp[n] = '\0';
    _name = temp;

    // Read all components
    int compLen = 0;
    iFile.read((char*)&compLen, sizeof(compLen));
    for(int i = 0; i < compLen; i++) {
        Component* comp = new Component(iFile);
        _components.push_back(comp);
    }
}

void HtmlForm::changeFieldData(string componentName, string fieldName, const vector<string>& params) {
    for(auto it = _components.begin(); it != _components.end(); it++) {
        if((*it)->getName() == componentName) {
            (*it)->changeFieldParameter(fieldName, params);
        }
    }
}


