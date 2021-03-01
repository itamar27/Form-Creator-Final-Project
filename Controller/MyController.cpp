#include "MyController.h"

/*
 *      Metod : Mycontroller (Constructor)
 *      Description: To intiazlize a MyController instance we must first use a view
 *                   to let our user control eveything, the user will chose his in and out streaming channels
 *                   and will use the view start method to work with our Controller and model parts.
 */

MyController::MyController(IView *view)
{
    if (view != nullptr)
        _view = view;

    _model = new HtmlFormModel();

    _commands["new form"] = new NewFormCommand(_view, _model);
    _commands["load form"] = new LoadFormCommand(_view, _model);
    _commands["save form"] = new SaveFormCommand(_view, _model);
    _commands["change form name"] = new ChangeFormNameCommand(_view, _model);
    _commands["generate form"] = new GenerateFormCommand(_view, _model);
    _commands["add component"] = new AddComponentCommand(_view, _model);
    _commands["remove component"] = new RemoveComponentCommand(_view, _model);
    _commands["change component name"] = new ChangeComponentNameCommand(_view, _model);
    _commands["adjust component order"] = new AdjustComponentOrderCommand(_view, _model);
    _commands["add field"] = new AddFieldCommand(_view, _model);
    _commands["remove field"] = new RemoveFieldCommand(_view, _model);
    _commands["adjust field order"] = new AdjustFieldOrderCommand(_view, _model);
    _commands["set field data"] = new SetFieldDataCommand(_view, _model);
    _commands["exit"] = new ExitCommand(_view, _model);

    vector<string> keys;
    for (auto it = _commands.begin(); it != _commands.end(); it++)
        keys.push_back(it->first);
    _commands["help"] = new HelpCommand(_view, _model, keys);

    string welcomeMessage = "/////////////////////////////////////////////////////////////////////////////////////////\n|\t\t\tWelcome to Form - Creator!\t\t\t\t\t|\n|\t\t\tLet's start creating Forms!\t\t\t\t\t|\n/////////////////////////////////////////////////////////////////////////////////////////";
    _view->display(welcomeMessage);

    Command *onLoad = new OnLoadCommand(_view, _model);
    onLoad->execute();
    delete onLoad;
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