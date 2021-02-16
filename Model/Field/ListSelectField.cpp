#include "./ListSelectField.h"

void ListSelectField::saveField(std::string name, std::ofstream *oFile) {

}

void ListSelectField::loadField(std::ifstream *iFile, std::string name) {

}

std::string ListSelectField::generateField() {
    std::string field("");
    field += "<label for='" + _headLine + "'>" + _headLine + "</label><br>\n";
    field += "<select name='" + _headLine + "' id='" + _headLine + "'>";
    for(int i=0; i<_values.size(); i++) {
        field += "<option value='" + _values[i] + "'>" + _values[i] + "</option>";
    }
    field += "</select><br>";

    return field;
}