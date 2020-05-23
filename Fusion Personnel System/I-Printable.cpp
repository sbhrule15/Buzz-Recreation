//
//  I-Printable.cpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include "I-Printable.hpp"

std::ostream &operator<<(std::ostream &os, const I_Printable &printable) {
    printable.print(os);
    return os;
}
