#include <iostream>
#include <sstream>
#include "Root/Program/Program.h"

int main() {


//    Topic topic("TopicTest","Me","NODATA");
//    Post post("PostTest","TEST");
//    Comment comment("Me","TestComment");
//
//    topic.addPost(post);
//    post.addComment(comment);
//    topic.print();
//    std::cout<<"\n--------"<<"\n";
//    topic.list();
//    std::cout<<"\n--------"<<"\n";
//    comment.print();

//    std::ifstream f("test.dat",std::ios::binary);
//    _string test;
//    test.readFromFile(f);
//    test.print();
//
//
//    std::ifstream ifs("testSaveData.dat",std::ios::binary);
//    Repository::GetInstance()->readData(ifs);
//    Command::setRepository(Repository::GetInstance());
//    CreateUserCommand createUserCommand;
//    createUserCommand.execute();
//
//    Repository * repo = Repository::GetInstance();
//    std::ofstream f("testSaveData.dat",std::ios::binary);
//    repo->getUserAt(0).addPoints(1);
//    repo->saveData(f);
//    Repository::GetInstance()->getUsers().print();
//    std::cout<<"\n\n\n";

    Program::getInstance()->run();

}