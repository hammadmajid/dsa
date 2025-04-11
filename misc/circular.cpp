#include <iostream>
using namespace std;

// CircularLinkedList class template
template <typename T> class CircularLinkedList {
private:
  // Node structure
  struct Node {
    T data;     // Data part of the node
    Node *next; // Pointer to the next node
  };

  Node *head; // Pointer to the first node (head) in the list

public:
  // Constructor to initialize an empty list
  CircularLinkedList() : head(nullptr) {}

  // Insert a node at the front of the list
  void insertAtFront(T value) {
    Node *newNode = new Node{value, nullptr};
    if (!head) {
      // If list is empty, point newNode to itself
      newNode->next = newNode;
      head = newNode;
    } else {
      Node *temp = head;
      // Traverse to the last node
      while (temp->next != head)
        temp = temp->next;
      // Insert newNode at the beginning
      newNode->next = head;
      temp->next = newNode;
      head = newNode; // Update head to new node
    }
  }

  // Insert a node at a specific middle position
  void insertAtMiddle(T value, int position) {
    if (position <= 0) {
      insertAtFront(value); // Insert at front for position <= 0
      return;
    } else if (position >= size()) {
      insertAtEnd(value); // Insert at end if position is beyond size
      return;
    }
    Node *newNode = new Node{value, nullptr};
    Node *temp = head;
    // Traverse to the node before the desired position
    for (int i = 1; i < position; ++i)
      temp = temp->next;
    // Insert newNode between temp and temp->next
    newNode->next = temp->next;
    temp->next = newNode;
  }

  // Insert a node at the end of the list
  void insertAtEnd(T value) {
    Node *newNode = new Node{value, nullptr};
    if (!head) {
      // If list is empty, point newNode to itself
      newNode->next = newNode;
      head = newNode;
    } else {
      Node *temp = head;
      // Traverse to the last node
      while (temp->next != head)
        temp = temp->next;
      // Link the new node at the end
      temp->next = newNode;
      newNode->next = head; // Make it circular
    }
  }

  // Delete the front node of the list
  void deleteAtFront() {
    if (!head)
      return; // Do nothing if list is empty
    if (head->next == head) {
      // Only one node in the list
      delete head;
      head = nullptr;
    } else {
      Node *temp = head;
      // Find the last node
      while (temp->next != head)
        temp = temp->next;
      Node *toDelete = head;
      head = head->next; // Move head to the next node
      temp->next = head; // Update last node to point to new head
      delete toDelete;   // Delete old head
    }
  }

  // Delete a node from a specific middle position
  void deleteAtMiddle(int position) {
    if (!head || position < 0 || position >= size())
      return; // Invalid position
    if (position == 0) {
      deleteAtFront(); // Delegate to deleteAtFront
      return;
    }
    Node *temp = head;
    // Traverse to the node before the one to delete
    for (int i = 1; i < position; ++i)
      temp = temp->next;
    Node *toDelete = temp->next; // Node to delete
    temp->next = toDelete->next; // Bridge the gap
    delete toDelete;             // Delete node
  }

  // Delete the last node in the list
  void deleteAtEnd() {
    if (!head)
      return; // Do nothing if list is empty
    if (head->next == head) {
      // Only one node
      delete head;
      head = nullptr;
    } else {
      Node *temp = head;
      // Traverse to the second last node
      while (temp->next->next != head)
        temp = temp->next;
      delete temp->next; // Delete last node
      temp->next = head; // Update link to head
    }
  }

  // Display the contents of the list
  void display() {
    if (!head) {
      cout << "List is empty" << endl;
      return;
    }
    Node *temp = head;
    do {
      cout << temp->data << " -> ";
      temp = temp->next;
    } while (temp != head); // Loop until back to head
    cout << "(back to head)" << endl;
  }

  // Get the size (number of nodes) in the list
  int size() {
    if (!head)
      return 0;
    int count = 0;
    Node *temp = head;
    do {
      count++;
      temp = temp->next;
    } while (temp != head); // Count until loop returns to head
    return count;
  }
};

int main() {
  CircularLinkedList<int> list;
  while (true) {
    int choice, value, position;
    // Menu for user interaction
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
