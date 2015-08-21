
#ifndef _INITIAL_CONDITIONS_H_
#define _INITIAL_CONDITIONS_H_

#include <string>

#include "../structure.H"

#include "initial_conditions.H"


class Initial_Conditions 
{

public:
    virtual int  setICparams( struct domain * theDomain ){return 0;}
    virtual int  parse_command_line_args(   struct domain * theDomain , 
                                            int argc , 
                                            char * argv [] ){return 0;}

    virtual void setup_grid( struct domain * theDomain );

private:
    virtual void initial( double * prim , double r ) = 0;
    virtual void setup_cells( struct domain * theDomain );

};

Initial_Conditions * select_initial_conditions( std::string IC_name );

#endif
