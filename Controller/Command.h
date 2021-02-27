#pragma once
#include <vector>
#include <string>

#include "../View/IView.h"
#include "../Model/IFormModel.h"

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

protected:
    IView* _view;
    IFormModel* _model;
};


/* 
 *      Class: NewFormCommand
 *      Description: This command execute the call for a new form in the model.
 */

class NewFormCommand: public Command {
private:
    IView* _view;
public:
    NewFormCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }
    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() < 1) {
            msg = "To create a new form please enter a name only";
            _view->display(msg);
        }

        string toSend = "";
        for(auto it = param.begin(); it != param.end(); it++) {
            toSend += (*it);
        }

        msg = _model->newForm(toSend);
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
    LoadFormCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() < 1) {
            msg = "To load a form please enter the filename to load from";
            _view->display(msg);
        }

        string toSend = "";
        for(auto it = param.begin(); it != param.end(); it++) {
            toSend += (*it);
        }

        msg = _model->loadForm(toSend);
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
    SaveFormCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() < 1) {
            msg = "To save a form please enter the file name you want to save it to";
            _view->display(msg);
        }
        string toSend = "";
        for(auto it = param.begin(); it != param.end(); it++) {
            toSend += (*it);
        }

        msg = _model->saveForm(toSend);
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
    ChangeFormNameCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() < 1) {
            msg = "To change a form name enter the new name";
            _view->display(msg);
        }

        string toSend = "";
        for(auto it = param.begin(); it != param.end(); it++) {
            toSend += (*it);
        }

        msg = _model->changeFormName(toSend);
        _view->display(msg);
    }
};


/* 
 *      Class: GenerateFormCommand
 *      Description: This command execute the call for a change form name in the model.
 */

class GenerateFormCommand: public Command {
private:
    IView* _view;
public:
    GenerateFormCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        msg = _model->generateForm();
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
    AddComponentCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() < 1) {
            msg = "To add a new component enter the new component's name";
            _view->display(msg);
        }

        string toSend = "";
        for(auto it = param.begin(); it != param.end(); it++) {
            toSend += (*it);
        }

        msg = _model->addComponent(toSend);
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
    RemoveComponentCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() != 1) {
            msg = "To remove a component enter the component's name";
            _view->display(msg);
        }

        msg = _model->removeComponent(param[0]);
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
    ChangeComponentNameCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() != 2) {
            msg = "To change component's name enter the current name and then the new one";
            _view->display(msg);
        }

        msg = _model->changeComponentName(param[0], param[1]);
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
    AdjustComponentOrderCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() != 2) {
            msg = "To change components order enter the first and second components you want to switch";
            _view->display(msg);
        }

        msg = _model->adjustComponentOrder(param[0], param[1]);
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
    AddFieldCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() != 3) {
            msg = "To add a field please enter the component's name, new field name and a type";
            _view->display(msg);
        }

        msg = _model->addField(param[0], param[1], param[2]);
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
    RemoveFieldCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() != 2) {
            msg = "To remove a field please enter the component's name and the field's name";
            _view->display(msg);
        }

        msg = _model->removeField(param[0], param[1]);
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
    AdjustFieldOrderCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() != 3) {
            msg = "To adjust the fields order please enter the component's name and the two fields you want to switch";
            _view->display(msg);
        }

        msg = _model->adjustFieldOrder(param[0], param[1], param[2]);
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
    SetFieldDataCommand(IView* view, IFormModel* model) {
        _view = view;
        _model = model;
    }

    virtual void execute(vector<string> param) {
        string msg;
        if(param.size() < 3) {
            msg = "To change field data, enter the component's name, the field's name and values to change";
            _view->display(msg);
        }

        vector<string> toSend; 
        for(int i = 2; i < param.size(); i++)
            toSend.push_back(param[i]);

        msg = _model->setFieldData(param[0], param[1], toSend);
        _view->display(msg);
    }
};