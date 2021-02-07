#include "./FreeTextField.h"

void FreeTextField::saveField(std::string name, std::ofstream *oFile)
{
}
void FreeTextField::loadField(std::ifstream *iFile, std::string name)
{
}
void FreeTextField::generateField()
{
}
void FreeTextField::changeParameters(const vector<string> &params)
{
    if (params.size() != 1)
        throw "Not a valid input";
    else
    {
        _defaultText = params[0];
    }
}
