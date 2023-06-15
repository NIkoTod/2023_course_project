#include <iostream>
#include "Root/Blocks/Topic/Topic.h"

int main() {

    Topic topic("TopicTest","Me","NODATA");
    Post post("PostTest","TEST");
    Comment comment("Me","TestComment");

    topic.addPost(post);
    post.addComment(comment);
    topic.print();
    std::cout<<"\n--------"<<"\n";
    topic.list();
    std::cout<<"\n--------"<<"\n";
    comment.print();


}
