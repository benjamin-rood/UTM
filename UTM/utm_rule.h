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
    enum headMove { L = -1, R = 1 };
    
    using domain_t = char;
    
    class rule {
    public:
        const domain_t corresponding_to_head_state;
        const domain_t corresponding_to_head_value;
        const domain_t sets_head_state;
        const domain_t does_head_move;
        const domain_t writes_head_value;
        
        rule (domain_t s, domain_t v, domain_t m, domain_t s2, domain_t v2) :
        corresponding_to_head_state{s},
        corresponding_to_head_value{v},
        does_head_move{m},
        sets_head_state{s2},
        writes_head_value{v2}
        {}
        
        rule (std::pair<domain_t, domain_t> identifier, domain_t m, domain_t s2, domain_t v2) :
        corresponding_to_head_state{identifier.first},
        corresponding_to_head_value{identifier.second},
        does_head_move{m},
        sets_head_state{s2},
        writes_head_value{v2}
        {}
        
        ~rule ( void ) = default;
        rule ( const rule& r ) = default;
        rule ( rule&& r ) = default;
        
        std::pair<domain_t, domain_t> identifier ( void ) const {
            return std::make_pair(corresponding_to_head_state, corresponding_to_head_value);
        }
        
        
        const bool operator== ( const rule& rhs )	{	return identifier() == rhs.identifier();	}
        const bool operator!= ( const rule& rhs )	{	return !operator==(rhs);	}
        
        
    };
}



#endif
