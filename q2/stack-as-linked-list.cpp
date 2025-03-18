#include <iostream>
using namespace std;

// Struct for Node
struct Node {
  int data;
  Node *next;
};

// Global variable for top of stack
Node *top = NULL;

// Function to push an element onto the stack
void push(int value) {
  Node *newNode = new Node();
  newNode->data = value;
  newNode->next = top;
  top = newNode;
}

// Function to pop an element from the stack
void pop() {
  if (top == NULL) {
    cout << "Stack Underflow" << endl;
    return;
  }
  Node *temp = top;
  top = top->next;
  delete temp;
}

// Function to get the top element of the stack
int peek() {
  if (top == NULL) {
    cout << "Stack is Empty" << endl;
    return -1;
  }
  return top->data;
}

// Function to check if the stack is empty
bool isEmpty() { return top == NULL; }

// Function to display the stack
void display() {
  if (isEmpty()) {
    cout << "Stack is Empty" << endl;
    return;
  }
  Node *temp = top;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  push(10);
  push(20);
  push(30);
  display();

  cout << "Top element: " << peek() << endl;

  pop();
  display();

  return 0;
}
