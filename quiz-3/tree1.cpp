#include <iostream>
using namespace std;

// Structure for a single node in the binary search tree
struct Node {
  int data;    // Data stored in the node
  Node *left;  // Pointer to the left child
  Node *right; // Pointer to the right child
};

class BST {
public:
  Node *root; // Root of the BST

  // Constructor initializes the root to NULL
  BST() { root = NULL; }

  // Creates a new node with given value and returns pointer to it
  Node *createNode(int value) {
    Node *newNode = new Node(); // Allocate memory
    newNode->data = value;      // Set data
    newNode->left = NULL;       // Left child is NULL
    newNode->right = NULL;      // Right child is NULL
    return newNode;
  }

  // Iteratively inserts a value into the BST
  void insertIteratively(int value) {
    Node *newNode = createNode(value); // Create new node

    if (root == NULL) {
      root = newNode; // Tree is empty, new node is root
      return;
    }

    Node *current = root;
    Node *parent = NULL;

    while (current != NULL) {
      parent = current;
      if (value < current->data)
        current = current->left; // Move to left subtree
      else
        current = current->right; // Move to right subtree
    }

    if (value < parent->data)
      parent->left = newNode; // Attach new node to left
    else
      parent->right = newNode; // Attach new node to right
  }

  // Recursively inserts a value into the BST
  Node *insertRecursively(Node *node, int value) {
    if (node == NULL)
      return createNode(value); // Base case: create and return new node

    if (value < node->data)
      node->left = insertRecursively(node->left, value); // Go to left subtree
    else
      node->right =
          insertRecursively(node->right, value); // Go to right subtree

    return node;
  }

  // Helper to call recursive insert with root
  void insertRecursively(int value) { root = insertRecursively(root, value); }

  // In-order traversal: Left -> Root -> Right
  void inOrderTraversal(Node *node) {
    if (node == NULL)
      return;

    inOrderTraversal(node->left);  // Visit left subtree
    cout << node->data << " ";     // Visit root
    inOrderTraversal(node->right); // Visit right subtree
  }

  // Post-order traversal: Left -> Right -> Root
  void postOrderTraversal(Node *node) {
    if (node == NULL)
      return;

    postOrderTraversal(node->left);  // Visit left subtree
    postOrderTraversal(node->right); // Visit right subtree
    cout << node->data << " ";       // Visit root
  }

  // Returns the height of the tree
  int getHeight(Node *node) {
    if (node == NULL)
      return 0;

    int leftHeight = getHeight(node->left);   // Height of left subtree
    int rightHeight = getHeight(node->right); // Height of right subtree

    return max(leftHeight, rightHeight) + 1; // Add 1 for current node
  }

  // Prints all nodes at a given level
  void printGivenLevel(Node *node, int level) {
    if (node == NULL)
      return;

    if (level == 1)
      cout << node->data << " "; // Print data at current level
    else {
      printGivenLevel(node->left, level - 1);  // Go to left child
      printGivenLevel(node->right, level - 1); // Go to right child
    }
  }

  // Prints level-order traversal using printGivenLevel
  void printLevelOrder() {
    int height = getHeight(root); // Get tree height
    for (int i = 1; i <= height; ++i) {
      printGivenLevel(root, i); // Print each level
    }
  }

  // Iteratively searches for a value in the BST
  bool searchIteratively(int value) {
    Node *current = root;
    while (current != NULL) {
      if (value == current->data)
        return true; // Value found
      else if (value < current->data)
        current = current->left; // Search in left subtree
      else
        current = current->right; // Search in right subtree
    }
    return false; // Not found
  }

  // Recursively searches for a value in the BST
  bool searchRecursively(Node *node, int value) {
    if (node == NULL)
      return false; // Base case: not found

    if (value == node->data)
      return true; // Value found

    if (value < node->data)
      return searchRecursively(node->left, value); // Search left
    else
      return searchRecursively(node->right, value); // Search right
  }

  // Helper to call recursive search with root
  bool searchRecursively(int value) { return searchRecursively(root, value); }
};

// Example usage
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
