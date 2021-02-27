// #include "./Model/Field/FreeTextField.h"
// #include "./Model/Field/InputField.h"
// #include "./Model/Field/ListSelectField.h"
// #include "./Model/Field/MultiChoiceField.h"
// #include "./Model/Field/SingleChoiceField.h"
// #include "./Model/Component/Component.h"
// #include "./Model/Form/HtmlForm.h"
#include "./Model/HtmlFormModel.h"


/*
 * Compilation line:
 * g++ ./Model/Field/InputField.cpp ./Model/Field/ListSelectField.cpp ./Model/Field/MultiChoiceField.cpp ./Model/Field/SingleChoiceField.cpp .\Model\Field\FreeTextField.cpp .\Model\Component\Component.cpp .\Model\Form\HtmlForm.cpp .\Model\HtmlFormModel.cpp .\ModelChecks.cpp -o Test.exe
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
 * ListSelectField()
 * ListSelectField.generate()
 * ListSelectField.addValue()
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

    // std::cout << "------------------------- NOW GENERATING FORM -------------------------" << std::endl;

    // HtmlForm myForm("Free Text Form");

    // Component myComponent("Hobbies");
    // Component listComponent("Same Hobbies in list");

    // InputField bestHobby("Best Hobby",  "Your best hobby is?");
    // InputField worstHobby("Worst Hobby");
    // FreeTextField myFreeTextField("Enter your hobbies here");
    // SingleCoichField singleField("Profession");

    // singleField.addValue("Doctor");
    // singleField.addValue("Developer");
    // singleField.addValue("Human Resource");
    // singleField.addValue("Other");

    // MultiChoiceField multiField("Hobbies Multi select");
    
    // multiField.addValue("Soccer");
    // multiField.addValue("Gaming");
    // multiField.addValue("TV");
    // multiField.addValue("Board Games");

    // ListSelectField listField("Hobbies list");

    // listField.addValue("Soccer");
    // listField.addValue("Gaming");
    // listField.addValue("TV");
    // listField.addValue("Board Games");


    // myComponent.addField(&myFreeTextField);
    // myComponent.addField(&singleField);
    // myComponent.addField(&multiField);

    // listComponent.addField(&listField);
    // listComponent.addField(&bestHobby);
    // listComponent.addField(&worstHobby);
    
    // myForm.addComponent(&myComponent);
    // myForm.addComponent(&listComponent);

    // myForm.generateForm();


    ///---------------- TESTS 190221 ----------------///

    // InputField userName("User Name", "Barak Daniel 22222");
    // InputField password("Password");

    // FreeTextField aboutYourself("Describe yourself");

    // Component mainComponent("Register");

    // HtmlForm signUp("CHECK1");

    // mainComponent.addField(&userName);
    // mainComponent.addField(&password);
    // mainComponent.addField(&aboutYourself);

    // signUp.addComponent(&mainComponent);

    // signUp.generateForm();

    ///---------------- TESTS 230221 ----------------///

<<<<<<< Updated upstream
    HtmlFormModel myModel;

    myModel.newForm("Checking the model facade");
    myModel.addComponent("Checking the model facade", "First component");
    myModel.addComponent("Checking the model facade", "Second component");
    myModel.addField("Checking the model facade", "Second component", "username", "InputField");
    myModel.addField("Checking the model facade", "Second component", "password", "InputField");
    myModel.addField("Checking the model facade", "First component", "About you", "FreeTextField");

    myModel.generateForm("Checking the model facade");
=======
    // HtmlFormModel myModel;

    // myModel.newForm("Checking the model facade");
    // myModel.addComponent("Checking the model facade", "First component");
    // myModel.addComponent("Checking the model facade", "Second component");
    // myModel.addField("Checking the model facade", "Second component", "username", "InputField");
    // myModel.addField("Checking the model facade", "Second component", "password", "InputField");
    // myModel.addField("Checking the model facade", "First component", "About you", "FreeTextField");

    // myModel.generateForm("Checking the model facade");


    ///---------------- TESTS 250221 ----------------///

    // FreeTextField testField("myField", "DEFUALT TEXT IS HERE!!!!");

    // std::ofstream saveFile("TESTSAVE.txt", std::ios::out | std::ios::binary);

    // testField.saveField(saveFile);

    // saveFile.close();

    // std::ifstream iFile("TESTSAVE.txt", std::ios::out | std::ios::binary);

    // char* temp = new char[4];
    // iFile.read(temp, 3);
    // temp[3] = '\0';
    // string type = temp;
    // std::cout << type << std::endl; 
    
    // FreeTextField loadingField(iFile);

    // std::cout << loadingField.getName() << std::endl;

    // ListSelectField listSelecet("select one");

    // listSelecet.addValue("One");
    // listSelecet.addValue("Two");
    // listSelecet.addValue("Three");

    // std::ofstream saveFile("TESTSAVE.txt", std::ios::out | std::ios::binary);

    // listSelecet.saveField(saveFile);

    // saveFile.close();

    // std::ifstream iFile("TESTSAVE.txt", std::ios::out | std::ios::binary);

    // char* temp = new char[4];
    // iFile.read(temp, 3);
    // temp[3] = '\0';
    // string type = temp;
    // std::cout << type << std::endl; 
    
    // ListSelectField loadingField(iFile);

    // std::cout << loadingField.getName() << std::endl;

    // Component* testSave = new Component("Testing save component");

    // FreeTextField* ftf = new FreeTextField("field one");
    // InputField* ipf = new InputField("field two");
    // ListSelectField* lsf = new ListSelectField("field three");
    // MultiChoiceField* mcf = new MultiChoiceField("field four");
    // SingleCoichField* scf = new SingleCoichField("field five");

    // testSave->addField(ftf);
    // testSave->addField(ipf);
    // testSave->addField(lsf);
    // testSave->addField(mcf);
    // testSave->addField(scf);

    // std::ofstream saveFile("TestComponent.txt", std::ios::out | std::ios::binary);

    // testSave->saveComponent(saveFile);

    // saveFile.close();

    // std::ifstream loadFile("TestComponent.txt", std::ios::out | std::ios::binary);

    // Component* comp = new Component(loadFile);

    // comp->printAllFields();

    ///---------------- TESTING ALL THE MODEL FOR SAVE/LOAD ----------------///

    HtmlFormModel myModel;

    myModel.newForm("prototype1");
    myModel.changeFormName("prototype1", "prototype");

    
    myModel.addComponent("prototype", "meta data");
    myModel.addField("prototype", "meta data", "about yourself", "FreeTextField");
    myModel.addField("prototype", "meta data", "hobbies", "MultiChoiceField");
    vector<string> vec;
    vec.push_back("add");
    vec.push_back("Soccer");
    myModel.setFieldData("prototype", "meta data", "hobbies", vec);
    vec[1] = "Gaming";
    myModel.setFieldData("prototype", "meta data", "hobbies", vec);
    vec[1] = "Anime";
    myModel.setFieldData("prototype", "meta data", "hobbies", vec);

    myModel.addField("prototype", "meta data", "sex", "SingleChoiceField");
    vec[1] = "Male";
    myModel.setFieldData("prototype", "meta data", "sex", vec);
    vec[1] = "Female";
    myModel.setFieldData("prototype", "meta data", "sex", vec);

    myModel.addComponent("prototype", "User info");
    myModel.addField("prototype", "User info", "email", "InputField");
    myModel.addField("prototype", "User info", "password", "InputField");

    myModel.generateForm("prototype");
    myModel.saveForm("prototype", "prototype_bin");

    myModel.loadForm("prototype", "prototype_bin");

    myModel.generateForm("prototype");
>>>>>>> Stashed changes
}