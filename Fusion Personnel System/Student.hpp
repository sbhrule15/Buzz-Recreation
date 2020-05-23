//
//  Student.hpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include "Account.hpp"

class Student : public Account {

    protected:
    int grade_level {6};
    
    
    public:
    virtual void method () override;
    Student(int grade_level_entry, std::string first_name_entry, std::string last_name_entry, int age_entry);
    virtual void print(std::ostream &os) const override;
    virtual ~Student() = default;
    
};

#endif /* Student_hpp */
