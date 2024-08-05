#include "l_Printable.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const l_Printable &obj)
{
    obj.print(os);
    return os;
}