#include "./InputField.h"

void InputField::saveField(std::string name, std::ofstream *oFile)
{
}
void InputField::loadField(std::ifstream *iFile, std::string name)
{
}

std::string InputField::generateField()
{
    std::string field("");
    field += "<label for='" + _headLine + "'>" + _headLine + "</label><br>";
    field += "<input type='text' id='" + _headLine + "' name='" + _headLine + "' value='" + _defaultText + "'><br>";

    return field;
}