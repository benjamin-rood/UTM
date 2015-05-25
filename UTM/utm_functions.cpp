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
        utm::tape_t corresponding_state = '0';
        utm::tape_t corresponding_value = '0';
        utm::tape_t setting_value = '0';
        utm::tape_t head_moving = 'R';
        utm::tape_t setting_state = '0';
        
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


utm::rule& utm::getRule ( utm::tape_t& state, const utm::tape::iterator& head, utm::ruleTree& rules )
{
    auto search = rules.find(std::make_pair(state, *head));
    return search->second;
}

void utm::printRule( const utm::rule& r )
{
    fmt::print("if:\t\tstate = {} && head = {}\n"
               "then:\tset head to {} && move head {} "
               "&& set state to {}\n"
               , r.corresponding_to_head_state,
               r.corresponding_to_head_value, r.writes_head_value,
               r.does_head_move, r.sets_head_state);
}

void utm::printProgramState ( utm::tape& tape, utm::tape_t& state, const utm::tape::iterator& head, int programCount )
{
    fmt::print("{:<3}:({})", programCount, state);
    utm::printTape(tape, head);
}

void utm::printTape ( const utm::tape& tape, const utm::tape::iterator& head )
{
    for (auto it = std::begin(tape); it != std::end(tape); it++) {
        if (it == head)
            fmt::print(">");
        else fmt::print(" ");
        fmt::print("{}", *it);
    }
}

void utm::moveHead ( utm::tape::iterator& head, utm::rule& rule, utm::tape& tape )
{
    if (rule.does_head_move == 'L') {
        head--;
        if (head == std::begin(tape))
            tape.emplace_front('B');
    }
    else if (rule.does_head_move == 'R') {
        head++;
        if (std::next(head) == std::end(tape))
            tape.emplace_back('B');
    }
    else {
        
    }
}

void utm::doStep ( utm::tape_t& state, utm::tape::iterator& head, utm::ruleTree rules, utm::tape& tape )
{
    auto rule = getRule(state, head, rules);
//    fmt::print("\n");
//    utm::printRule(rule);
//    fmt::print("writing {} at head\n", rule.writes_head_value);
    *head = rule.writes_head_value;
    utm::moveHead(head, rule, tape);
//    fmt::print("head moves {}\n", rule.does_head_move);
    state = rule.sets_head_state;
//    fmt::print("set state to {}\n", state);
}
