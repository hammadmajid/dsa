#include <iomanip> // use setw for pretty printing
#include <iostream>

#define WIDTH 10

using namespace std;

struct Song {
  int id;
  string name;
  string artist;
  string album;
  unsigned playtime;
};

Song getSongInfo() {
  // TODO: ask user about song info
}

class Node {
public:
  Song song;
  Node *next;

  Node() { next = NULL; }

  Node(Song s) {
    this->song = s;
    next = NULL;
  }
};

class Stack {
  Node *top;

public:
  Stack() : top(NULL) {}

  void push() {
    // TODO: implement
  }

  void pop() {
    // TODO: implement
  }

  Song peak() {
    // TODO: implement
    return top->song;
  }

  unsigned size() {
    // TODO: implement
    return 1;
  }

  void clear() {
    // call pop() until stack is empty
  }

  void display() {
    if (top == NULL) {
      cout << "Stack is empty" << endl;
    } else {

      Node *tmp = top;

      while (tmp != NULL) {
        cout << tmp->song.id << endl;

        // TODO: pretty print

        tmp = tmp->next;
      }
    }
  }
};

class Queue {
  Node *front;
  Node *rear;

public:
  Queue() : front(NULL), rear(NULL) {}

  void enqueue(Song s);

  void dequeue();
  Song peak();
  unsigned size();
  void display() {
    if (front == NULL) {
      cout << "Stack is empty" << endl;
    } else {

      Node *tmp = front;

      while (tmp != NULL) {
        cout << tmp->song.id << endl;

        // TODO: pretty print

        tmp = tmp->next;
      }
    }
  }
};

class List {
  Node *head;

public:
  List() : head(NULL) {}

  void insertAtHead(Song s);
  void insertAtMiddle(Song s, unsigned position);
  void insertAtTail(Song s);

  void deleteAtHead();
  void deleteAtMiddle(unsigned position);
  void deleteAtTail();

  unsigned size();

  void display();
};

int main() {
  List playlist; // create list with at least 5 song already in it, use artist
                 // like twenty one pilot, artic monkeys, daft punk etc
  Stack history;
  Queue queue;
  char option;

  do {
    system("clear");
    cout << "Music Player" << endl;
    cout << string(2 * WIDTH, '=') << endl << endl;

    cout << "Menu" << endl << "0: Exit" << endl << "Enter (0-n): ";
    // TODO: add options for adding new song to list(ask position)
    // add option for asking to delete from list(ask position)
    // add option to push song to history or delete entire history
    // add option to add song to queue or dequeue
    cin >> option;
  } while (option != '0');
  return 0;
}
