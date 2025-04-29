#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

class BST {
public:
  Node *root;
  BST() { root = NULL; }

  Node *createNode(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  void insertIteratively(int value) {
    Node *newNode = createNode(value);
    if (root == NULL) {
      root = newNode;
      return;
    }

    Node *current = root;
    Node *parent = NULL;

    while (current != NULL) {
      parent = current;
      if (value < current->data)
        current = current->left;
      else
        current = current->right;
    }

    if (value < parent->data)
      parent->left = newNode;
    else
      parent->right = newNode;
  }

  Node *insertRecursively(Node *node, int value) {
    if (node == NULL)
      return createNode(value);
    if (value < node->data)
      node->left = insertRecursively(node->left, value);
    else
      node->right = insertRecursively(node->right, value);
    return node;
  }

  void insertRecursively(int value) { root = insertRecursively(root, value); }

  void inOrderTraversal(Node *node) {
    if (node == NULL)
      return;

    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
  }

  void postOrderTraversal(Node *node) {
    if (node == NULL)
      return;

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
  }

  int getHeight(Node *node) {
    if (node == NULL)
      return 0;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return max(leftHeight, rightHeight) + 1;
  }

  void printGivenLevel(Node *node, int level) {
    if (node == NULL)
      return;

    if (level == 1)
      cout << node->data << " ";
    else {
      printGivenLevel(node->left, level - 1);
      printGivenLevel(node->right, level - 1);
    }
  }

  void printLevelOrder() {
    int height = getHeight(root);
    for (int i = 1; i <= height; ++i) {
      printGivenLevel(root, i);
    }
  }

  bool searchIteratively(int value) {
    Node *current = root;
    while (current != NULL) {
      if (value == current->data)
        return true;
      else if (value < current->data)
        current = current->left;
      else
        current = current->right;
    }
    return false;
  }

  bool searchRecursively(Node *node, int value) {
    if (node == NULL)
      return false;
    if (value == node->data)
      return true;
    if (value < node->data)
      return searchRecursively(node->left, value);
    else
      return searchRecursively(node->right, value);
  }

  bool searchRecursively(int value) { return searchRecursively(root, value); }

  // Helper to find minimum node in a subtree
  Node *findMin(Node *node) {
    while (node && node->left != NULL)
      node = node->left;
    return node;
  }

  Node *deleteNode(Node *node, int value) {
    if (node == NULL)
      return NULL;

    if (value < node->data) {
      node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
      node->right = deleteNode(node->right, value);
    } else {
      // Node found
      if (node->left == NULL) {
        Node *temp = node->right;
        delete node;
        return temp;
      } else if (node->right == NULL) {
        Node *temp = node->left;
        delete node;
        return temp;
      } else {
        // Node with two children
        Node *temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
      }
    }
    return node;
  }

  void deleteNode(int value) { root = deleteNode(root, value); }
};

int main() {
  BST tree;

  tree.insertIteratively(10);
  tree.insertIteratively(5);
  tree.insertIteratively(15);
  tree.insertRecursively(3);
  tree.insertRecursively(7);
  tree.insertRecursively(18);

  cout << "In-order Traversal: ";
  tree.inOrderTraversal(tree.root);
  cout << "\n";

  cout << "Post-order Traversal: ";
  tree.postOrderTraversal(tree.root);
  cout << "\n";

  cout << "Level-order Traversal: ";
  tree.printLevelOrder();
  cout << "\n";

  cout << "Search 7 Iteratively: "
       << (tree.searchIteratively(7) ? "Found" : "Not Found") << "\n";
  cout << "Search 100 Recursively: "
       << (tree.searchRecursively(100) ? "Found" : "Not Found") << "\n";

  cout << "Height of tree: " << tree.getHeight(tree.root) << "\n";

  return 0;
}
