//
//  utm_types.h
//  UTM
//
//  Created by Benjamin Rood on 10/05/15.
//  Copyright (c) 2015 bisr. All rights reserved.
//

#ifndef UTM_utm_types_h
#define UTM_utm_types_h

#include "utm_rule.h"
#include <vector>

namespace utm {
    typedef std::vector<domain_t> tape; //  welllllll, until I do a custom vector type, we have no choice but to use an alias to a vector.
}

#endif
