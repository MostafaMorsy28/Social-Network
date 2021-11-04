cmake_minimum_required(VERSION 3.15)
project(friendsNetwork)

set(CMAKE_CXX_STANDARD 14)

add_executable(friendsNetwork main.cpp friendsBST.cpp friendsBST.h LinkedList.cpp LinkedList.h User.cpp User.h)