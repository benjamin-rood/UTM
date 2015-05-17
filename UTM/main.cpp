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
    if ( in ) {
        char c = 3;
        for (int i = 0; i < 4; ++i)
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        in.get(c);
        activeDomain.max_states = (c-48);
        fmt::print("{}", activeDomain.max_states);
        in.ignore(1);
        in.get(c);
        activeDomain.max_values = (c-48);
        fmt::print(" {}", activeDomain.max_values);
        in.ignore(1);
        in.get(c);
        activeDomain.head_starting_position = (c-48);
        fmt::print(" {}", activeDomain.head_starting_position);
        in.ignore(1);
        in.get(c);
        activeDomain.machine_starting_state = (c-48);
        fmt::print(" {}", activeDomain.machine_starting_state);
        for (int i = 0; i < 4; ++i)
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        fmt::print("\n");
        in.get(c);
        while (c != '#') {
            activeTape.push_back(c-48);
            fmt::print("{} ", *std::end(activeTape).operator--());
            in.ignore(1);
            in.get(c);
        }
        for (int i = 0; i < 3; ++i)
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        in.get(c);
        utm::domain_t a = static_cast<utm::domain_t>(c-48);
        fmt::print("\n{}", a);
        in.close();
    }
    
    
    
//    auto head = std::begin(activeTape);
//    for (auto i = 0; i < activeDomain.head_starting_position ; ++head) {}
    
    
    
    
    return 0;
}
