//
//  Scheduler.hpp
//  Scheduler
//
//  Created by Joshua Pare on 5/25/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#ifndef Scheduler_hpp
#define Scheduler_hpp

#include <stdio.h>
#include <iostream>
#include <array>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

class Schedule {
public:
    
// ATTRIBUTES
    std::string firstname {"First"};
    std::string lastname {"Last"};
    std::array<std::array<std::string,11>, 5> time_table {};
    std::string schedule_file {"None.txt"};
    
// METHODS
    
    void element_access (int l, std::string time);
    void print_schedule ();
    void get_schedule();
    void load_schedule ();
    void add_class ();
    int time_conversion(std::string time);
    int day_conversion(std::string day);
    
// Constructor
    
    Schedule(std::string first, std::string last)
    : schedule_file(first+last+"Schedule.txt"), firstname(first), lastname(last), time_table(
    {{
        {{"OPEN (7:30)", "OPEN (8:30)", "OPEN (9:30)", "OPEN (10:30)", "OPEN (11:30)", "LUNCH HOUR", "OPEN (1:30)", "OPEN (2:30)", "OPEN (3:30)", "OPEN (4:30)", "OPEN (5:30)"}},
        {{"OPEN (7:30)", "OPEN (8:30)", "OPEN (9:30)", "OPEN (10:30)", "OPEN (11:30)", "LUNCH HOUR", "OPEN (1:30)", "OPEN (2:30)", "OPEN (3:30)", "OPEN (4:30)", "OPEN (5:30)"}},
        {{"OPEN (7:30)", "OPEN (8:30)", "OPEN (9:30)", "OPEN (10:30)", "OPEN (11:30)", "LUNCH HOUR", "OPEN (1:30)", "OPEN (2:30)", "OPEN (3:30)", "OPEN (4:30)", "OPEN (5:30)"}},
        {{"OPEN (7:30)", "OPEN (8:30)", "OPEN (9:30)", "OPEN (10:30)", "OPEN (11:30)", "LUNCH HOUR", "OPEN (1:30)", "OPEN (2:30)", "OPEN (3:30)", "OPEN (4:30)", "OPEN (5:30)"}},
        {{"OPEN (7:30)", "OPEN (8:30)", "OPEN (9:30)", "OPEN (10:30)", "OPEN (11:30)", "LUNCH HOUR", "OPEN (1:30)", "OPEN (2:30)", "OPEN (3:30)", "OPEN (4:30)", "OPEN (5:30)"}},
    }}
                                                   ) {}
    
    };







#endif /* Scheduler_hpp */
