#include "./Component.h"

void Component::addField(IField *field)
{
    if (field == nullptr)
    {
        return;
    }

    _fields.insert(_fields.end(), field);
}

void Component::removeField(string name)
{
    for (auto it = _fields.begin(); it != _fields.end(); it++)
    {
        if ((*it)->getName() == name)
        {
            _fields.erase(it);
            return;
        }
    }
}

void Component::adjustFieldsOrder(string fieldName, string replaceWith)
{
    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < _fields.size(); i++)
    {
        if (_fields[i]->getName() == fieldName)
            index1 = i;
        if (_fields[i]->getName() == replaceWith)
            index2 = i;
    }

    // If both fields exists, switch between them
    if (index1 != -1 && index2 != -1)
    {
        auto temp = _fields[index1];
        _fields[index1] = _fields[index2];
        _fields[index2] = temp;
    }
}

void Component::changeFieldParameter(string name, const vector<string> &params)
{
    for (auto it = _fields.begin(); it != _fields.end(); it++)
    {
        if ((*it)->getName() == name)
        {
            (*it)->changeParameters(params);
        }
    }
}

void Component::saveComponent(std::ofstream &oFile)
{
    int n = 0;

    // Write headline
    n = _name.length();
    oFile.write((char *)&n, sizeof(n));
    oFile.write(_name.c_str(), n);

    // Write fields
    int fieldLen = _fields.size();
    oFile.write((char *)&fieldLen, sizeof(fieldLen));
    for (auto it = _fields.begin(); it != _fields.end(); it++)
    {
        (*it)->saveField(oFile);
    }
}

void Component::loadComponent(std::ifstream &iFile)
{
    int n = 0;

    // Read headline
    iFile.read((char *)&n, sizeof(n));
    char *temp = new char[n + 1];
    iFile.read(temp, n);
    temp[n] = '\0';
    _name = temp;

    // Read fields
    int fieldLen = 0;
    iFile.read((char *)&fieldLen, sizeof(fieldLen));

    for (int i = 0; i < fieldLen; i++)
    {
        // Read field type
        char *type = new char[4];
        iFile.read(type, 3);
        type[3] = '\0';
        string typeString = type;

        // Check which field to initialize
        Field *field = nullptr;
        if (typeString == "FTF")
        {
            field = new FreeTextField(iFile);
        }
        else if (typeString == "IPF")
        {
            field = new InputField(iFile);
        }
        else if (typeString == "LSF")
        {
            field = new ListSelectField(iFile);
        }
        else if (typeString == "MCF")
        {
            field = new MultiChoiceField(iFile);
        }
        else if (typeString == "SCF")
        {
            field = new SingleCoichField(iFile);
        }

        // Add field if type was found
        if (field != nullptr)
        {
            _fields.push_back(field);
        }
    }
}

std::string Component::generateComponent()
{

    std::string component("");
    // Add component head line
    component += "<h2>" + _name + "</h2>\n";

    // Add all fields under this component
    for (int i = 0; i < _fields.size(); i++)
    {
        component += _fields[i]->generateField();
        component += "<br>";
    }

    return component;
}

// If the component contains a field, returns 1, if it does not contain it then it returns 0
int Component::containtsField(string name)
{
    auto it = _fields.begin();
    while (it != _fields.end())
    {
        if ((*it)->getName() == name)
            return 1;

        it++;
    }

    return 0;
}
