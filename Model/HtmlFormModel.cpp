#include "HtmlFormModel.h"

string HtmlFormModel::newForm(string name){
    string returnMsg;
    if(_forms.find(name) == _forms.end()){
        _forms[name] = new HtmlForm(name);
        returnMsg = name + " have been created\n";
    }
    else {
        returnMsg = name + " already exists\n";
    }
    
    return returnMsg;
}

string HtmlFormModel::loadForm(string name) {
    return "";
}

string HtmlFormModel::saveForm(string name) {
    return "";
}

string HtmlFormModel::changeFormName(string formName, string newName) {
    auto it = _forms.find(formName);
    if(it == _forms.end()) {
        return "Form '" + formName + "' doesn't exists\n";
    }
    if(_forms.find(newName) == _forms.end()) {
        return "The name ;" + newName + "' already exists\n";
    }

    (*it).second->changeName(newName);
    _forms[newName] = (*it).second;

    _forms.erase(formName);
    
    return "Name changed from '" + formName + "' to '" + newName + "'\n";
}

string HtmlFormModel::generateForm(string name) {
    if(_forms.find(name) == _forms.end()) {
        return "No form exists with this name: " + name + "\n";
    }

    _forms[name]->generateForm();

    return "Form generated\n";
}


string HtmlFormModel::addComponent(string formName, string componentName) {
    if(_forms.find(formName) == _forms.end()) {
        return "No form exists with this name: " + formName + "\n";
    }
    if(_forms[formName]->containtsComponent(componentName)) {
        return "This component '"+componentName+"' already exists\n";
    }

    _forms[formName]->addComponent(new Component(componentName));

    return "Added component " + componentName + "\n";
}

string HtmlFormModel::removeComponent(string formName, string componentName) {
    if(_forms.find(formName) == _forms.end()) {
        return "Form '" + formName + "' doesn't exists";
    }

    _forms[formName]->removeComponent(componentName);

    return "Component has been removed\n";
}

string HtmlFormModel::changeComponentName(string componentName, string newName){
    return "\n";
}

string HtmlFormModel::adjustComponentOrder(string name, int newPoistion) {
    return "\n";
}

string HtmlFormModel::addField(string formName, string componentName, string fieldName, string type){
    if(_forms.find(formName) == _forms.end()) {
        return "No form exists with this name: " + formName + "\n";
    }
    if(_forms[formName]->containtsComponent(componentName) == 0) {
        return "No component exists with this name: " + componentName + "\n";
    }
    if(_forms[formName]->containtsField(componentName ,fieldName)) {
       return "This field '" + fieldName + "' already exists\n";
    }
    
    if(type == "FreeTextField") {
        _forms[formName]->addField(componentName, new FreeTextField(fieldName));
    }
    if(type == "InputField") {
        _forms[formName]->addField(componentName, new InputField(fieldName));
    }
    if(type == "ListSelectField") {
        _forms[formName]->addField(componentName, new ListSelectField(fieldName));
    }
    if(type == "MultiChoiceField") {
        _forms[formName]->addField(componentName, new MultiChoiceField(fieldName));
    }
    if(type == "SingleChoiceField") {
        _forms[formName]->addField(componentName, new SingleCoichField(fieldName));
    }

    return "Field " + fieldName + " has been added\n";
}

string HtmlFormModel::removeField(string name) {
    return "";
}

string HtmlFormModel::adjustFieldOrder(string name, int newPoistion) {
    return "";
}

string HtmlFormModel::setFieldData(string name, int index) {
    return "";
}
