#include <iostream>
#define MAX 5

using namespace std;

char stack[MAX];
int top;

void initStack() { top = -1; }

bool isEmpty() { return top == -1; };

bool isFull() { return top == MAX - 1; }

void push(char data) {
  if (isFull()) {
    cout << "Stack overflow" << endl;
  } else {
    top += 1;
    stack[top] = data;
  }
}

void pop() {
  if (isEmpty()) {
    cout << "Stack underfow" << endl;
  } else {
    stack[top] = ' ';
    top -= 1;
  }
}

void display() {
  for (int i = 0; i <= top; i++) {
    cout << stack[i] << endl;
  }
}

void deleteStack() {
  for (int i = 0; i <= top; i++) {
    stack[i] = ' ';
  }
  top = -1;
}

int main() {
  initStack();

  push('a');
  push('b');
  pop();
  push('c');

  display();

  deleteStack();
}
