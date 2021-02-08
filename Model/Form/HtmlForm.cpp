#include "./HtmlForm.h"

void HtmlForm::addComponent(Component *component)
{
    if (component != nullptr)
    {
        //Throw exception
    }

    _components.push_back(component);
}

void HtmlForm::removeComponent(int index)
{
    if (_components.at(index))
    {
        _components.erase(_components.begin() + index);
    }
}

void HtmlForm::adjustComponentOrder(string name, int newPosition) {}

void HtmlForm::generateForm()
{
    std::string form("");
    std::string fileName("");

    form += "<!DOCTYPE html>\n";
    form += "<html>\n";
    form += "<head>\n";
    form += "<title>" + _name + "</title>\n";
    form += "</head>\n";
    form += "<body>\n";
    form += "<h1>" + _name + "</h1>\n";

    for (int i = 0; i < _components.size(); i++)
    {
        form += _components[i]->generateComponent();
    }

    form += "</body>\n";
    form += "</html>";

    fileName = _name + ".html";

    std::ofstream ofs;
    ofs.open(fileName, std::fstream::in | std::fstream::out | std::ofstream::trunc);

    ofs << form;

    ofs.close();
}
