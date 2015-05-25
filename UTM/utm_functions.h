#ifndef UTM_utm_functions_h
#define UTM_utm_functions_h

#include <fstream>
#include "cppformat/format.h"
#include "utm_data_structures.h"
#include "utm_types.h"

namespace utm {
    void printProgramState ( utm::tape& tape, utm::tape_t& state, const utm::tape::iterator& head, int programCount );
    
    void initialiseProgramFromFile ( std::ifstream& in ,
    domain& domain, utm::tape& tape, utm::ruleTree& rules );
    
    rule& getRule ( utm::tape_t& state, const utm::tape::iterator& head, utm::ruleTree& rules );
    void doStep ( utm::tape_t& state, utm::tape::iterator& head, utm::ruleTree rules, utm::tape& tape );
    void moveHead ( utm::tape::iterator& head, utm::rule& rule, utm::tape& tape );
    
    void printRule ( const utm::rule& r );
    
    void printTape ( const utm::tape& tape, const utm::tape::iterator& head );
}


#endif
