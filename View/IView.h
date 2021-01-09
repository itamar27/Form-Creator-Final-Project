#pragma once
#include <string>
#include <iostream>

using namespace std;


/*----------------------------------------------------------------

    InterFace : View
    Memebers  : None
    Methods   : start()
                getOStream()
                display(string& msg)
    
    Description: The IView has start() for creating the UI for the user,
                 getOStream() to set the out put stream for the view,
                 and display() to update the view.

----------------------------------------------------------------*/

class IView
{
public:
    virtual void start() = 0;
    virtual ostream &getOStream() = 0;
    virtual void display(string& msg) = 0;
};