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
    
    virtual void method () = 0;
    
};

#endif /* Account_hpp */
