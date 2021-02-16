#include "./Model/Field/FreeTextField.h"
#include "./Model/Field/MultiChoiceField.h"
#include "./Model/Field/SingleChoiceField.h"
#include "./Model/Component/Component.h"
#include "./Model/Form/HtmlForm.h"


/*
 * Compilation line:
 * g++ ./Model/Field/MultiChoiceField.cpp ./Model/Field/SingleChoiceField.cpp .\Model\Field\FreeTextField.cpp .\Model\Component\Component.cpp .\Model\Form\HtmlForm.cpp .\ModelChecks.cpp -o Test.exe
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
 * HtmlForm.generate()
 * Component.generate()
 * FreeTextField.generate()
 * SingleChoiceField()
 * SingleChoiceField.addValue()
 * SingleChoiceField.generate()
 * 
 */

int main()
{
    // FreeTextField field("Free Text Field Test");

    // std::cout << field.getHeadLine() << std::endl;

    // field.setHeadLine("TEST TEST TEST");

    // std::cout << field.getHeadLine() << std::endl;

    // Component comp("Testing component");

    // comp.addField(&field);
    // comp.addField(&singleField);

    // FreeTextField field2("Adding a second Field!");

    // comp.addField(&field2);

    // comp.printAllFields();

    // HtmlForm form("My Testing Form!");

    // form.addComponent(&comp);

    // comp.removeField(0);
    // comp.removeField(0);

    // form.printAllComponents();

    // form.removeComponent(0);

    // form.printAllComponents();

    std::cout << "------------------------- NOW GENERATING FORM -------------------------" << std::endl;

    HtmlForm myForm("Free Text Form");

    Component myComponent("Hobbies");

    FreeTextField myFreeTextField("Enter your hobbies here");
    SingleCoichField singleField("Profession");

    singleField.addValue("Doctor");
    singleField.addValue("Developer");
    singleField.addValue("Human Resource");
    singleField.addValue("Other");

    MultiChoiceField multiField("Hobbies Multi select");
    
    multiField.addValue("Soccer");
    multiField.addValue("Gaming");
    multiField.addValue("TV");
    multiField.addValue("Board Games");


    myComponent.addField(&myFreeTextField);
    myComponent.addField(&singleField);
    myComponent.addField(&multiField);
    
    myForm.addComponent(&myComponent);

    myForm.generateForm();
}