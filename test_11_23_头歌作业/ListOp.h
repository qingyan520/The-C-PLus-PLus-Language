#pragma once
#include "List.h"
#include <iostream>
using std::ostream;
ostream& operator << (ostream& os, const List& rhs) {
    rhs.disp(os);
    return os;
}
