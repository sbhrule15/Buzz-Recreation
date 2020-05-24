//
//  Menus.cpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/24/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include "Menus.hpp"

// Login Menu
void Menus::login() {
    std::string usernameentry{};
    std::string passwordentry{};
    std::string username{"JPare"};
    std::string password{"Aida2019$"};
    bool access{false};

    do {
        std::cout << "====================LOGIN====================" << std::endl;
        std::cout << "\nPlease enter your username and password:\n" << std::endl;

        std::cout << "\tUsername: ";
        getline(std::cin, usernameentry);

        std::cout << "\tPassword: ";
        getline(std::cin, passwordentry);

        if (username == usernameentry && password == passwordentry) {
            std::cout << "Welcome " << usernameentry << "." << std::endl;
            access = true;
        } else {
            std::cerr << "Credentials invalid. Please try again.";
            access =  false;
            }
    } while (access == false);
}

// Main Menu
int Menus::main_menu() {
    int selection{};
    std::cout << "\n==========MAIN MENU==========\n" << std::endl;
    std::cout << "\t1) Students" << std::endl;
    std::cout << "\t2) Teachers" << std::endl;
    std::cout << "\t3) Administration" << std::endl;
    std::cout << "\t4) Enrollments" << std::endl;
    std::cout << "\t5) Quit" << std::endl;
    std::cout << "\nPlease select an option above: ";
    std::cin >> selection;
    
    return selection;
}

// Student Main Menu
int Menus::student_main_menu() {
    int selection{};
    std::cout << "\n==========STUDENT MENU==========\n" << std::endl;
    std::cout << "\t1) Find Student" << std::endl;
    std::cout << "\t2) Create New Student" << std::endl;
    std::cout << "\t3) List All Students" << std::endl;
    std::cout << "\t4) Delete Student" << std::endl;
    std::cout << "\t5) Quit" << std::endl;
    std::cout << "\nPlease select an option above: ";
    std::cin >> selection;
    
    return selection;
}

// Teach Main Menu
int Menus::teacher_main_menu(){
    int selection{};
    std::cout << "\n==========MAIN MENU==========\n" << std::endl;
    std::cout << "\t1) Find Teacher" << std::endl;
    std::cout << "\t2) Create New Teacher" << std::endl;
    std::cout << "\t3) List All Teachers" << std::endl;
    std::cout << "\t4) Delete Teacher" << std::endl;
    std::cout << "\t5) Quit" << std::endl;
    std::cout << "\nPlease select an option above: ";
    std::cin >> selection;
    
    return selection;
}

// Admin Main Menu
int Menus::admin_main_menu() {
    int selection{};
    std::cout << "\n==========MAIN MENU==========\n" << std::endl;
    std::cout << "\t1) Find Admin" << std::endl;
    std::cout << "\t2) Create New Admin" << std::endl;
    std::cout << "\t3) Delete Admin" << std::endl;
    std::cout << "\t4) Enrollments" << std::endl;
    std::cout << "\t5) Quit" << std::endl;
    std::cout << "\nPlease select an option above: ";
    std::cin >> selection;
    
    return selection;
}
