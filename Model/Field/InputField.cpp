#include "./InputField.h"

void InputField::saveField(std::ofstream &oFile)
{
    int n = 0;
    string type = "IPF";

    // Write type
    n = type.length();
    oFile.write(type.c_str(), n);

    // Write headline
    saveHeadLine(oFile);

    // Write default text
    n = _defaultText.length();
    oFile.write((char *)&n, sizeof(n));
    oFile.write(_defaultText.c_str(), n);
}

void InputField::loadField(std::ifstream &iFile)
{
    // Read headline
    int n = 0;
    loadHeadLine(iFile);

    // Read default text
    iFile.read((char *)&n, sizeof(n));
    char *temp = new char[n + 1];
    iFile.read(temp, n);
    temp[n] = '\0';
    _defaultText = temp;
}

std::string InputField::generateField()
{
    std::string field("");
    field += "<label for='" + _headLine + "'>" + _headLine + "</label><br>";
    field += "<input type='text' id='" + _headLine + "' name='" + _headLine + "' value='" + _defaultText + "'><br>";

    return field;
}

void InputField::changeParameters(const vector<string> &params)
{
    if (params.size() != 2)
        throw "Not a valid input";
    else
    {
        // Can only add to text field
        if (params.at(0) == "add")
            _defaultText = params.at(1);
    }
}