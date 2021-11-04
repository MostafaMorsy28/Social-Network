/*
  -----------------------------------------------
     Names		                  	IDs
  -----------------------------------------------
  1- Mostafa Mahmoud Anwar Morsy	20190544
  2- Mohamed Ashraf Mohamed Al   	20190424
  3- Elhussein Abd Alaziz Youssef	20190106
  4- Mohamed Essam beshier	      20190461
  5- Joseph diaa saied	        	20190155
  6- Abdelrahman Ali Fathy      	20190314
  7- David Ayman Youssef Morcos  	20190196
  -----------------------------------------------
*/

#include <iostream>
#include <fstream>
#include "User.h"

using namespace std;

void menu(){
    std :: cout << "1. List all Friends\n2. Search by username\n3. Add Friend\n4. Remove friend\n";
    std :: cout << "5. People you may know\n6. Logout\n9. Exit\n";
}

bool loggedIN = false;
User *currentUser = nullptr;

int main() {
  // Input from file

  ifstream inFile;
  inFile.open("../all-users.in");
  string str, username, name, email;
  while (getline(inFile, str)) {
    if (str == "") {
      continue;
    }
    int i = 0;
    username = name = email = "";
    while (str[i] != ',')  {
      username+= str[i++];
    }
    i+= 2;
    while (str[i] != ',') {
      name+= str[i++];
    }
    i+= 2;
    while (i < str.size()) {
      email+= str[i++];
    }
    User::ll.insert(User(username, name, email));
  }
  inFile.close();
  inFile.open("../all-users-relations.in");
  string username1, username2;
  while (getline(inFile, str)) {
    if (str == "") {
      continue;
    }
    int i=0;
    username1 = username2 = "";
    while (str[i] != ',') {
      username1+= str[i++];
    }
    i+=2;
    while (i < str.size()) {
      username2+= str[i++];
    }
    User *user1 = User::find(username1), *user2 = User::find(username2);
    if (user1 && user2) {
        user1->addFriend(user2);
    }
  }
  inFile.close();

  int choice = 0;
  while (choice != 9){
      std :: cout << "1. Login\n9. Exit\n";
      std :: cin >> choice;
      if (choice == 1){
          // LOGIN FUNCTION
          while (true){
              string us;
              std :: cout << "Enter your username\n";
              std :: cin >> us;
              currentUser = User::find(us);
              if (currentUser == nullptr) std :: cout << "invalid username, try again";
              else {
                  loggedIN = true;
                  break;
              }
          }
      }
      while (choice != 9 && loggedIN){
          menu();
          std :: cin >> choice;
          if (choice == 1){
              std :: cout << "---------- Friends List ----------\n";
              currentUser->listAllFriend();
              std :: cout << "----------------------------------\n";
          }
          else if (choice == 2){
              std :: cout << "Enter the username you would like to find \n";
              string x;
              std :: cin >> x;
              currentUser->searchFriend(x);
          }
          else if (choice == 3){
              std :: cout << "Enter the username you would like to add as a friend.\n";
              string x;
              std :: cin >> x;
              User *searched = User::find(x);
              if (searched == nullptr) std :: cout << "User was not found\n";
              else {
                  cout << *currentUser << std :: endl << *searched << std :: endl;
                  currentUser->addFriend(searched);
              }
              delete &searched;
          }
          else if (choice == 4){
              std :: cout << "Enter the username you would like to remove from your friend list.\n";
              string x;
              std :: cin >> x;
              User *searched = User::find(x);
              if (searched == nullptr) std :: cout << "User was not found\n";
              else currentUser->removeFriend(searched);
              delete &searched;
          }
          else if (choice == 5){
              currentUser->recommendFriends();
          }
          else if (choice == 6){
              loggedIN = false;
              currentUser = nullptr;
              break;
          }
          else if (choice != 9) std :: cout << "Please enter a valid operation number\n";
      }
  }


  delete currentUser;
  return 0;
}
