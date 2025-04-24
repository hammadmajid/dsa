#include <iostream>
using namespace std;

// Maximum size of stack
const int MAX_SIZE = 100;

// Global variables
int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
  if (top >= MAX_SIZE - 1) {
    cout << "Stack Overflow" << endl;
    return;
  }
  top++;
  stack[top] = value;
}

// Function to pop an element from the stack
void pop() {
  if (top < 0) {
    cout << "Stack Underflow" << endl;
    return;
  }
  top--;
}

// Function to get the top element of the stack
int peek() {
  if (top < 0) {
    cout << "Stack is Empty" << endl;
    return -1;
  }
  return stack[top];
}

// Function to check if the stack is empty
bool isEmpty() { return top == -1; }

// Function to display the stack
void display() {
  if (isEmpty()) {
    cout << "Stack is Empty" << endl;
    return;
  }
  for (int i = 0; i <= top; i++) {
    cout << stack[i] << " ";
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
