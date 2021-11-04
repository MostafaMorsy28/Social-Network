#include "friendsBST.h"

friendsBST * friendsBST::add(friendsBST *root, User* key) {
  if (root == nullptr) {
    return createNode(key);
  }
  if (key->getUsername() == root->key->getUsername()){
      return root;
  }
  if (key->getUsername() < root->key->getUsername()) {
    root->left = add(root->left, key);
    if (root->priority > root->left->priority) {
      root = rightRotation(root);
    }
  } else {
    root->right = add(root->right, key);
    if (root->priority > root->right->priority) {
      root = leftRotation(root);
    }
  }
  return root;
}

friendsBST * friendsBST::del(friendsBST *root, User* key) {
  if (root == nullptr) {
    return root;
  }
  if (key->getUsername() < root->getKey()->getUsername()) {
    root->left = del(root->left, key);
    return root;
  } else if (key->getUsername() > root->getKey()->getUsername()) {
    root->right = del(root->right, key);
    return root;
  }

  if (root->left == nullptr) {
    friendsBST* tmp = root;
    root = root->right;
    delete tmp;
  } else if (root->right == nullptr) {
    friendsBST* tmp = root;
    root = root->left;
    delete tmp;
  } else if (root->left->priority < root->right->priority) {
    root = rightRotation(root);
    root->right = del(root->right, key);
  } else {
    root = leftRotation(root);
    root->left = del(root->left, key);
  }
  return root;
}

friendsBST *friendsBST::find(friendsBST *root, string username) {
  if (root == nullptr || root->key->getUsername() == username) {
    return root;
  }
  if (root->key->getUsername() > username) {
    return find(root->left, username);
  } else {
    return find(root->right, username);
  }
}

friendsBST* friendsBST::createNode (User* key) {
  friendsBST* ret = new friendsBST;
  ret->key = key;
  ret->priority = rand()%100;
  ret->left = ret->right = nullptr;
  return ret;
}

friendsBST* friendsBST:: leftRotation(friendsBST *root) {
  friendsBST* ret = root->right;
  root->right = root->right->left;
  ret->left = root;
  return ret;
}

friendsBST* friendsBST:: rightRotation(friendsBST *root) {
  friendsBST* ret = root->left;
  root->left = root->left->right;
  ret->right = root;
  return ret;
}

User* friendsBST:: getKey() {
  return key;
}

void friendsBST::inorderOutput(friendsBST* root) {
  if (root == nullptr) {
    return;
  }
  inorderOutput(root->left);
  cout << *(root->getKey()) << "\n";
  inorderOutput(root->right);
}