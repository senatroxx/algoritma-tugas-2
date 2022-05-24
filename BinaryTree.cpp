/*
 * NAMA : Muhamad Athhar Kautsar
 * NPM  : 065121076
 * 
 */

#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;

  Node(int value)
  {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

void preorderTraversal(struct Node *node)
{
  if (node == NULL)
    return;

  cout << node->value << "->";
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}

void print(const string &prefix, const Node *node, bool isLeft, bool nodeLeft, bool isRoot)
{
  if (node != NULL)
  {
    bool condition;
    cout << prefix;
    cout << (nodeLeft ? "├──" : "└──");

    if (isRoot) {
      cout << "\033[1;31m" + to_string(node->value) + "\033[0m" << endl;
    }
    if (nodeLeft && !isRoot) {
      cout << "\033[1;34m" + to_string(node->value) + "\033[0m" << endl;
    }else if (!nodeLeft && !isRoot) {
      cout << "\033[1;33m" + to_string(node->value) + "\033[0m" << endl;
    }

    auto ikon = isLeft ? "│  " : "   ";
    if(node->right == NULL)
    {
      print(prefix + ikon, node->left, false, true, false);
    }else{
      print(prefix + ikon, node->left, true, true, false);
    }
    print(prefix + ikon, node->right, false, false, false);
  }
}

int main(){
  Node *root = new Node(5);
  root->left = new Node(2);
  root->right = new Node(6);
  root->left->left = new Node(12);
  root->left->right = new Node(3);
  root->right->left = new Node(7);
  root->right->left->right = new Node(23);
  root->right->left->left = new Node(19);
  root->right->right = new Node(9);
  root->right->right->right = new Node(20);
  root->right->right->right->left = new Node(41);
  root->left->left->left = new Node(1);
  root->left->left->left->right = new Node(4);
  root->left->left->left->right->left = new Node(25);
  
  print("", root, false, false, true);

  cout << endl << "Preorder Traversal: " << endl;
  preorderTraversal(root);

  return 0;
}