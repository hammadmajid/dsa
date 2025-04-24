#include <iostream>

struct Node {
  int data;
  Node *left;
  Node *right;
};

int maxDepth(Node *root) {
  // Root being null means tree doesn't exist.
  if (root == NULL)
    return 0;

  // Get the depth of the left and right subtree
  // using recursion.
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);

  // Choose the larger one and add the root to it.
  if (leftDepth > rightDepth)
    return leftDepth + 1;
  else
    return rightDepth + 1;
}

int main() {}
