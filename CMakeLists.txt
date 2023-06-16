cmake_minimum_required(VERSION 3.24)
project(2023_Course_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(2023_Course_Project
        main.cpp
        Root/Utility/String/_string.cpp
        Root/Blocks/Topic/Topic.cpp
        Root/Blocks/Post/Post.cpp
        Root/Blocks/Comment/Comment.cpp
        Root/Utility/Collection/Collection.hpp
        Root/Repository/Repository.cpp
        Root/User/User.cpp Root/User/User.h
        Root/Utility/Set/_set.hpp
        Root/Command/Command.h
        Root/Command/UserCommand/CreateUserCommand.h
        Root/Interfaces/IOpenable.h
        Root/Interfaces/IWriteble.h
        Root/Factory/Factory.h
        Root/Factory/UserFactory.h
        )
