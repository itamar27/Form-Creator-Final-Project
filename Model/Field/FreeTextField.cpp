#include "./FreeTextField.h"

void FreeTextField::saveField(std::ofstream &oFile)
{
    int n = 0;
    string type = "IPF";

    // Write type
    n = type.length();
    oFile.write(type.c_str(), n);

    // Write headline
    saveHeadLine(oFile);

    // Write defualt text
    n = _defaultText.length();
    oFile.write((char *)&n, sizeof(n));
    oFile.write(_defaultText.c_str(), n);
}
void FreeTextField::loadField(std::ifstream &iFile)
{
    // Read headline
    int n = 0;
    loadHeadLine(iFile);

    // Read defualt text
    iFile.read((char *)&n, sizeof(n));
    char *temp = new char[n + 1];
    iFile.read(temp, n);
    temp[n] = '\0';
    _defaultText = temp;
}

std::string FreeTextField::generateField()
{
    std::string field("");
    field += "<label for='" + _headLine + "'>" + _headLine + "</label><br>\n";
    field += "<textarea id='" + _headLine + "' name='" + _headLine + "' rows='4' cols='50'>\n";
    field += _defaultText + "\n";
    field += "</textarea><br>\n";

    return field;
}

void FreeTextField::changeParameters(const vector<string> &params)
{
    if (params.size() != 2)
        throw "Not a valid input";
    else
    {
        // Can only add for text fields
        if (params.at(0) == "add")
            _defaultText = params.at(1);
    }
}
