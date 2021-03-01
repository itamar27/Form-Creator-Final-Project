#include "HtmlFormModel.h"

// The path to the templates directory
string path = "./Templates/";

void HtmlFormModel::printModel()
{

    if (_form != nullptr)
    {
        _form->printForm();
    }
    else
    {
        std::cout << "There is no existing form yet" << std::endl;
    }
}

string HtmlFormModel::newForm(string name)
{
    string returnMsg;

    // If a form already exists, delete its allcation
    if (_form != nullptr)
    {
        delete _form;
    }

    _form = new HtmlForm(name);
    return name + " have been created";
}

string HtmlFormModel::loadForm(string fileName)
{
    // If a form already exists, delete its allcation
    if (_form != nullptr)
    {
        delete _form;
    }
    fileName += ".txt";

    std::ifstream iFile(path + fileName, std::ios::out | std::ios::binary);
    if (!iFile.is_open())
    {
        return "Could not find selected file name";
    }

    _form = new HtmlForm(iFile);
    iFile.close();

    if (_form)
        return "Form was loaded successfully";
    else
    {
        _form = nullptr;
        return "Problem loading form";
    }
}

string HtmlFormModel::saveForm(string fileName)
{
    if (_form == nullptr)
    {
        return "Please create or load a form before saving";
    }

    fileName += ".txt";
    std::ofstream oFile(path + fileName, std::ios::out | std::ios::binary);
    if (!oFile.is_open())
    {
        return "Error opening file, please try to save again";
    }

    _form->saveForm(oFile);
    oFile.close();
    return "Form has been saved";
}

string HtmlFormModel::changeFormName(string newName)
{
    if (_form == nullptr)
    {
        return "Please create or load a form before executing commands on it";
    }

    _form->changeName(newName);
    return "Name changed successfully to '" + newName + "'";
}

string HtmlFormModel::generateForm()
{
    if (_form == nullptr)
        return "Please create or load a form before executing commands on it";

    _form->generateForm();

    return "Form has been generated";
}

string HtmlFormModel::addComponent(string componentName)
{
    if (_form == nullptr)
    {
        return "Please create or load a form before executing commands on it";
    }
    if (_form->containtsComponent(componentName))
    {
        return "This component '" + componentName + "' already exists";
    }

    _form->addComponent(new Component(componentName));

    return "Added component " + componentName;
}

string HtmlFormModel::removeComponent(string componentName)
{
    if (_form == nullptr)
    {
        return "Please create or load a form before executing commands on it";
    }
    if (_form->containtsComponent(componentName) == 0)
    {
        return "This component '" + componentName + "' doesn't exists";
    }

    _form->removeComponent(componentName);

    return "Component has been removed";
}

string HtmlFormModel::changeComponentName(string componentName, string newName)
{

    if (_form == nullptr)
    {
        return "Please create or load a form before executing commands on it";
    }
    if (_form->containtsComponent(componentName) == 0)
    {
        return "This component '" + componentName + "' doesn't exists";
    }

    _form->changeComponentName(componentName, newName);
    return "Component's name changed successfully";
}

string HtmlFormModel::adjustComponentOrder(string componentName, string replaceWith)
{
    if (_form == nullptr)
    {
        return "Please create or load a form before executing commands on it";
    }
    if (_form->containtsComponent(componentName) == 0)
    {
        return "This component '" + componentName + "' doesn't exists";
    }
    if (_form->containtsComponent(replaceWith) == 0)
    {
        return "This component '" + replaceWith + "' doesn't exists";
    }

    _form->adjustComponentOrder(componentName, replaceWith);
    return "Components order changed successfully";
}

string HtmlFormModel::addField(string componentName, string fieldName, string type)
{
    if (_form == nullptr)
    {
        return "Please create or load a form before executing commands on it";
    }
    if (_form->containtsComponent(componentName) == 0)
    {
        return "This component '" + componentName + "' doesn't exists";
    }
    if (_form->containtsField(componentName, fieldName))
    {
        return "This field '" + fieldName + "' already exists";
    }

    string msg = "Bad type name";
    if (type == "FreeTextField")
    {
        _form->addField(componentName, new FreeTextField(fieldName));
        msg = "Field " + fieldName + " has been added";
    }
    if (type == "InputField")
    {
        _form->addField(componentName, new InputField(fieldName));
        msg = "Field " + fieldName + " has been added";
    }
    if (type == "ListSelectField")
    {
        _form->addField(componentName, new ListSelectField(fieldName));
        msg = "Field " + fieldName + " has been added";
    }
    if (type == "MultiChoiceField")
    {
        _form->addField(componentName, new MultiChoiceField(fieldName));
        msg = "Field " + fieldName + " has been added";
    }
    if (type == "SingleChoiceField")
    {
        _form->addField(componentName, new SingleChoiceField(fieldName));
        msg = "Field " + fieldName + " has been added";
    }

    return msg;
}

string HtmlFormModel::removeField(string componentName, string fieldName)
{
    if (_form == nullptr)
    {
        return "Please create or load a form before executing commands on it";
    }
    if (_form->containtsComponent(componentName) == 0)
    {
        return "This component '" + componentName + "' doesn't exists";
    }
    if (_form->containtsField(componentName, fieldName) == 0)
    {
        return "This field '" + fieldName + "' doesn't exists";
    }
    _form->removeField(componentName, fieldName);
    return "Field " + fieldName + " has been removed";
}

string HtmlFormModel::adjustFieldOrder(string componentName, string fieldName, string replaceWith)
{
    if (_form == nullptr)
    {
        return "Please create or load a form before executing commands on it";
    }
    if (_form->containtsComponent(componentName) == 0)
    {
        return "This component '" + componentName + "' doesn't exists";
    }
    if (_form->containtsField(componentName, fieldName) == 0)
    {
        return "This field '" + fieldName + "' doesn't exists";
    }
    if (_form->containtsField(componentName, replaceWith) == 0)
    {
        return "This field '" + replaceWith + "' doesn't exists";
    }

    _form->adjustFieldOrder(componentName, fieldName, replaceWith);
    return "Fields order has changed successfully";
}

string HtmlFormModel::setFieldData(string componentName, string fieldName, const vector<string> &params)
{
    if (_form == nullptr)
    {
        return "Please create or load a form before executing commands on it";
    }
    if (_form->containtsComponent(componentName) == 0)
    {
        return "This component '" + componentName + "' doesn't exists";
    }
    if (_form->containtsField(componentName, fieldName) == 0)
    {
        return "This field '" + fieldName + "' doesn't exists";
    }

    _form->changeFieldData(componentName, fieldName, params);

    return "Changed field successfully";
}
