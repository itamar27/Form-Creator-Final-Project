#include "./ListSelectField.h"

<<<<<<< Updated upstream
void ListSelectField::saveField(std::string name, std::ofstream *oFile) {

}

void ListSelectField::loadField(std::ifstream *iFile, std::string name) {

=======
void ListSelectField::saveField(std::ofstream &oFile) {
    int n = 0;
    string type = "LSF";

    // Write type
    n = type.length();
    oFile.write(type.c_str(), n);

    // Write headline
    saveHeadLine(oFile);

    // Write list values
    n = _values.size();
    oFile.write((char*)&n, sizeof(n));
    for(int i=0; i<n; i++) {
        int len = _values[i].length();
        oFile.write((char*)&len, sizeof(len));
        oFile.write(_values[i].c_str(), len);
    }

}

void ListSelectField::loadField(std::ifstream &iFile) {
    // Read headline
    int n = 0;
    loadHeadLine(iFile);

    // Read list values
    iFile.read((char*)&n, sizeof(n));
    for(int i=0; i<n; i++) {
        int len = 0;
        iFile.read((char*)&len, sizeof(len));
        char* temp = new char[len+1];
        iFile.read(temp, len);
        temp[len] = '\0';
        string val = temp;
        _values.push_back(val);
    }
>>>>>>> Stashed changes
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