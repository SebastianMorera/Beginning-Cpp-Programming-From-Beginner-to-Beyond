cmake_minimum_required(VERSION 3.28)
project(Inheritance_challenge)

set(CMAKE_CXX_STANDARD 17)

add_executable(Inheritance_challenge main.cpp
        Savings_Account.h
        Account.h
        Account.cpp
        Savings_Account.cpp
        Account_Util.h
        Account_Util.cpp
        Checking_Account.cpp
        Checking_Account.h
        Trust_Account.cpp
        Trust_Account.h)
