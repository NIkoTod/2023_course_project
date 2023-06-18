//
// Created by nikol on 17.06.2023.
//

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Factory.h"
#include "../Command/UserCommand/CreateUserCommand.h"
#include "../Command/UserCommand/LoginUserCommand.h"
#include "../Command/UserCommand/PrintUsersCommand.h"
#include "../Command/UnknownCommand.h"
#include "../Command/BlockCommand/CreateTopicCommand.h"
#include "../Command/BlockCommand/PrintTopicsCommand.h"
#include "../Command/BlockCommand/SearchTopicByHeader.h"
#include "../Command/BlockCommand/OpenTopicCommand.h"
#include "../Command/BlockCommand/PostListOnTopicCommand.h"
#include "../Command/BlockCommand/CreatePostCommand.h"
#include "../Command/BlockCommand/QuitTopicCommand.h"
#include "../Command/BlockCommand/OpenPostCommand.h"
#include "../Command/BlockCommand/CreateCommentCommand.h"
#include "../Command/BlockCommand/CommentListOnPost.h"
#include "../Command/BlockCommand/ReplyOnCommentCommand.h"
#include "../Command/UserCommand/LogoutUserCommand.h"
#include "../Command/BlockCommand/ClosePostCommand.h"
#include "../Command/BlockCommand/VoteCommand.h"
#include "../Command/UserCommand/PrintProfileCommand.h"
#include "../Command/BlockCommand/InfoAboutTopicCommand.h"

class CommandFactory{
public:

    static Command *create(const _string& association) {
        if(association == "signup") return new CreateUserCommand();
        if(association == "login") return new LoginUserCommand();
        if(association == "logout") return new LogoutUserCommand();
        if(association == "print_users") return new PrintUsersCommand();
        if(association == "print_topics") return new PrintTopicsCommand();
        if(association == "create") return new CreateTopicCommand();
        if(association == "search") return new SearchTopicByHeader();
        if(association == "open") return new OpenTopicCommand();
        if(association == "list") return new PostListOnTopicCommand();
        if(association == "post") return new CreatePostCommand();
        if(association == "quit") return new QuitTopicCommand();
        if(association == "p_open") return new OpenPostCommand();
        if(association == "p_close") return new ClosePostCommand();
        if(association == "comment") return new CreateCommentCommand();
        if(association == "comments") return new CommentListOnPost();
        if(association == "reply") return new ReplyOnCommentCommand();
        if(association == "about") return new InfoAboutTopicCommand();
        if(association == "whoami") return new PrintProfileCommand();
        if(association == "upvote"){ return (new VoteCommand())->provideVoteType(Vote::LIKE);}
        if(association == "downvote"){ return (new VoteCommand())->provideVoteType(Vote::DISLIKE);}
        return new UnknownCommand();
    }

};
#endif //COMMANDFACTORY_H
