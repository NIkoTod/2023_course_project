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
        Root/Interfaces/IProgram.h Root/Command/UserCommand/PrintUsersCommand.h Root/Command/UnknownCommand.h Root/Command/UserCommand/LogoutUserCommand.h Root/Command/BlockCommand/CreateTopicCommand.h Root/Factory/TopicFactory.h Root/Command/BlockCommand/PrintTopicsCommand.h Root/Command/BlockCommand/SearchTopicByHeader.h Root/Command/BlockCommand/OpenTopicCommand.h Root/Command/BlockCommand/PostListOnTopicCommand.h Root/Command/BlockCommand/CreatePostCommand.h Root/Factory/PostFactory.h Root/Command/BlockCommand/QuitTopicCommand.h Root/Command/BlockCommand/OpenPostCommand.h Root/Factory/CommentFactory.h Root/Command/BlockCommand/CreateCommentCommand.h Root/Command/BlockCommand/CommentListOnPost.h Root/Command/BlockCommand/ReplyOnCommentCommand.h Root/Command/BlockCommand/ClosePostCommand.h Root/Command/BlockCommand/VoteCommand.h Root/Command/UserCommand/PrintProfileCommand.h Root/Command/BlockCommand/InfoAboutTopicCommand.h)
