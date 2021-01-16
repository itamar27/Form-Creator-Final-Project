#pragma once

/*----------------------------------------------------------------

    InterFace : IController
    Memebers  : None
    Methods   : update()
    
    Description: To implement this interface, a update() method should be defined and implemented
                 in the way that the Controller will exectute the command.

----------------------------------------------------------------*/

class IController
{
public:
    virtual void update() = 0;
};