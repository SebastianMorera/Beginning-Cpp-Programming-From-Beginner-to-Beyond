#ifndef INSUFFICENTFUNDSEXCEPTION_H
#define INSUFFICENTFUNDSEXCEPTION_H
#include <exception>


class InsufficentFundsException: public std::exception {
public:
    InsufficentFundsException() noexcept = default;
    ~InsufficentFundsException() override = default;
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Unsufficent funds exception";
    }
};



#endif //INSUFFICENTFUNDSEXCEPTION_H
