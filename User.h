#ifndef FRIENDSNETWORK_USER_H
#define FRIENDSNETWORK_USER_H

#include <iostream>
#include "friendsBST.h"
#include "LinkedList.h"

using namespace std;

class friendsBST;

class User {
private:
    string username, name, email;
    friendsBST* bst = nullptr;
public:
    static User* find(string username);
    static LinkedList<User> ll;
    User();
    User(string username, string name, string email);
    User(const User &user);
    friend istream& operator>> (istream& input, User& u) {
      input >> u.username >> u.name >> u.email;
      return input;
    }
    friend ostream& operator<< (ostream& output, User& u) {
      output << "Username: " << u.username << " Full name: " << u.name;
      return output;
    }
    string getUsername();
    void addFriend(User* username);
    void removeFriend(User* username);
    void searchFriend(string username);
    void listAllFriend();
    void recommendFriends();
};


#endif //FRIENDSNETWORK_USER_H
