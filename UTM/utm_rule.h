//
//  rule.h
//  UTM
//
//  Created by Benjamin Rood on 10/05/15.
//  Copyright (c) 2015 bisr. All rights reserved.
//

#ifndef UTM_utm_rule_h
#define UTM_utm_rule_h

#include <iostream>
#include <utility>

namespace utm {
    enum headMove { L = 0, R = 1 };
    
    using tape_t = char;
    
    class rule {
    public:
        const tape_t corresponding_to_head_state;
        const tape_t corresponding_to_head_value;
        const tape_t sets_head_state;
        const tape_t does_head_move;
        const tape_t writes_head_value;
        
        rule (tape_t s, tape_t v, tape_t m, tape_t s2, tape_t v2) :
        corresponding_to_head_state{s},
        corresponding_to_head_value{v},
        does_head_move{m},
        sets_head_state{s2},
        writes_head_value{v2}
        {}
        
        rule (std::pair<tape_t, tape_t> identifier, tape_t m, tape_t s2, tape_t v2) :
        corresponding_to_head_state{identifier.first},
        corresponding_to_head_value{identifier.second},
        does_head_move{m},
        sets_head_state{s2},
        writes_head_value{v2}
        {}
        
        ~rule ( void ) = default;
        rule ( const rule& r ) = default;
        rule ( rule&& r ) = default;
        
        std::pair<tape_t, tape_t> identifier ( void ) const {
            return std::make_pair(corresponding_to_head_state, corresponding_to_head_value);
        }
        
        
        const bool operator== ( const rule& rhs )	{	return identifier() == rhs.identifier();	}
        const bool operator!= ( const rule& rhs )	{	return !operator==(rhs);	}
        
        
    };
}



#endif
