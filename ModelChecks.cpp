#include "./Model/Field/FreeTextField.h"
#include "./Model/Component/Component.h"
#include "./Model/Form/HtmlForm.h"


/*
 * Compilation line:
 * g++ .\Model\Field\FreeTextField.cpp .\Model\Component\Component.cpp .\Model\Form\HtmlForm.cpp .\ModelChecks.cpp -o Test.exe
 * 
 * Please update it if you are editing this file.
 */


/*
 *
 * So far the following has been tested:
 * Field.getHeaLine()
 * Field.setHeadLine()
 * FreeTextField()
 * Component()
 * Componenet.addField()
 * Component.removeField()
 * HtmlForm()
 * 
 */

int main()
{
    FreeTextField field("Free Text Field Test");

    std::cout << field.getHeadLine() << std::endl;

    field.setHeadLine("TEST TEST TEST");

    std::cout << field.getHeadLine() << std::endl;

    Component comp("Testing component");

    comp.addField(&field);
    
    FreeTextField field2("Adding a second Field!");

    comp.addField(&field2);

    comp.printAllFields();

    HtmlForm form("My Testing Form!");

    form.addComponent(&comp);

    comp.removeField(0);
    comp.removeField(0);

    form.printAllComponents();

    form.removeComponent(0);

    form.printAllComponents();

}