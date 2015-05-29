//
//  utm_types.h
//  UTM
//
//  Created by Benjamin Rood on 10/05/15.
//  Copyright (c) 2015 bisr. All rights reserved.
//

#ifndef UTM_utm_types_h
#define UTM_utm_types_h

#include <list>
#include <map>
#include "utm_rule.h"


namespace utm {
    
    using tape = std::list<tape_t>;
    
    using ruleTree = std::map<std::pair<tape_t, tape_t>, utm::rule>;
    
    typedef struct domain {
        uint32_t    max_states;
        uint32_t    max_values;
        int      head_starting_position;
        tape_t    machine_starting_state;
        
        domain(void) : head_starting_position{0}, machine_starting_state{0}, max_values{0}, max_states{0} {}
        
        domain(int startPos, tape_t startState, uint32_t numValues, uint32_t numStates)
        :   head_starting_position{startPos}, machine_starting_state{startState},
        max_values{numValues}, max_states{numStates}
        {}
        
    } domain;
    
}

#endif
