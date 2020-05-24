//
//  Account.cpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include "Account.hpp"

Account::Account(std::string first, std::string last, int age_of)
: first_name(first), last_name(last), age(age_of) {
    std::cout << "Creating Account" << std::endl;
}

void Account::print(std::ostream &os) const {
    os << "[Account: " << last_name << ", " << first_name << std::endl << "Age: " << age << std::endl;
}

