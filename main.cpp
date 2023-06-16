#include <iostream>
#include <sstream>
#include "Root/Blocks/Topic/Topic.h"
#include "Root/Utility/Set/_set.hpp"
#include "Root/Factory/UserFactory.h"

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

    UserFactory f;
    f.create();

}