// shell only implementation of a Universal Turing Machine under conditions per assignment for 159.331

#include "cppformat/format.cc"
#include <fstream>
#include "utm_functions.h"
#include "utm_data_structures.h"
#include "utm_types.h"


int main(int argc, const char * argv[]) {
    
    utm::ruleTree activeRules;
    utm::tape activeTape;
    utm::domain activeDomain;
    
    std::ifstream in( argv[1], std::ios::in | std::ios::binary );
    
    utm::initialiseProgramFromFile(in, activeDomain, activeTape, activeRules);
    
    utm::tape_t machineState = activeDomain.machine_starting_state;
    
    auto head = activeTape.begin();
    const int hsp = activeDomain.head_starting_position;
    if (hsp < 0)
        for (int i = 0 ; i != hsp ; --i, --head) {}
    else
        for (int i = 0 ; i != hsp ; ++i, ++head) {}
    
    activeTape.emplace_front('B');
    activeTape.emplace_back('B');
    
    int pc = 0;
    while (machineState != 'H') {
        utm::printProgramState(activeTape, machineState, head, pc++);
        utm::doStep(machineState, head, activeRules, activeTape);
        fmt::print("\n");
    }
    utm::printProgramState(activeTape, machineState, head, pc++);
    fmt::print("\n");
    fmt::print("Program Halted\n");
    
    
    in.close();
    
    return 0;
}
