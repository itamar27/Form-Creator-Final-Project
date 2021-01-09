#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "IView.h"
//#include "../Controller/Controller.h"

using namespace std;

/*----------------------------------------------------------------

    Class     : CLI
    Memebers  : ostram& _out
                istream& _in
    Methods   : start()
                getOStream()
                display()
                parseInput(string& str, MyController* con)
    
    Description: A class implementing the IView interface through CLI (=Command Line Interface) 
                 The addition of the parseInput() method is to parse the CLI input and send it to the Controller.

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
    virtual vector<string> parseInput(string& str, MyController* con);

private:
    ostream &_out;
    istream &_in;
};