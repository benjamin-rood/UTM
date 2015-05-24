#include "utm_functions.h"

void utm::initialiseProgramFromFile
( std::ifstream& in ,
 utm::domain& domain,
 utm::tape& tape,
 utm::ruleTree& rules )
{
    if ( in ) {
        char c = 3;
        for (int i = 0; i < 4; ++i)
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        in.get(c);
        domain.max_states = (c-48);
        in.ignore(1);
        in.get(c);
        domain.max_values = (c-48);
        in.ignore(1);
        in.get(c);
        domain.head_starting_position = (c-48);
        in.ignore(1);
        in.get(c);
        domain.machine_starting_state = (c);
        for (int i = 0; i < 4; ++i)
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        in.get(c);
        while (c != '#') {
            tape.push_back(c);
            in.ignore(1);
            in.get(c);
        }
        for (int i = 0; i < 3; ++i)
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        utm::domain_t corresponding_state = '0';
        utm::domain_t corresponding_value = '0';
        utm::domain_t setting_value = '0';
        utm::domain_t head_moving = 'R';
        utm::domain_t setting_state = '0';
        
        while (in) {
            corresponding_state = in.get();
            in.get();
            corresponding_value = in.get();
            in.get();
            setting_value = in.get();
            in.get();
            head_moving = in.get();
            in.get();
            setting_state = in.get();
            in.get();
            
            utm::rule new_rule(corresponding_state, corresponding_value,
                               head_moving, setting_state, setting_value);
            rules.emplace(new_rule.identifier(), new_rule);
        }
        
    }
}

void utm::printRule( utm::rule r )
{
    fmt::print("{} {} {} {} {}\n", r.corresponding_to_head_state,
               r.corresponding_to_head_value, r.writes_head_value,
               r.does_head_move, r.sets_head_state);
}
