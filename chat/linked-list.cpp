#include <iostream>
using namespace std;

// LinkedList class template
class LinkedList {
private:
  // Node structure template
  struct Node {
    int data;
    Node *next;
  };

  Node *head; // Pointer to the first node in the list

public:
  LinkedList() : head(NULL) {} // Constructor initializes an empty list

  // Insert at front
  void insertAtFront(int value) {
    Node *newNode = new Node; // Create a new node
    newNode->data = value;
    newNode->next = head; // Point new node to current head
    head = newNode;       // Update head to new node
  }

  // Insert at middle
  void insertAtMiddle(int value, int position) {
    if (position <= 0) { // If position is invalid or 0, insert at front
      insertAtFront(value);
      return;
    } else if (position >=
               size()) { // If position is beyond list size, insert at end
      insertAtEnd(value);
      return;
    }
    Node *newNode = new Node;
    newNode->data = value;
    Node *temp = head;
    for (int i = 1; i < position;
         i++) { // intraverse to the node before insertion point
      temp = temp->next;
    }
    newNode->next = temp->next; // Point new node to the next node
    temp->next = newNode;       // Link previous node to new node
  }

  // Insert at end
  void insertAtEnd(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (!head) { // If list is empty, new node becomes head
      head = newNode;
    } else {
      Node *temp = head;
      while (temp->next) { // intraverse to the last node
        temp = temp->next;
      }
      temp->next = newNode; // Link last node to new node
    }
  }

  // Delete at front
  void deleteAtFront() {
    if (!head)
      return; // If list is empty, do nothing
    Node *temp = head;
    head = head->next; // Move head to next node
    delete temp;       // Free memory
  }

  // Delete at middle
  void deleteAtMiddle(int position) {
    if (!head || position < 0 || position >= size())
      return;            // If invalid position, do nothing
    if (position == 0) { // If deleting first node, call deleteAtFront
      deleteAtFront();
      return;
    }
    Node *temp = head;
    for (int i = 1; i < position;
         i++) { // intraverse to the node before deletion point
      temp = temp->next;
    }
    Node *nodeintoDelete = temp->next; // Node to be deleted
    temp->next = nodeintoDelete->next; // Link previous node to next node
    delete nodeintoDelete;             // Free memory
  }

  // Delete at end
  void deleteAtEnd() {
    if (!head)
      return;          // If list is empty, do nothing
    if (!head->next) { // If only one node exists, delete head
      delete head;
      head = NULL;
    } else {
      Node *temp = head;
      while (temp->next->next) { // intraverse to second-last node
        temp = temp->next;
      }
      delete temp->next;    // Delete last node
      temp->next = NULL; // Update second-last node's next pointer
    }
  }

  // Display the list
  void display() {
    Node *temp = head;
    while (temp) { // intraverse and print each node
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  // Get the size of the list
  int size() {
    int count = 0;
    Node *temp = head;
    while (temp) { // intraverse the list to count nodes
      count++;
      temp = temp->next;
    }
    return count;
  }
};

int main() {
  LinkedList list;
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
