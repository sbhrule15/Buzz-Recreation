//
//  Teacher.hpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#ifndef Teacher_hpp
#define Teacher_hpp

#include <stdio.h>
#include "Account.hpp"
#include <string>

class Teacher : public Account {
private:
    
protected:
    std::string department {"None"};
    std::string subject {"None"};
    
public:
    virtual void method () override;
    
    void get_info ();
    std::string get_department(){ return department;};
    std::string get_subject(){ return subject;};
    
    Teacher() {}
    Teacher(std::string department_entry, std::string subject_entry, std::string first_name_entry, std::string last_name_entry, int age_entry);
    virtual void print(std::ostream &os) const override;
    
    virtual ~Teacher() = default;
    
    
};

#endif /* Teacher_hpp */
