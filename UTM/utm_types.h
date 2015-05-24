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
#include "utm_rule.h"


namespace utm {
    using tape = std::list<domain_t>; //  welllllll, until I do a custom vector type, we have no choice but to use an alias to a vector.
    
    typedef struct domain {
        uint32_t    max_states;
        uint32_t    max_values;
        int      head_starting_position;
        domain_t    machine_starting_state;
        
        domain(void) : head_starting_position{0}, machine_starting_state{0}, max_values{0}, max_states{0} {}
        
        domain(int startPos, domain_t startState, uint32_t numValues, uint32_t numStates)
        :   head_starting_position{startPos}, machine_starting_state{startState},
        max_values{numValues}, max_states{numStates}
        {}
        
    } domain;
    
    typedef struct head {
        tape::iterator position;
        domain_t state;
        domain_t value;
        
        head(tape::iterator pos, domain_t state, domain_t val)
        : position{pos}, state{state}, value{val}
        {}
        
    } head;
    
}

#endif
