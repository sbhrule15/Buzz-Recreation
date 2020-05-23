//
//  Admin.hpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#ifndef Admin_hpp
#define Admin_hpp

#include <stdio.h>
#include "Account.hpp"

class Admin : public Account {
    private:
    
    
    protected:
    std::string title {"Admin"};
    
    
    public:
    Admin() {}
    Admin(std::string title_entry, std::string first_name_entry, std::string last_name_entry, int age_entry);
    virtual void method () override;
    virtual void print(std::ostream &os) const override;
    virtual ~Admin () = default;
    
    
};

#endif /* Admin_hpp */
