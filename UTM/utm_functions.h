#ifndef UTM_utm_functions_h
#define UTM_utm_functions_h

#include <fstream>
#include "cppformat/format.h"
#include "utm_data_structures.h"
#include "utm_types.h"

namespace utm {
    void printProgramState ( utm::tape& memTape );
    
    utm::rule makeRule ( std::string );
    
    utm::tape readTapeFromFile ( std::string );
    
    void initialiseProgramFromFile ( std::ifstream& in ,
     utm::domain& domain, utm::tape& tape, utm::ruleTree& rules );
    
    void moveHead ( utm::tape& memTape, utm::rule& rule );
    
    void printRule ( utm::rule r );
}


#endif
