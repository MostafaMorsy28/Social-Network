#ifndef SOCIALNETWORK_FRIENDSBST_H
#define SOCIALNETWORK_FRIENDSBST_H

#include <iostream>
#include "User.h"

using namespace std;

class User;

class friendsBST {
private:
    friendsBST *right, *left;
    User* key;
    int priority;
public:
    friendsBST* add (friendsBST* root, User* key);
    friendsBST* del (friendsBST* root, User* key);
    friendsBST* find (friendsBST* root, string username);
    friendsBST* createNode (User* key);
    friendsBST* leftRotation(friendsBST* root);
    friendsBST* rightRotation(friendsBST* root);
    User* getKey();
    void inorderOutput(friendsBST* root);
};


#endif //SOCIALNETWORK_FRIENDSBST_H
