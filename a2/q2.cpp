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

char peek() { return (top != NULL) ? top->data : '\0'; }

bool isPalindrome(string input) {
  int len = input.length();

  for (int i = 0; i < len / 2; i++)
    push(input[i]);

  for (int i = (len + 1) / 2; i < len; i++) {
    if (peek() != input[i])
      return false;
    else
      pop();
  }
  return true;
}

int main() {
  string input;
  cout << "Enter string/number: ";
  cin >> input;

  if (isPalindrome(input))
    cout << "Palindrome\n";
  else
    cout << "Not a palindrome\n";

  return 0;
}
