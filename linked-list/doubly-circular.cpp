#include <iostream>
using namespace std;

// Doubly Circular LinkedList class template
template <typename T> class LinkedList {
private:
  // Node structure with next and prev pointers
  struct Node {
    T data;
    Node *next;
    Node *prev;
  };

  Node *head; // Pointer to the head (start) of the list

public:
  // Constructor to initialize an empty list
  LinkedList() : head(nullptr) {}

  // Insert a new node at the front
  void insertAtFront(T value) {
    Node *newNode = new Node{value, nullptr, nullptr};
    if (!head) {
      newNode->next = newNode->prev = newNode;
      head = newNode;
    } else {
      Node *tail = head->prev;
      newNode->next = head;
      newNode->prev = tail;
      head->prev = newNode;
      tail->next = newNode;
      head = newNode;
    }
  }

  // Insert a new node at the specified position
  void insertAtMiddle(T value, int position) {
    if (position <= 0 || !head) {
      insertAtFront(value);
      return;
    } else if (position >= size()) {
      insertAtEnd(value);
      return;
    }

    Node *temp = head;
    for (int i = 0; i < position - 1; ++i) {
      temp = temp->next;
    }

    Node *newNode = new Node{value, temp->next, temp};
    temp->next->prev = newNode;
    temp->next = newNode;
  }

  // Insert a new node at the end
  void insertAtEnd(T value) {
    if (!head) {
      insertAtFront(value);
      return;
    }

    Node *tail = head->prev;
    Node *newNode = new Node{value, head, tail};
    tail->next = newNode;
    head->prev = newNode;
  }

  // Delete the node at the front
  void deleteAtFront() {
    if (!head)
      return;

    if (head->next == head) {
      delete head;
      head = nullptr;
      return;
    }

    Node *tail = head->prev;
    Node *temp = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete temp;
  }

  // Delete the node at a specified position
  void deleteAtMiddle(int position) {
    if (!head || position < 0 || position >= size())
      return;

    if (position == 0) {
      deleteAtFront();
      return;
    }

    Node *temp = head;
    for (int i = 0; i < position; ++i) {
      temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
  }

  // Delete the node at the end
  void deleteAtEnd() {
    if (!head)
      return;

    if (head->next == head) {
      delete head;
      head = nullptr;
      return;
    }

    Node *tail = head->prev;
    tail->prev->next = head;
    head->prev = tail->prev;
    delete tail;
  }

  // Display the list
  void display() {
    if (!head) {
      cout << "List is empty" << endl;
      return;
    }

    Node *temp = head;
    do {
      cout << temp->data << " <-> ";
      temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
  }

  // Return size of the list
  int size() {
    if (!head)
      return 0;
    int count = 0;
    Node *temp = head;
    do {
      ++count;
      temp = temp->next;
    } while (temp != head);
    return count;
  }
};

int main() {
  LinkedList<int> list;
  while (true) {
    int choice, value, position;
    cout << "\nChoose an operation:\n";
    cout << "1. Insert at front\n";
    cout << "2. Insert at middle\n";
    cout << "3. Insert at end\n";
    cout << "4. Delete at front\n";
    cout << "5. Delete at middle\n";
    cout << "6. Delete at end\n";
    cout << "7. Display list\n";
    cout << "8. Get size\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value: ";
      cin >> value;
      list.insertAtFront(value);
      break;
    case 2:
      cout << "Enter value: ";
      cin >> value;
      cout << "Enter position: ";
      cin >> position;
      list.insertAtMiddle(value, position);
      break;
    case 3:
      cout << "Enter value: ";
      cin >> value;
      list.insertAtEnd(value);
      break;
    case 4:
      list.deleteAtFront();
      break;
    case 5:
      cout << "Enter position: ";
      cin >> position;
      list.deleteAtMiddle(position);
      break;
    case 6:
      list.deleteAtEnd();
      break;
    case 7:
      list.display();
      break;
    case 8:
      cout << "Size: " << list.size() << endl;
      break;
    case 9:
      return 0;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  }
}

