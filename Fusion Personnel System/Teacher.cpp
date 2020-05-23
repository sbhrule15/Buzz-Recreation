//
//  Teacher.cpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include "Teacher.hpp"

void Teacher::method () {
    std::cout << "Junk Method - Do Not Use" << std::endl;
}

void Teacher::print(std::ostream &os) const {
    os << "[Teacher: " << last_name << ", " << first_name << "\nAge: " << age << std::endl << "Department: " << department << std::endl << "Subject: " << subject << "]" << std::endl;
}
// Constructors

Teacher::Teacher(std::string department_entry, std::string subject_entry, std::string first_name_entry, std::string last_name_entry, int age_entry)
: Account(first_name_entry, last_name_entry, age_entry), department{department_entry}, subject{subject_entry}
{
    std::cout << "Creating Teacher" << std::endl;
}

