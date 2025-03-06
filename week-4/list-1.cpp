#include <iostream>
using namespace std;

class List {
public:
  struct Node {
    int data;
    Node *next;
    Node *prev;
  };

  Node *head, *tail;

  List() {
    head = NULL;
    tail = NULL;
  }

  int size() {
    if (head == NULL)
      return 0;

    int count = 0;
    Node *tmp = head;
    while (tmp != NULL) {
      count += 1;
      tmp = tmp->next;
    }

    return count;
  }

  void push_front(int value) {
    Node *temp = new Node();
    temp->data = value;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL) {
      head->prev = temp;
    } else {
      tail = temp;
    }
    head = temp;
  }

  void push_back(int value) {
    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;
    temp->prev = tail;

    if (tail != NULL) {
      tail->next = temp;
    } else {
      head = temp;
    }
    tail = temp;
  }

  void display() {
    Node *tmp = head;
    while (tmp != NULL) {
      cout << tmp->data << " ";
      tmp = tmp->next;
    }
    cout << endl;
  }

  bool search(int value) {
    if (head == NULL) {
      return false;
    } else {

      Node *tmp = head;
      while (tmp != NULL) {
        if (tmp->data == value) {
          return true;
        }
        tmp = tmp->next;
      }
      return false;
    }
  }
};

int main() {
  List l;

  l.push_front(1);
  l.push_front(2);
  l.push_front(3);
  l.push_back(4);
  l.push_back(5);

  l.display();

  cout << l.size() << endl;

  if (l.search(3)) {
    cout << "found\n";
  }

  return 0;
}
