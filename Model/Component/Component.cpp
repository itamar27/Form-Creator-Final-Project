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

<<<<<<< Updated upstream
void Component::adjustFieldsOrder(string name, int newPosition){}
void Component::changeFieldParameter(int index) {}
void Component::saveComponent() {}
void Component::uploadComponent(){}
=======
void Component::changeFieldParameter(string name, const vector<string>& params) {
    for(auto it = _fields.begin(); it != _fields.end(); it++) {
        if((*it)->getName() == name) {
            (*it)->changeParameters(params);
        }
    }
}

void Component::saveComponent(std::ofstream &oFile) {
    int n = 0;
    
    // Write headline
    n = _name.length();
    oFile.write((char*)&n, sizeof(n));
    oFile.write(_name.c_str(), n);

    // Write fields
    int fieldLen = _fields.size();
    oFile.write((char*)&fieldLen, sizeof(fieldLen));
    for(auto it = _fields.begin(); it != _fields.end(); it++) {
        (*it)->saveField(oFile);
    }
}

void Component::loadComponent(std::ifstream &iFile) {
    int n = 0;

    // Read headline
    iFile.read((char*)&n, sizeof(n));
    char* temp = new char[n+1];
    iFile.read(temp, n);
    temp[n] = '\0';
    _name = temp;

    
    // Read fields
    int fieldLen = 0;
    iFile.read((char*)&fieldLen, sizeof(fieldLen));

    for(int i = 0; i<fieldLen; i++) {
        // Read field type
        char* type = new char[4];
        iFile.read(type, 3);
        type[3] = '\0';
        string typeString = type;

        // Check which field to initialize
        Field* field = nullptr;
        if(typeString == "FTF") {
            field = new FreeTextField(iFile);
        } 
        else if(typeString == "IPF") {
            field = new InputField(iFile);
        } 
        else if(typeString == "LSF") {
            field = new ListSelectField(iFile);
        } 
        else if(typeString == "MCF") {
            field = new MultiChoiceField(iFile);
        } 
        else if(typeString == "SCF") {
            field = new SingleCoichField(iFile);
        } 

        // Add field if type was found
        if(field != nullptr) {
            _fields.push_back(field);
        }
    }
}

>>>>>>> Stashed changes
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

