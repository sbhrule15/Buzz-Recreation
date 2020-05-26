//
//  Menus.cpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/24/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include "Menus.hpp"
#include <iomanip>

// Header Formatting
void Menus::header(std::string header) {
    std::cout << "\n==========" << header;
    std::cout << std::left << std::setw(100) << std::setfill('=') << "=";
    std::cout << std::endl;
}

// Login Menu
void Menus::login() {
    std::string usernameentry{};
    std::string passwordentry{};
    std::string username{"JPare"};
    std::string password{"Aida2019$"};
    bool access{false};

    do {
        header("LOGIN");
        std::cout << "\nPlease enter your username and password:\n" << std::endl;

        std::cout << "\tUsername: ";
        getline(std::cin, usernameentry);

        std::cout << "\tPassword: ";
        getline(std::cin, passwordentry);

        if (username == usernameentry && password == passwordentry) {
            std::cout << "Welcome " << usernameentry << ".\n" << std::endl;
            access = true;
        } else {
            std::cerr << "Credentials invalid. Please try again.\n\n";
            access =  false;
            }
    } while (access == false);
}

// Main Menu
int Menus::main_menu() {
    int selection{};
    std::cout << "\n==========" << std::setw(100) << std::setfill('=') << "MAIN MENU";
    std::cout << std::endl;
    std::cout << "\t1) Students" << std::endl;
    std::cout << "\t2) Teachers" << std::endl;
    std::cout << "\t3) Administration" << std::endl;
    std::cout << "\t4) Smart Scheduler" << std::endl;
    std::cout << "\t5) Quit" << std::endl;
    std::cout << "\nPlease select an option above: ";
    std::cin >> selection;
    
    return selection;
}


// STUDENT MENUS

    // Student Main Menu
    int Menus::student_main_menu() {
        int selection{};
        std::cout << "\n==========" << std::setw(100) << std::setfill('=') << "STUDENT MENU";
        std::cout << std::endl;
        std::cout << "\t1) Find Student" << std::endl;
        std::cout << "\t2) Create New Student" << std::endl;
        std::cout << "\t3) List All Students" << std::endl;
        std::cout << "\t4) Delete Student" << std::endl;
        std::cout << "\t5) Quit" << std::endl;
        std::cout << "\nPlease select an option above: ";
        std::cin >> selection;
        
        return selection;
    }


//TEACHER MENUS

    // Teacher Main Menu
    int Menus::teacher_main_menu(){
        int selection{};
        std::cout << "\n==========" << std::setw(100) << std::setfill('=') << "TEACHER MENU";
        std::cout << std::endl;
        std::cout << "\t1) Find Teacher" << std::endl;
        std::cout << "\t2) Add Class" << std::endl; // DONE
        std::cout << "\t3) List All Teachers" << std::endl;
        std::cout << "\t4) Print Teacher Schedule" << std::endl; // DONE
        std::cout << "\t5) Quit" << std::endl; // DONE
        std::cout << "\nPlease select an option above: ";
        std::cin >> selection;
        
        return selection;
    }


// ADMIN MENUS

    // Admin Main Menu
    int Menus::admin_main_menu() {
        int selection{};
        std::cout << "\n==========" << std::setw(100) << std::setfill('=') << "ADMINISTRATION MENU";
        std::cout << std::endl;
        std::cout << "\t1) Find Admin" << std::endl;
        std::cout << "\t2) Create New Admin" << std::endl;
        std::cout << "\t3) Delete Admin" << std::endl;
        std::cout << "\t4) Enrollments" << std::endl;
        std::cout << "\t5) Quit" << std::endl;
        std::cout << "\nPlease select an option above: ";
        std::cin >> selection;
        
        return selection;
    }
