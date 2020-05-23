//
//  Admin.cpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include "Admin.hpp"


//Constructor
Admin::Admin(std::string title_entry, std::string first_name_entry, std::string last_name_entry, int age_entry)
: Account(first_name_entry, last_name_entry, age_entry), title{title_entry}
{}

void Admin::method () {
    std::cout << "Junk Method - Do Not Use" << std::endl;
}

void Admin::print(std::ostream &os) const {
os << "[Admin: " << last_name << ", " << first_name << "\nAge: " << age << std::endl << "Title: " <<  title << "]" << std::endl;
}
