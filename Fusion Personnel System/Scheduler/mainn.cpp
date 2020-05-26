//
//  mainn.cpp
//  Scheduler
//
//  Created by Joshua Pare on 5/25/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include <stdio.h>
#include "Scheduler.hpp"
#include <sstream>
#include <memory>
#include <vector>


int main() {
   //Blank Function object for function use
    Schedule f ("Function", "Function");
   //Schedule Access
  

    int selection{0};
    
    while (selection !=3) {
        std::cout << "What would you like to do?\n\n" << std::endl;
        std::cout << "\t1) Get Schedule\n\t2) Add Class\n\t3) Quit\n" << std::endl;
        std::cin >> selection;

        if (selection == 1)
            f.print_schedule();
        else if (selection == 2)
            f.add_class();
        else {
            std::cout << "Goodbye";
            return 0;
        }
    }
    
    
    
    
    return 0;
}
