#include <iostream>

#include "Account.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"
#include "Savings_Account.h"

int main()
{
    std::unique_ptr<Account> moes_account;
    std::unique_ptr<Account> larrys_account;

    try
    {
        larrys_account = std::make_unique<Savings_Account>("Larry", -2000.0);
        std::cout << *larrys_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    try
    {
        moes_account = std::make_unique<Savings_Account>("Moe", 1000.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(500.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(1000.0);
        std::cout << *moes_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch (const InsufficentFundsException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
