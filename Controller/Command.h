#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "../View/IView.h"
#include "../Model/IFormModel.h"

using namespace std;

/*----------------------------------------------------------------

    Class     : Command

    Members   :  IView* _view
                 IFormModel* _model
            
    Methods   : execute()
    
    Description: For this design pattern we implement each command with only one method,
                 execute() which takes the data received from the input in the view and
                 making it ready for the model execution and then calling the model to
                 execute it.

----------------------------------------------------------------*/

class Command
{
public:
    Command(IView *view, IFormModel *model) : _view(view), _model(model) {}

public:
    virtual void execute() = 0;
    string getInput(string msg)
    {
        string retVal;
        _view->display(msg);

        getline(cin, retVal);
        return retVal;
    }

protected:
    IView *_view;
    IFormModel *_model;
};


/**
 *  ----------Commands implementation---------------    
 *      This section is an extend to the basic command class. 
 *      For each command that the system has (every interaction between the controller and the model),
 *      there is class below that implements this command.  
 *  ------------------------------------------------
 **/

/* 
 *      Class: NewFormCommand
 *      Description: This command execute the call for a new form in the model.
 */

class NewFormCommand : public Command
{

public:
    NewFormCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }
    virtual void execute()
    {
        string msg;

        if (_model->isFormExists())
        {
            string decision = "Your are already working on a form, enter the number of the option you want to make:\n1. Save current form and make a new one\n2. Stay on the current form";
            decision = getInput(decision);
            if (decision == "1")
            {
                string name = getInput("Enter a file name to save");
                msg = _model->saveForm(name);
                _view->display(msg);
            }
            else if (decision == "2")
            {
                msg = "Canceling new form creation";
                _view->display(msg);
                return;
            }
            else
            {
                msg = "Bad argument was given, please select '1' or '2'";
                _view->display(msg);
                return;
            }
        }
        string toSend = getInput("Please enter a form name:");

        msg = _model->newForm(toSend);
        _view->display(msg);
    }
};

/* 
 *      Class: LoadFormCommand
 *      Description: This command execute the call for a load form in the model.
 */

class LoadFormCommand : public Command
{

public:
    LoadFormCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string msg;

        if (_model->isFormExists())
        {
            string decision = "Your are already working on a form, enter the number of the option you want to make:\n1. Save current form and make a new one\n2. Stay on the current form";
            decision = getInput(decision);
            if (decision == "1")
            {
                string name = getInput("Enter a file name to save");
                msg = _model->saveForm(name);
                _view->display(msg);
            }
            else if (decision == "2")
            {
                msg = "Canceling loading";
                _view->display(msg);
                return;
            }
            else
            {
                msg = "Bad argument was given, please select '1' or '2'";
                _view->display(msg);
                return;
            }
        }

        string toSend = getInput("Please enter a file name:");

        msg = _model->loadForm(toSend);
        _view->display(msg);
    }
};

/* 
 *      Class: SaveFormCommand
 *      Description: This command execute the call for a save form in the model.
 */

class SaveFormCommand : public Command
{

public:
    SaveFormCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string toSend = getInput("Please enter a file name:");

        string msg = _model->saveForm(toSend);
        _view->display(msg);
    }
};

/* 
 *      Class: ChangeFormNameCommand
 *      Description: This command execute the call for a change form name in the model.
 */

class ChangeFormNameCommand : public Command
{

public:
    ChangeFormNameCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string toSend = getInput("Please enter a new form name:");

        string msg = _model->changeFormName(toSend);
        _view->display(msg);
    }
};

/* 
 *      Class: GenerateFormCommand
 *      Description: This command execute the call for generating the form in the model.
 */

class GenerateFormCommand : public Command
{

public:
    GenerateFormCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string msg = _model->generateForm();
        _view->display(msg);
    }
};

/* 
 *      Class: AddComponentCommand
 *      Description: This command execute the call for adding component in the model.
 */

class AddComponentCommand : public Command
{

public:
    AddComponentCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string toSend = getInput("Please enter component name:");

        string msg = _model->addComponent(toSend);
        _view->display(msg);
    }
};

/* 
 *      Class: RemoveComponentCommand
 *      Description: This command execute the call for removing component in the model.
 */

class RemoveComponentCommand : public Command
{

public:
    RemoveComponentCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string toSend = getInput("Please enter component name:");

        string msg = _model->removeComponent(toSend);
        _view->display(msg);
    }
};

/* 
 *      Class: ChangeComponentNameCommand
 *      Description: This command execute the call for changing component name in the model.
 */

class ChangeComponentNameCommand : public Command
{

public:
    ChangeComponentNameCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string stringName = getInput("Please enter component name:");
        string stringRename = getInput("Please enter a new name:");

        string msg = _model->changeComponentName(stringName, stringRename);
        _view->display(msg);
    }
};

/* 
 *      Class: AdjustComponentOrderCommand
 *      Description: This command execute the call for adjusting components order in the model.
 */

class AdjustComponentOrderCommand : public Command
{

public:
    AdjustComponentOrderCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string stringName = getInput("Please enter the first component name:");
        string replaceWith = getInput("Please enter the second component name:");

