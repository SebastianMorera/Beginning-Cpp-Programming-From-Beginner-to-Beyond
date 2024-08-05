cmake_minimum_required(VERSION 3.28)
project(Polymorphism_challenge)

set(CMAKE_CXX_STANDARD 17)

add_executable(Polymorphism_challenge main.cpp
        Account.cpp
        l_Printable.cpp
        l_Printable.h
        Checking_Account.cpp
        Savings_Account.cpp
        Trust_Account.cpp
        Account_Util.cpp)
