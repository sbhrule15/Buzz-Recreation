//
//  Menus.hpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/24/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#ifndef Menus_hpp
#define Menus_hpp

#include <stdio.h>
#include <iostream>
#include <string>


class Menus {
public:
    
    int existence = 1;
    
    // Login Menu
    void login();
    
    // Main Menu
    int main_menu();
    
    // Student Menus
    int student_main_menu();
    
    // Teach Menus
    int teacher_main_menu();
    
    // Administration Menus
    int admin_main_menu ();
    
};

#endif /* Menus_hpp */
