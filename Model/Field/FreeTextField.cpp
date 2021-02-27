#include "./FreeTextField.h"

void FreeTextField::saveField(std::string name, std::ofstream *oFile)
{
}
void FreeTextField::loadField(std::ifstream *iFile, std::string name)
{
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
    if (params.size() != 1)
        throw "Not a valid input";
    else
    {
        _defaultText = params.at(0);
    }
}
