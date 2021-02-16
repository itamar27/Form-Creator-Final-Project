#include "./MultiChoiceField.h"

void MultiChoiceField::saveField(std::string name, std::ofstream *oFile) {

}

void MultiChoiceField::loadField(std::ifstream *iFile, std::string name) {

}

std::string MultiChoiceField::generateField() {
    std::string field("");
    field += "<label for='" + _headLine + "'>" + _headLine + "</label><br>\n";
    for(int i=0; i<_values.size(); i++) {
        field += "<input type='checkbox' id='" + _values[i] + "' name= '" + _headLine + to_string(i) + "' value= '" + _values[i] +"'>\n";
        field += "<label for= '" + _values[i] + "'>" + _values[i] + "</label><br>\n";
    }

    return field;

}