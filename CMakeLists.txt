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
        Root/User/User.cpp
        Root/Utility/Set/_set.hpp
        Root/Command/Command.h
        Root/Command/UserCommand/CreateUserCommand.h
        Root/Interfaces/IWriteble.hpp
        Root/Factory/Factory.h
        Root/Factory/UserFactory.h
        Root/Factory/CommandFactory.h
        Root/Command/UserCommand/LoginUserCommand.h
        Root/Command/Command.cpp
        Root/Program/Program.cpp
        Root/Interfaces/IProgram.h)
