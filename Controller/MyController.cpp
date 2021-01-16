#include "MyController.h"

/*
 *      Metod : Mycontroller (Constructor)
 *      Description: To intiazlize a MyController instance we must first use a view (some program interface)
 *                   to let our user control eveything, the user will chose his in and out streaming channels
 *                   and will use the view start method to work with our Controller and model parts.
 */

MyController::MyController(IView *view)
{
    if (view != nullptr)
        _view = view;

    // _model = new FormModel();
    // _model->Attach(*this);

    _commands["new form"] = new NewFormCommand(_view);
    _commands["load form"] = new LoadFormCommand(_view);
    _commands["save form"] = new SaveFormCommand(_view);
    _commands["change form name"] = new ChangeFormNameCommand(_view);
    _commands["add component"] = new AddComponentCommand(_view);
    _commands["remove component"] = new RemoveComponentCommand(_view);
    _commands["change component name"] = new ChangeComponentNameCommand(_view);
    _commands["adjust component order"] = new AdjustComponentOrderCommand(_view);
    _commands["add field"] = new AddFieldCommand(_view);
    _commands["remove field"] = new RemoveFieldCommand(_view);
    _commands["adjust field order"] = new AdjustFieldOrderCommand(_view);
    _commands["set field data"] = new SetFieldDataCommand(_view);


    // std::ifstream loadFile(data_file, std::ios::in | std::ios::binary);
    // if (loadFile.is_open())
    //     _model->loadAllMazes(&loadFile);
    // loadFile.close();
    string welcomeMessage = "/////////////////////////////////////////////////////////////////////////////////////////\n|\t\t\tWelcome to Form - Creator!\t\t\t\t\t|\n|\t\t\tLet's start creating Forms!\t\t\t\t\t|\n/////////////////////////////////////////////////////////////////////////////////////////";
    _view->display(welcomeMessage);
}

/* 
 *      Method: update
 *      Description: This method is part of the observer pattern to update the controller.
 *                   The controller is the observer and needs to decide what to do on coming updates from the observable (the model)
 */

void MyController::update(IFormModel &model)
{
    // std::string tmp = model.getState();
    string tmp = "No model yet";
    _view->display(tmp);
}

/* 
 *      Method: get
 *      Description: This method is part of the MVC and build the connection between the interface(view)
 *                   and the command that is part of the controller. 
 */

Command *MyController::get(const std::string &command)
{
    auto it = _commands.find(command);
    if (it == _commands.end())
        return nullptr;

    return it->second;
}

/* 
 *      Method: Destructor
 *      Description: iterate throgh all commands that were allocated in MyController constructor
 */

MyController::~MyController()
{
    for (auto it = _commands.begin(); it != _commands.end(); ++it)
    {
        delete it->second;
    }

    delete _model;
}