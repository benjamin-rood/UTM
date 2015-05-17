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
        domain_t    max_states;
        domain_t    max_values;
        size_t      head_starting_position;
        domain_t    machine_starting_state;
        domain(void) : head_starting_position{0}, machine_starting_state{0}, max_values{0}, max_states{0} {}
        domain(size_t startPos, domain_t startState, domain_t numValues, domain_t numStates)
        :   head_starting_position{startPos}, machine_starting_state{startState},
        max_values{numValues}, max_states{numStates}
        {}
        
    } domain;
}

#endif
