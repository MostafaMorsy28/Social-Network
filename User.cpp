#include "User.h"

LinkedList<User> User:: ll;

User::User()  {
  username = "null";
  name = "null";
  email = "null";
}

User::User(string username, string name, string email) {
this->username = username;
this-> name =  name;
this-> email = email;
}

User::User(const User &user) {
  this->username = user.username;
  this->name = user.name;
  this->email = user.email;
  bst = user.bst;
}

void User::addFriend(User* user) {
  bst = bst->add(bst, user);
  user->bst = user->bst->add(user->bst, this);
}


void User::removeFriend(User* user) {
  bst = bst->del(bst, user);
  user->bst = user->bst->del(user->bst, this);
}

void User::searchFriend(string username) {
  friendsBST* tmp = bst->find(bst, username);
  if (tmp == nullptr) {
    cout << "Not found\n";
  } else {
    cout << *(tmp->getKey()) << " E-mail Address: " << (tmp->getKey())->email << "\n";
  }
}

void User::listAllFriend() {
  bst->inorderOutput(bst);
}

string User::getUsername() {
  return username;
}

User *User::find(string username) {
    for (auto itr = ll.begin(); itr != ll.end(); itr++){
        if ((*itr).getUsername() == username) return &(*itr);
    }
    return nullptr;
}

void User::recommendFriends() {
    int counter = 0;
    for (auto it = ll.begin(); it != ll.end() && counter < 5; it++){
        if (bst->find(bst, (*it).getUsername()) == nullptr && this != &(*it)){
            std :: cout << *it << std :: endl;
            counter++;
        }
    }
}