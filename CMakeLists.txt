cmake_minimum_required(VERSION 3.24)
project(2023_Course_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(2023_Course_Project
        main.cpp
        Root/Blocks/Block.h
        Root/String/_string.cpp
        Root/String/_string.h
        Root/Blocks/Topic/Topic.cpp
        Root/Blocks/Topic/Topic.h
        Root/Blocks/Post/Post.cpp
        Root/Blocks/Post/Post.h
        Root/Blocks/Comment/Comment.cpp
        Root/Blocks/Comment/Comment.h
        Root/Interfaces/IOpenable.h
        Root/Collection/Collection.hpp
        Root/System/System.cpp Root/System/System.h)
