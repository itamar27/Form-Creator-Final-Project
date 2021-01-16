#pragma once
#include <vector>
#include <string>

using namespace std;

/*----------------------------------------------------------------

    Class     : Command
    Memebers  : 

    Methods   : 
    
    Description: 

----------------------------------------------------------------*/

class Command
{
public:
    virtual void execute(std::vector<std::string> param) = 0;
};