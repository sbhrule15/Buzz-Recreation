//
//  Schedule.hpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/25/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#ifndef Schedule_hpp
#define Schedule_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include <array>
#include <string>



class Schedule {
public:
    
// Single Class Slot
    
//    std::map<int,std::string> slot {"0", "OPEN"};
 
// Array of Each Day (starts at 7:30, goes to 6:30)
    
//    std::array<std::string,11> timeslots = {
//        "OPEN", "OPEN", "OPEN", "OPEN", "OPEN", "LUNCH HOUR", "OPEN", "OPEN", "OPEN", "OPEN", "OPEN"};
//
//    std::array<std::string, 5> week {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    
    std::array<std::array<std::string,11>, 5> time_table =
    {{"OPEN", "OPEN", "OPEN", "OPEN", "OPEN", "LUNCH HOUR", "OPEN", "OPEN", "OPEN", "OPEN", "OPEN"}};
    
    
    
    
// Each Day Of The Week
    
    
    
    
};



#endif /* Schedule_hpp */
