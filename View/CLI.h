#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "IView.h"
#include "../Controller/MyController.h"

using namespace std;

/*----------------------------------------------------------------

    Class     : CLI

    Members   : ostream& _out
                istream& _in

    Methods   : start()
                getOStream()
                display()
                parseInput(string &str, MyController *con)
                display(string &msg)
    
    Description: A class implementing the IView interface through CLI (=Command Line Interface),
                 it extendes the IView with parseInput() method in order to parse the CLI input and send it to the Controller.

----------------------------------------------------------------*/

class CLI : public IView
{

public:
    CLI() : _out(std::cout), _in(cin){};
    CLI(ostream &out, istream &in) : _out(out), _in(in) {}
    ~CLI() {}

public:
    virtual void start();
    virtual ostream &getOStream();
    virtual vector<string> parseInput(string &str, MyController *con);
    virtual void display(string &msg);

private:
    ostream &_out;
    istream &_in;
};