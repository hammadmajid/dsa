#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *createNode(int value) {
  Node *node = new Node;
  node->data = value;
  node->left = node->right = 0;
  return node;
}

Node *insert(Node *root, int value) {
  if (!root)
    return createNode(value);
  if (value < root->data)
    root->left = insert(root->left, value);
  else
    root->right = insert(root->right, value);
  return root;
}

Node *binarySearch(Node *root, int target) {
  while (root) {
    if (root->data == target)
      return root;
    else if (target < root->data)
      root = root->left;
    else
      root = root->right;
  }
  return 0;
}

int main() {
  Node *root = 0;
  int values[] = {10, 5, 15, 3, 7, 12, 17};
  for (int i = 0; i < 7; ++i)
    root = insert(root, values[i]);

  int target = 7;
  Node *result = binarySearch(root, target);
  if (result)
    cout << "Found: " << result->data << endl;
  else
    cout << "Not found" << endl;
  return 0;
}
