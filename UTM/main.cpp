
/* Rood, Benjamin, 13145989, Assignment 2, 159.331 */
/*
 
 ------------------------------------------------------
   A virtual Universal Turing Machine written in C++
 ------------------------------------------------------
 
 The "infinite" Tape is implemented as a double-ended linked-list, 
 initialised from the second (non-comment) line in the input file.
 
 Rules are dynamically-generated objects, which are added to a 
 Rule Tree (an STL (ordered) map (Red-Black Tree)) which can be searched 
 quickly to determine each corresponding step of the program.
 
 The Head is an bi-directional iterator which moves one step at a time 
 through the Tape-as-linked-list.
 
 Program Counter and Machine State are variables local to main.
 
 After the domain is defined, the initial state of the tape is loaded, 
 and each of the program rules has been added to the Rule Tree, the 
 program steps begin. Depending on the position of the Head and the
 Machine State, the rule identified by these two parameters is found
 in the Rule Tree. Each Rule object holds the next instruction block 
 to write a value on the tape, move the head left or right, and set
 the machine state. The program counter increments for each successive
 completed instruction based on the appropriate rule.
 
 When the machine state becomes 'H', the program halts.
 
 ------------------------------------------------------
 
 uses namespace utm:
 -  utm::tape_t is aliased to char.
 -  utm::tape is aliased to an double-ended STL list container of type 
    char.
 -  utm::head is a bi-directional utm::tape::iterator.
 -  utm::domain is a struct of the program domain parameters.
 –  utm::rule is a class constructed by the parameters given for each 
    line of the input file defining a rule.
 –  utm::ruleTree is aliased to an STL map container with key,value pair
    of <std::pair<corresponding state, corresponding value>, utm::rule>
 
 –––––––––––––––––––––––––––––––––––––------------------
 
 dependencies:
 -  cppformat (a portable low-cost alternative to output streams and printf)
 
 Copyright (c) 2012 - 2015, Victor Zverovich
 
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 --------------------------------------------------------
 
*/

#include <iostream>
#include "utm_functions.h"
#include "utm_types.h"


int main(int argc, const char * argv[]) {
    
    fmt::print("----------------------------------------\n");
    fmt::print(" 159.331 Assignment 2 Semester 1 2015   \n");
    fmt::print(" Submitted by: Rood, Benjamin, 13145989 \n");
    fmt::print("----------------------------------------\n");
    
    utm::ruleTree activeRules;
    utm::tape activeTape;
    utm::domain activeDomain;
    
    if (argc < 2) {
        std::cerr << "Error: Missing input file argument.\n";
        exit(EXIT_SUCCESS);
    }
    if (argc > 2) {
        std::cerr << "Error: Too many arguments.\n";
        exit(EXIT_SUCCESS);
    }
    
    //  initial setup:
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
    //  end setup
    
    //  Print domain:
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
    
    //  Turing Machine program steps begin:
    int pc = 0;
    while (machineState != 'H') {
        utm::printProgramState(activeTape, machineState, head, pc++);
        utm::doStep(machineState, head, activeRules, activeTape);
        fmt::print("\n");
    }
    utm::printProgramState(activeTape, machineState, head, pc++);
    fmt::print("\n");
    fmt::print("Program Halted\n");
    //  end TM.
    return 0;
}
