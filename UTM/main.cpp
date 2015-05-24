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
    
//    fmt::print("RULES:\n");
//    for (auto& r : activeRules)
//        utm::printRule(r.second);
    
    auto start_pos = activeTape.begin();
    const int hsp = activeDomain.head_starting_position;
    if (hsp < 0)
        for (int i = 0 ; i != hsp ; --i, --start_pos) {}
    else
        for (int i = 0 ; i != hsp ; ++i, ++start_pos) {}
    
    utm::head head(start_pos, activeDomain.machine_starting_state, *start_pos);
    
    for (; head.position != activeTape.end(); head.position++)
    {
        head.value = *head.position;
        fmt::print("{} ", head.value);
    }
    fmt::print("\n");
    
    for (auto& t : activeTape)
        fmt::print("{} ", t);
    fmt::print("\n");
    
    in.close();
    
    return 0;
}
