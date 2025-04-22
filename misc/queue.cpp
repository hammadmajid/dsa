#include <iostream>
using namespace std;

// Node structure
struct Node {
  int data;
  Node *next;
};

// Queue class
class Queue {
private:
  Node *front;
  Node *rear;

public:
  Queue() { front = rear = nullptr; }

  // Enqueue operation
  void enqueue(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    if (rear == nullptr) {
      front = rear = newNode;
      return;
    }
    rear->next = newNode;
    rear = newNode;
  }

  // Dequeue operation
  void dequeue() {
    if (front == nullptr) {
      cout << "Queue is empty.\n";
      return;
    }
    Node *temp = front;
    front = front->next;

    // If front becomes NULL, then change rear also
    if (front == nullptr)
      rear = nullptr;

    delete temp;
  }

  // Display the queue
  void display() {
    if (front == nullptr) {
      cout << "Queue is empty.\n";
      return;
    }
    Node *temp = front;
    cout << "Queue: ";
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "\n";
  }

  // Destructor to clean up memory
  ~Queue() {
    while (front != nullptr) {
      dequeue();
    }
  }
};

// Main function
int main() {
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  q.display();

  q.dequeue();
  q.display();

  q.dequeue();
  q.dequeue();
  q.dequeue(); // Attempt to dequeue from empty queue

  return 0;
}
