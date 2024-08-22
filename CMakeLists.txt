cmake_minimum_required(VERSION 3.28)
project(CCGStatBalancer)

set(CMAKE_CXX_STANDARD 26)

add_executable(CCGStatBalancer main.cpp
        CardCostCalculator.h
        CardStats.h
        CardStats.cpp
        CardCostCalculator.cpp
)
