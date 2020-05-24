//
//  Account.hpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <memory>
#include <iostream>
#include <string>
#include "I-Printable.hpp"

class Account : public I_Printable {

protected:
    
    std::string first_name {"First"};
    std::string last_name {"Last"};
    int age {1};
    
public:
    // Constructor/Destructor
    
    Account() {}
    Account(std::string first, std::string last, int age_of);
    virtual ~Account() = default;
    virtual void print(std::ostream &os) const override;
    
    // Setter and Getters
    
    void set_first_name (std::string fn_entry) {
        first_name = fn_entry;
    }
    
    std::string get_first_name () {
        return first_name;
    }
    
    void set_last_name (std::string ln_entry) {
        last_name = ln_entry;
    }
    
    std::string get_last_name () {
        return last_name;
    }
    
    void set_age (int a_entry) {
        age = a_entry;
    }
    
    int get_age () {
       return age;
    }
    
    
    virtual void method () = 0;
    
};

#endif /* Account_hpp */
