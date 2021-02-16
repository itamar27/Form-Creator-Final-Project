#include "./SingleChoiceField.h"

void SingleCoichField::saveField(std::string name, std::ofstream *oFile) {

}

void SingleCoichField::loadField(std::ifstream *iFile, std::string name) {

}

std::string SingleCoichField::generateField() {
    std::string field("");
    field += "<label for='" + _headLine + ":'>" + _headLine + "</label><br>\n";
    for(int i=0; i<_values.size(); i++) {
        field += "<input type='radio' id='" + _values[i] + "' name= '" + _headLine + "' value= '" + _values[i] +"'>\n";
        field += "<label for= '" + _values[i] + "'>" + _values[i] + "</label><br>\n";
    }

    return field;
}
