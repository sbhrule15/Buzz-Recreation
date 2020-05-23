//
//  Student.cpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include "Student.hpp"

void Student::method () {
    std::cout << "Junk Method - Do Not Use" << std::endl;
}

Student::Student(int grade_level_entry, std::string first_name_entry, std::string last_name_entry, int age_entry)
: Account(first_name_entry, last_name_entry, age_entry), grade_level{grade_level_entry}
{
}

void Student::print(std::ostream &os) const {
    os << "[Student: " << last_name << ", " << first_name << "\nAge: " << age << std::endl << "Grade Level: " << grade_level << "]" << std::endl; }
