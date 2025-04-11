#include <iostream>
using namespace std;

// LinkedList class template
template <typename T> class LinkedList {
private:
  // Node structure to hold data and pointers to next and previous nodes
  struct Node {
    T data;
    Node *next;
    Node *prev;
  };

  Node *head; // Pointer to the first node in the list
  Node *tail; // Pointer to the last node in the list

public:
  // Constructor initializes an empty list
  LinkedList() : head(nullptr), tail(nullptr) {}

  // Insert a new node at the front of the list
  void insertAtFront(T value) {
    Node *newNode = new Node{value, head, nullptr};
    if (head)
      head->prev = newNode; // Update previous head's prev pointer
    else
      tail = newNode; // If list was empty, new node is also tail
    head = newNode;   // Update head to new node
  }

  // Insert a new node at the given position in the list
  void insertAtMiddle(T value, int position) {
    if (position <= 0) { // Position is invalid or front
      insertAtFront(value);
      return;
    } else if (position >= size()) { // Position is beyond end
      insertAtEnd(value);
      return;
    }

    Node *temp = head;
    // Traverse to the node just before the target position
    for (int i = 0; i < position - 1; ++i) {
      temp = temp->next;
    }

    // Create new node and adjust pointers
    Node *newNode = new Node{value, temp->next, temp};
    temp->next->prev = newNode;
    temp->next = newNode;
  }

  // Insert a new node at the end of the list
  void insertAtEnd(T value) {
    Node *newNode = new Node{value, nullptr, tail};
    if (!head) {
      head = tail = newNode; // Empty list
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // Delete the node at the front of the list
  void deleteAtFront() {
    if (!head)
      return; // Empty list

    Node *temp = head;
    head = head->next;
    if (head)
      head->prev = nullptr;
    else
      tail = nullptr; // List becomes empty
    delete temp;
  }

  // Delete the node at the given position
  void deleteAtMiddle(int position) {
    if (!head || position < 0 || position >= size())
      return; // Invalid position or empty list

    if (position == 0) {
      deleteAtFront();
      return;
    }

    Node *temp = head;
    // Traverse to the node at the target position
    for (int i = 0; i < position; ++i) {
      temp = temp->next;
    }

    // Adjust surrounding nodes' pointers
    if (temp->prev)
      temp->prev->next = temp->next;
    if (temp->next)
      temp->next->prev = temp->prev;
    if (temp == tail)
      tail = temp->prev; // Update tail if needed

    delete temp;
  }

  // Delete the node at the end of the list
  void deleteAtEnd() {
    if (!tail)
      return; // Empty list

    Node *temp = tail;
    tail = tail->prev;
    if (tail)
      tail->next = nullptr;
    else
      head = nullptr; // List becomes empty
    delete temp;
  }

  // Display the contents of the list
  void display() {
    Node *temp = head;
    while (temp) {
      cout << temp->data << " <-> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  // Return the number of nodes in the list
  int size() {
    int count = 0;
    Node *temp = head;
    while (temp) {
      ++count;
      temp = temp->next;
    }
    return count;
  }
};

int main() {
  LinkedList<int> list;
  while (true) {
    int choice, value, position;
    // Display menu options
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
