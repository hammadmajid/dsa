#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int value) {
    data = value;
    left = 0;
    right = 0;
  }
};

class BinaryTree {
public:
  Node *root;

  BinaryTree() { root = 0; }

  Node *insert(Node *node, int value) {
    if (node == 0)
      return new Node(value);
    if (value < node->data)
      node->left = insert(node->left, value);
    else
      node->right = insert(node->right, value);
    return node;
  }

  void insert(int value) { root = insert(root, value); }

  void inorder(Node *node) {
    if (node == 0)
      return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }

  void preorder(Node *node) {
    if (node == 0)
      return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
  }

  void postorder(Node *node) {
    if (node == 0)
      return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
  }

  void printInorder() {
    inorder(root);
    cout << endl;
  }

  void printPreorder() {
    preorder(root);
    cout << endl;
  }

  void printPostorder() {
    postorder(root);
    cout << endl;
  }
};

int main() {
  BinaryTree tree;
  tree.insert(50);
  tree.insert(30);
  tree.insert(70);
  tree.insert(20);
  tree.insert(40);
  tree.insert(60);
  tree.insert(80);

  cout << "Inorder: ";
  tree.printInorder();

  cout << "Preorder: ";
  tree.printPreorder();

  cout << "Postorder: ";
  tree.printPostorder();

  return 0;
}
