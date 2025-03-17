#include <iostream>
#include <string>
using namespace std;

struct Node {
  char data;
  Node *link;
};

Node *top = NULL;

bool isEmpty() { return top == NULL; }

void push(char value) {
  Node *newNode = new Node();
  newNode->data = value;
  newNode->link = top;
  top = newNode;
}

void pop() {
  if (isEmpty())
    return;
  Node *temp = top;
  top = top->link;
  delete temp;
}

char peek() { return isEmpty() ? '\0' : top->data; }

bool isMatch(char open, char close) {
  bool parenPair = open == '(' && close == ')';
  bool bracesPair = open == '{' && close == '}';
  bool bracketsPair = open == '[' && close == ']';

  if (parenPair || bracesPair || bracketsPair) {
    return true;
  } else {
    return false;
  }
}

bool checkBrackets(string expr) {
  int len = expr.length();
  for (int i = 0; i < len; i++) {
    switch (expr[i]) {
    case '(':
    case '{':
    case '[':
      push(expr[i]);
      break;
    case ')':
    case '}':
    case ']':
      if (isEmpty() || !isMatch(peek(), expr[i])) {
        return false;
      }
      pop();
      break;
    }
  }
  return isEmpty();
}

int main() {
  string input;
  cout << "Enter expression: ";
  cin >> input;

  if (checkBrackets(input))
    cout << "Matched\n";
  else
    cout << "Not matched\n";

  return 0;
}
