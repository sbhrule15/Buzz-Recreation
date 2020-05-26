//
//  I-Printable.hpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#ifndef I_Printable_hpp
#define I_Printable_hpp

#include <stdio.h>
#include <iostream>
#include <string>


class I_Printable {
public:
   // friend std::ostream &operator<<(std::ostream &os, const I_Printable &printable);
    
    
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
    
};

#endif /* I_Printable_hpp */
