// cppformat Copyright (c) 2012 - 2015, Victor Zverovich
/* Rood, Benjamin, 13145989, Assignment 2, 159.331 */
/*
 Uses
 */


//#include "cppformat/format.cc"
//#include <fstream>
#include "utm_functions.h"
#include "utm_data_structures.h"
#include "utm_types.h"


int main(int argc, const char * argv[]) {
    
    fmt::print("----------------------------------------\n");
    fmt::print(" 159.331 Assignment 2 Semester 1 2015   \n");
    fmt::print(" Submitted by: Rood, Benjamin, 13145989 \n");
    fmt::print("----------------------------------------\n");
    
    utm::ruleTree activeRules;
    utm::tape activeTape;
    utm::domain activeDomain;
    
    std::string filepath = argv[1];
    
    utm::initialiseProgramFromFile(filepath, activeDomain, activeTape, activeRules);
    
    utm::tape_t machineState = activeDomain.machine_starting_state;
    
    auto head = activeTape.begin();
    const int hsp = activeDomain.head_starting_position;
    if (hsp < 0)
        for (int i = 0 ; i != hsp ; --i, --head) {}
    else
        for (int i = 0 ; i != hsp ; ++i, ++head) {}
    
    activeTape.emplace_front('B');
    activeTape.emplace_back('B');
    
    fmt::print("{}-state {}-symbol Turing Program\n\n", activeDomain.max_states, activeDomain.max_values);
    
    fmt::print("Rules:\n");
    
    utm::tape_t prevState = '?';
    for (auto& r : activeRules) {
        if (r.second.corresponding_to_head_state != prevState) {
            fmt::print("{:>2}:\t", r.second.corresponding_to_head_state);
            prevState = r.second.corresponding_to_head_state;
        }
        else fmt::print("\t");
        fmt::print("{} {} {} {}\n",
                   r.second.corresponding_to_head_value, r.second.writes_head_value,
                   r.second.does_head_move, r.second.sets_head_state);
    }
    fmt::print("\n\n");
    
    int pc = 0;
    while (machineState != 'H') {
        utm::printProgramState(activeTape, machineState, head, pc++);
        utm::doStep(machineState, head, activeRules, activeTape);
        fmt::print("\n");
    }
    utm::printProgramState(activeTape, machineState, head, pc++);
    fmt::print("\n");
    fmt::print("Program Halted\n");
    
    return 0;
}
