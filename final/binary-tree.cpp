#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

Node *createNode(int value) { return new Node{value, nullptr, nullptr}; }

Node *insert(Node *root, int value) {
  if (!root)
    return createNode(value);
  if (value < root->data)
    root->left = insert(root->left, value);
  else
    root->right = insert(root->right, value);
  return root;
}

Node *findMin(Node *root) {
  while (root->left)
    root = root->left;
  return root;
}

Node *deleteNode(Node *root, int value) {
  if (!root)
    return root;
  if (value < root->data)
    root->left = deleteNode(root->left, value);
  else if (value > root->data)
    root->right = deleteNode(root->right, value);
  else {
    if (!root->left)
      return root->right;
    if (!root->right)
      return root->left;
    Node *temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

void inorder(Node *root) {
  if (root) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

int main() {
  Node *root = nullptr;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 70);
  insert(root, 20);
  insert(root, 40);
  insert(root, 60);
  insert(root, 80);

  cout << "Inorder before deletion: ";
  inorder(root);
  cout << "\n";

  root = deleteNode(root, 30);
  cout << "Inorder after deleting 30: ";
  inorder(root);
}
