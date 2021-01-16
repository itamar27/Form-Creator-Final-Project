#pragma once

/*----------------------------------------------------------------

    InterFace : IController
    Memebers  : None
    Methods   : update()
    
    Description: To implement this interface, a update() method should be defined and implemented
                 in the way that the Controller will exectute the command.
                 This is an observer design pattern.

----------------------------------------------------------------*/

class IController
{
public:
    virtual void update() = 0;
};