#pragma once
#include <string>
#include <map>

#include "IController.h"
#include "Command.h"

#include "../View/IView.h"
#include "../Model/IFormModel.h"

using namespace std;

/*----------------------------------------------------------------

    Class     : MyController
    Memebers  : map<string, Command*> _commands
                IFormModel* _model
                IView* _view

    Methods   : update()
                get()
                update()
    
    Description: This class is implementing the IController interface.
                 The class holds a map which used to get a Command class by name: string.
                 The observer design pattern here uses the Model: IFormModel as an observeable.

----------------------------------------------------------------*/

class MyController : public IController
{

public:
    MyController(IView* view);
    ~MyController();

public:
    virtual void update();
    virtual Command *get(const std::string &command);
    virtual void update(IFormModel &model);

private:
    map<string, Command*> _commands;
    IFormModel* _model;
    IView* _view;
};