        string msg = _model->adjustComponentOrder(stringName, replaceWith);
        _view->display(msg);
    }
};

/* 
 *      Class: AddFieldCommand
 *      Description: This command execute the call for adding a field in the model.
 */

class AddFieldCommand : public Command
{

public:
    AddFieldCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string compName = getInput("Please enter the component name:");
        string fieldName = getInput("Please enter the field name:");
        string type = getInput("Please enter the field type:");

        string msg = _model->addField(compName, fieldName, type);
        _view->display(msg);
    }
};

/* 
 *      Class: RemoveFieldCommand
 *      Description: This command execute the call for removing a field in the model.
 */

class RemoveFieldCommand : public Command
{

public:
    RemoveFieldCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string compName = getInput("Please enter the component name:");
        string fieldName = getInput("Please enter the field name:");

        string msg = _model->removeField(compName, fieldName);
        _view->display(msg);
    }
};

/* 
 *      Class: AdjustFieldOrderCommand
 *      Description: This command execute the call for adjusting fields order in the model.
 */

class AdjustFieldOrderCommand : public Command
{

public:
    AdjustFieldOrderCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string compName = getInput("Please enter the component name:");
        string fieldName = getInput("Please enter the first field name:");
        string replaceWith = getInput("Please enter the second field name:");

        string msg = _model->adjustFieldOrder(compName, fieldName, replaceWith);
        _view->display(msg);
    }
};

/* 
 *      Class: SetFieldDataCommand
 *      Description: This command execute the call for a set field data in the model, to set the parameters of the field.
 */

class SetFieldDataCommand : public Command
{

public:
    SetFieldDataCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string compName = getInput("Please enter the component name:");
        string fieldName = getInput("Please enter the field name:");
        int keepAdding = 1;
        int i = 0;
        while (keepAdding)
        {
            vector<string> param;
            string temp;
            temp = getInput("What action you want to take?\n[add, remove]");
            param.push_back(temp);
            temp = getInput("Please enter the value:");
            param.push_back(temp);
            string msg = _model->setFieldData(compName, fieldName, param);
            _view->display(msg);

            keepAdding = stoi(getInput("Keep adding values? (1=Yes, 0=No)"));
        }
    }
};

/* 
 *      Class: HelpCommand
 *      Description: When calling this command, the user will be presented with all the possible commands on the system.
 */

class HelpCommand : public Command
{

public:
    HelpCommand(IView *view, IFormModel *model, vector<string> commands) : Command(view, model)
    {
        _commands = commands;
    }

    virtual void execute()
    {

        string msg = "\n/////////////////////////////////////////////////////////////////////////////////////////\n";
        _view->display(msg);
        int i = 1;
        for (auto &command : _commands)
        {
            msg = to_string(i++) + ". " + command;
            _view->display(msg);
        }

        msg = "\n\n -------------------------------------------------------------------------\n";
        _view->display(msg);

        msg = "In order to create the form properly you should start with the 'new form' command.";
        msg += "\nAfter creating the form use the 'add component', that will use you as container for fields,";
        msg += "\nnow you can add field to you components.";
        msg += "\nFor every different set of fields you can create a new components and add more fields to them,";
        msg += "\nuse the name of field as suggested below.\n\n\n";
        _view->display(msg);

        string fields = "FreeTextField - A large free text field.";
        fields += "\nInputField - short text input";
        fields += "\nSingleChoice - a select input, that provides only one choice among the list of values.";
        fields += "\nMultiChoice - a select input, that provides multi choice choice among the list of values.";
        fields += "\nListSelect - a drop list input, that provides only one choice among the list of values.";
        _view->display(fields);

        msg = "\n/////////////////////////////////////////////////////////////////////////////////////////\n";
        _view->display(msg);
    }

private:
    vector<string> _commands;
};

/* 
 *      Class: ExitCommand
 *      Description: Exiting the program properly.
 */

class ExitCommand : public Command
{

public:
    ExitCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        _model->saveForm("last_form");
    }
};

/* 
 *      Class: OnLoadCommand
 *      Description: The first thing happening when the program starts, it loads the last point of work of the user.
 */

class OnLoadCommand : public Command
{

public:
    OnLoadCommand(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        string msg = _model->loadForm("last_form");
        if (msg == "Form was loaded successfully")
        {
            string choice = getInput("Do you want to start where you stopped last time?\n1. Yes\n2. No");
            if (choice == "1" || choice == "Yes")
            {
                _view->display(msg);
            }
            else if (choice == "2" || choice == "No")
            {
                _model->removeForm();
            }
            else
            {
                msg = "Bad argument was given, restored to where you stopped last time";
                _view->display(msg);
            }
        }
    }
};

/* 
 *      Class: ShowProgress
 *      Description: This command execute the call for showing the current progress of the model.
 */

class ShowProgress : public Command
{

public:
    ShowProgress(IView *view, IFormModel *model) : Command(view, model)
    {
    }

    virtual void execute()
    {
        _model->printModel();
    }
};