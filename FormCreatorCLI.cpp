#include "./View/CLI.h"

// To make and exe file, run the comment in the next row.
// g++ ./Model/Field/InputField.cpp ./Model/Field/ListSelectField.cpp ./Model/Field/MultiChoiceField.cpp ./Model/Field/SingleChoiceField.cpp .\Model\Field\FreeTextField.cpp .\Model\Component\Component.cpp .\Model\Form\HtmlForm.cpp .\Model\HtmlFormModel.cpp .\View\CLI.cpp .\Controller\MyController.cpp .\FormCreatorCLI.cpp -o FormCreatorCLI.exe

int main() {
    CLI* myCLI = new CLI(std::cout, std::cin);

    myCLI->start();

    return 0;
}