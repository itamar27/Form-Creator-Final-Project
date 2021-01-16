#pragma once
#include <vector>
#include <string>

using namespace std;

/*----------------------------------------------------------------

    Class     : Command
    Methods   : execute()
    
    Description: For this design pattern we implement each command with only one method,
                 exectute() which takes the data received from the input in the view and
                 making it ready for the model execution and then calling the model to
                 execute it.

----------------------------------------------------------------*/

class Command
{
public:
    virtual void execute(std::vector<std::string> param) = 0;
};


/* 
 *      Class: NewFormCommand
 *      Description: This command execute the call for a new form in the model.
 */

class NewFormCommand: public Command {
private:
    IView* _view;
public:
    NewFormCommand(IView* view) {
        _view = view;
    }
    virtual void execute(vector<string> param) {
        string msg = "You got to NewFormCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: LoadFormCommand
 *      Description: This command execute the call for a load form in the model.
 */

class LoadFormCommand: public Command {
private:
    IView* _view;
public:
    LoadFormCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to LoadFormCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: SaveFormCommand
 *      Description: This command execute the call for a save form in the model.
 */

class SaveFormCommand: public Command {
private:
    IView* _view;
public:
    SaveFormCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to SaveFormCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: ChangeFormNameCommand
 *      Description: This command execute the call for a change form name in the model.
 */

class ChangeFormNameCommand: public Command {
private:
    IView* _view;
public:
    ChangeFormNameCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to ChangeFormNameCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: AddComponentCommand
 *      Description: This command execute the call for a add component in the model.
 */

class AddComponentCommand: public Command {
private:
    IView* _view;
public:
    AddComponentCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to AddComponentCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: RemoveComponentCommand
 *      Description: This command execute the call for a remove component in the model.
 */

class RemoveComponentCommand: public Command {
private:
    IView* _view;
public:
    RemoveComponentCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to RemoveComponentCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: ChangeComponentNameCommand
 *      Description: This command execute the call for a change component name in the model.
 */

class ChangeComponentNameCommand: public Command {
private:
    IView* _view;
public:
    ChangeComponentNameCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to ChangeComponentNameCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: AdjustComponentOrderCommand
 *      Description: This command execute the call for a adjust components order in the model.
 */

class AdjustComponentOrderCommand: public Command {
private:
    IView* _view;
public:
    AdjustComponentOrderCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to AdjustComponentOrderCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: AddFieldCommand
 *      Description: This command execute the call for a add field in the model.
 */

class AddFieldCommand: public Command {
private:
    IView* _view;
public:
    AddFieldCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to AddFieldCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: RemoveFieldCommand
 *      Description: This command execute the call for a remove field in the model.
 */

class RemoveFieldCommand: public Command {
private:
    IView* _view;
public:
    RemoveFieldCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to RemoveFieldCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: AdjustFieldOrderCommand
 *      Description: This command execute the call for a adjust fields order in the model.
 */

class AdjustFieldOrderCommand: public Command {
private:
    IView* _view;
public:
    AdjustFieldOrderCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to AdjustFieldOrderCommand";
        _view->display(msg);
    }
};


/* 
 *      Class: SetFieldDataCommand
 *      Description: This command execute the call for a set field data in the model.
 */

class SetFieldDataCommand: public Command {
private:
    IView* _view;
public:
    SetFieldDataCommand(IView* view) {
        _view = view;
    }

    virtual void execute(vector<string> param) {
        string msg = "You got to SetFieldDataCommand";
        _view->display(msg);
    }
};