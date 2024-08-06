cmake_minimum_required(VERSION 3.28)
project(Exception_Handling_Challenge)

set(CMAKE_CXX_STANDARD 17)

add_executable(Exception_Handling_Challenge main.cpp
        IllegalBalanceException.h
        Account.h
        Account.cpp
        Account_Util.h
        Account_Util.cpp
        Checking_Account.cpp
        I_Printable.cpp
        Savings_Account.cpp
        Trust_Account.cpp
        InsufficentFundsException.h)
