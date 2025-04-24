#include <iostream>
using namespace std;

// Maximum number of elements in the queue
const int MAX_SIZE = 100;

// Global queue array and front/rear pointers
int queue[MAX_SIZE]; // Queue storage
int front = -1,
    rear = -1; // Initially, both front and rear are -1 (queue is empty)

// Function to check if the queue is full
bool isFull() {
  // The queue is full when moving rear forward would overlap with front
  return (rear + 1) % MAX_SIZE == front;
}

// Function to check if the queue is empty
bool isEmpty() {
  // Queue is empty if front is still -1
  return front == -1;
}

// Function to add an element to the queue (enqueue operation)
void enqueue(int value) {
  if (isFull()) {
    cout << "Queue Overflow" << endl; // Cannot add more elements
    return;
  }

  // If queue is empty, we need to set front to 0
  if (isEmpty())
    front = 0;

  // Move rear forward circularly using modulo (wrap around if needed)
  rear = (rear + 1) % MAX_SIZE;
  queue[rear] = value; // Store value at new rear position
}

// Function to remove an element from the queue (dequeue operation)
void dequeue() {
  if (isEmpty()) {
    cout << "Queue Underflow" << endl; // No elements to remove
    return;
  }

  // If there is only one element, reset queue to empty state
  if (front == rear) {
    front = rear = -1;
  } else {
    // Move front forward circularly using modulo (wrap around if needed)
    front = (front + 1) % MAX_SIZE;
  }
}

// Function to get the front element without removing it
int peek() {
  if (isEmpty()) {
    cout << "Queue is Empty" << endl;
    return -1; // Return invalid value
  }
  return queue[front]; // Return front element
}

// Function to display the queue elements
void display() {
  if (isEmpty()) {
    cout << "Queue is Empty" << endl;
    return;
  }
  cout << "Queue elements: ";

  int i = front;
  while (true) {
    cout << queue[i] << " "; // Print current element
    if (i == rear)
      break;                // Stop when we reach rear
    i = (i + 1) % MAX_SIZE; // Move to next element circularly
  }
  cout << endl;
}

// Main function to demonstrate queue operations
int main() {
  // Step 1: Add elements to the queue
  enqueue(10); // Queue: [10]
  enqueue(20); // Queue: [10, 20]
  enqueue(30); // Queue: [10, 20, 30]

  display(); // Output: Queue elements: 10 20 30

  // Step 2: Get the front element
  cout << "Front element: " << peek() << endl; // Output: Front element: 10

  // Step 3: Remove an element from the queue
  dequeue(); // Removes 10, Queue: [20, 30]

  display(); // Output: Queue elements: 20 30

  return 0;
}
