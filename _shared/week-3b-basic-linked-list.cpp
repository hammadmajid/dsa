#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};

// Program to create a simple linked

int main() {
  // list with 3 nodes
  Node *head = NULL;
  Node *second = NULL;
  Node *third = NULL;

  // allocate 3 nodes in the heap
  head = new Node();
  second = new Node();
  third = new Node();

  head->data = 1;      // assign data in first node
  head->next = second; // Link first node with

  second->data = 2; // assign data to second node

  // Link second node with the third node
  second->next = third;
  third->data = 3; // assign data to third node
  third->next = NULL;

  return 0;
}
