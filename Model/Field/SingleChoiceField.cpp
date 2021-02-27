#include "./SingleChoiceField.h"

void SingleCoichField::saveField(std::ofstream &oFile) {
    int n = 0;
    string type = "SCF";

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

void SingleCoichField::loadField(std::ifstream &iFile) {
    // Read headline
    int n = 0;
    loadHeadLine(iFile);

    // Read list values
    iFile.read((char*)&n, sizeof(n));
    for(int i=0; i<n; i++) {
        int len = 0;
        iFile.read((char*)&len, sizeof(len));
        char* temp = new char[len];
        iFile.read(temp, len);
        temp[len] = '\0';
        string val = temp;
        _values.push_back(val);
    }
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
