//
//  utm_data_structures.h
//  UTM
//
//  Created by Benjamin Rood on 10/05/15.
//  Copyright (c) 2015 bisr. All rights reserved.
//

#ifndef UTM_utm_data_structures_h
#define UTM_utm_data_structures_h

#include <map>
#include "utm_types.h"

namespace utm {
    typedef std::map<std::pair<domain_t, domain_t>, utm::rule> ruleTree;
    
    typedef struct domain {
        size_t head_starting_position;
        domain_t machine_starting_state;
        domain_t max_values;
        domain_t max_states;
        domain(void) : head_starting_position{0}, machine_starting_state{0}, max_values{0}, max_states{0} {}
        domain(size_t startPos, domain_t startState, domain_t numValues, domain_t numStates)
        :   head_starting_position{startPos}, machine_starting_state{startState},
        max_values{numValues}, max_states{numStates}
        {}
        
    } domain;
}

#endif
