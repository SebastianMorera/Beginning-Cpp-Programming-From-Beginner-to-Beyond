#ifndef L_PRINTABLE_H
#define L_PRINTABLE_H
#include <iostream>

class l_Printable {
    friend std::ostream &operator<<(std::ostream &os, const l_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~l_Printable() = default;
};

#endif //L_PRINTABLE_H
