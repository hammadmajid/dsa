#include <iostream>
using namespace std;
#define SIZE 5

int A[SIZE];
int front = -1;
int rear = -1;

// Function to check if queue is empty or not
bool isempty() {
  if (front == -1 && rear == -1)
    return true;
  else
    return false;
}

// function to enter elements in queue
void enqueue(int value) {

  // queue is full
  if ((rear + 1) % SIZE == front)
    cout << "Queue is full \n";

  // insert in queue
  else {
    // first element inserted
    if (front == -1)
      front = 0;
    // insert element at rear
    rear = (rear + 1) % SIZE;
    A[rear] = value;
  }
}

// function to delete/remove element from queue
void dequeue() {
  if (isempty())
    cout << "Queue is empty\n";
  else

    // only one element
    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % SIZE;
}

// function to show the element at front
void showfront() {
  if (isempty())
    cout << "Queue is empty\n";
  else
    cout << "element at front is:" << A[front];
}

// function to display queue
void displayQueue() {
  if (isempty())
    cout << "Queue is empty\n";
  else {
    int i;
    if (front <= rear) {
      for (i = front; i <= rear; i++)
        cout << A[i] << " ";
    } else {
      i = front;
      while (i < 5) {
        cout << A[i] << " ";
        i++;
      }
      i = 0;
      while (i <= rear) {
        cout << A[i] << " ";
        i++;
      }
    }
  }
}

// Main Function
int main() {
  int choice, flag = 1, value;
  while (flag == 1) {
    cout << "1.Enqueue \n2.Dequeue \n3.Show Front \n4.Display Queue \n5.Exit\n";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter Value:\n";
      cin >> value;
      enqueue(value);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      showfront();
      break;
    case 4:
      displayQueue();
      break;
    case 5:
      flag = 0;
      break;
    }
  }

  return 0;
}
