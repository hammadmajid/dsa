#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

Node *createNode(int value) { return new Node{value, nullptr, nullptr}; }

// Iterative insert
Node *insert(Node *root, int value) {
  Node *newNode = createNode(value);
  if (!root)
    return newNode;

  Node *parent = nullptr;
  Node *curr = root;

  while (curr) {
    parent = curr;
    if (value < curr->data)
      curr = curr->left;
    else
      curr = curr->right;
  }

  if (value < parent->data)
    parent->left = newNode;
  else
    parent->right = newNode;

  return root;
}

// Find minimum value node (iterative)
Node *findMin(Node *node) {
  while (node && node->left)
    node = node->left;
  return node;
}

// Iterative delete
Node *deleteNode(Node *root, int value) {
  Node *parent = nullptr;
  Node *curr = root;

  // Find the node and its parent
  while (curr && curr->data != value) {
    parent = curr;
    if (value < curr->data)
      curr = curr->left;
    else
      curr = curr->right;
  }

  if (!curr)
    return root; // Value not found

  // Case 1: Node has no left child
  if (!curr->left) {
    Node *temp = curr->right;
    if (!parent)
      return temp; // Deleting root
    if (parent->left == curr)
      parent->left = temp;
    else
      parent->right = temp;
    delete curr;
  }
  // Case 2: Node has no right child
  else if (!curr->right) {
    Node *temp = curr->left;
    if (!parent)
      return temp; // Deleting root
    if (parent->left == curr)
      parent->left = temp;
    else
      parent->right = temp;
    delete curr;
  }
  // Case 3: Node has two children
  else {
    Node *succ = findMin(curr->right);
    int succVal = succ->data;
    root = deleteNode(root, succVal); // Recursively delete successor
    curr->data = succVal;
  }

  return root;
}

// Inorder traversal (still recursive for simplicity)
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
  cout << "\n";

  return 0;
}
