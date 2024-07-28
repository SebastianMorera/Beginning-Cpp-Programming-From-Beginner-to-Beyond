#ifndef MYSTRING_H
#define MYSTRING_H
#include <ostream>

class Mystring {
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;  // pointer to a char[] that holds a C-style string
public:
    Mystring(); // No-args constructor
    Mystring(const char *s);    // Overloaded constructor
    Mystring(const Mystring &source);   // Copy constructor
    Mystring( Mystring &&source);   // Move constructor
    ~Mystring();    // Destructor

    Mystring &operator=(const Mystring &rhs);   // Copy assignment
    Mystring &operator=(Mystring &&rhs);    // Move assignment

    void display() const;

    // getters
    int get_length() const;
    const char *get_str() const;

    // Overloaded operator member methods
    Mystring operator-() const;
    Mystring operator+(const Mystring &m) const;
    bool operator==(const Mystring &m) const;
    bool operator!=(const Mystring &m) const;
    bool operator<(const Mystring &m) const;
    bool operator>(const Mystring &m) const;
    Mystring &operator+=(const Mystring &m);
    Mystring operator*(int n) const;
    Mystring &operator*=(int n);
    Mystring &operator++();
    Mystring operator++(int n);
};

#endif //MYSTRING_H
