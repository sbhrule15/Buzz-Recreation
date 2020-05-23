//
//  main.cpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include "Account.hpp"
#include "Teacher.hpp"
#include "Admin.hpp"
#include "Teacher.hpp"

// In File



// Out file





int main () {
    
    std::unique_ptr<Account> JP = std::make_unique<Teacher>("Electives", "Music", "Joshua", "Pare", 24);
    std::unique_ptr<Account> JY = std::make_unique<Teacher>("STEM", "Science", "Justine", "Yoon", 30);
    std::unique_ptr<Account> CD = std::make_unique<Teacher>("STEM", "Math", "Costanza", "Davis", 23);
    std::unique_ptr<Account> DG = std::make_unique<Teacher>("Humanities", "English", "Danielle", "Greenburg", 32);
    
    std::cout << *JP << std::endl;
    std::cout << *JY << std::endl;
    std::cout << *CD << std::endl;
    std::cout << *DG << std::endl;
    
    return 0;
}
