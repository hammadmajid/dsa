#include <iostream>
#define MAX 5

using namespace std;

int stack[MAX], top;

void initStack() { top = -1; }

bool isEmpty() { return top == -1; };

bool isFull() { return top == MAX - 1; }

void push(int data) {
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
    stack[top] = 0;
    top -= 1;
    ;
  }
}

void display() {
  for (int i = 0; i <= top; i++) {
    cout << stack[i] << endl;
  }
}

int main() {
  initStack();

  push(1);
  push(2);
  pop();
  push(3);

  display();
}
