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
    using ruleTree = std::map<std::pair<tape_t, tape_t>, utm::rule>;
    
    
}

#endif
