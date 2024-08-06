#ifndef ILLEGAL_BALANCE_EXCEPTION_H_
#define ILLEGAL_BALANCE_EXCEPTION_H_
#include <exception>

class IllegalBalanceException: public std::exception
{
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() override = default;
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Illegal balance exception";
    }
};

#endif // ILLEGAL_BALANCE_EXCEPTION_H_
