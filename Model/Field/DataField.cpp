#include "./Field.h"

using namespace std;

/*----------------------------------------------------------------

    InterFace : DataField
    Memebers  : None
    Methods   : 
                changeParameters()
    
    Description: DataField -------------//----------- 

----------------------------------------------------------------*/

class DataField : public Field
{
public:
    DataField(string headLine) : Field(headLine) {}
    ~DataField() {}

public:
    virtual void changeParameters(const vector<string>& params)
    {
        // Decide on implementation --//--
    }
};