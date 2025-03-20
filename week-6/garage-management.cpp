#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int d) : data(d), next(NULL) {}
};

class Queue {
  Node *front, *rear;

public:
  Queue() : front(NULL), rear(NULL) {}

  Queue(const Queue &q) : front(NULL), rear(NULL) {
    Node *temp = q.front;
    while (temp != NULL) {
      enqueue(temp->data);
      temp = temp->next;
    }
  }

  void enqueue(int data) {
    Node *temp = new Node(data);
    if (rear == NULL) {
      front = rear = temp;
      return;
    }
    rear->next = temp;
    rear = temp;
  }

  int dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    Node *temp = front;
    int data = front->data;
    front = front->next;
    if (front == NULL)
      rear = NULL;
    delete temp;
    return data;
  }

  bool isEmpty() { return front == NULL; }

  int getFront() {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    return front->data;
  }

  int getRear() {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    return rear->data;
  }
};

class Stack {
  Node *top;

public:
  Stack() : top(NULL) {}

  Stack(const Stack &s) : top(NULL) {
    Node *temp = s.top;
    Stack tempStack;
    while (temp != NULL) {
      tempStack.push(temp->data);
      temp = temp->next;
    }
    // Reverse the order
    while (!tempStack.isEmpty()) {
      push(tempStack.pop());
    }
  }

  void push(int data) {
    Node *temp = new Node(data);
    temp->next = top;
    top = temp;
  }

  int pop() {
    if (isEmpty()) {
      cout << "Stack is empty" << endl;
      return -1;
    }
    Node *temp = top;
    int data = top->data;
    top = top->next;
    delete temp;
    return data;
  }

  bool isEmpty() { return top == NULL; }

  int getTop() {
    if (isEmpty()) {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return top->data;
  }
};

class GarageManagement {
private:
  Queue road;
  Stack garage;

public:
  GarageManagement() {}

  void onRoad(int id) {
    road.enqueue(id);
    cout << "Truck " << id << " is now on road" << endl;
  }

  void enterGarage(int id) {
    bool found = false;
    Queue temp;

    while (!road.isEmpty()) {
      int current = road.dequeue();
      if (current == id) {
        found = true;
        garage.push(id);
        cout << "Truck " << id << " entered the garage" << endl;
      } else {
        temp.enqueue(current);
      }
    }

    // Restore remaining trucks on road
    while (!temp.isEmpty()) {
      road.enqueue(temp.dequeue());
    }

    if (!found) {
      cout << "Truck " << id << " not found on road" << endl;
    }
  }

  void exitGarage(int id) {
    if (garage.isEmpty()) {
      cout << "Garage is empty" << endl;
    }

    if (garage.getTop() == id) {
      garage.pop();
      onRoad(id);
      cout << "Truck " << id << " exited garage" << endl;
    } else {
      cout << "Truck " << id << " not near garage door" << endl;
    }
  }

  void showTruck(string location) {
    if (location == "garage") {
      if (garage.isEmpty()) {
        cout << "Garage is empty" << endl;
        return;
      }
      Stack temp = garage;
      cout << "Trucks in garage (from entrance to back): ";
      while (!temp.isEmpty()) {
        cout << temp.getTop() << " ";
        temp.pop();
      }
      cout << endl;
    } else if (location == "road") {
      if (road.isEmpty()) {
        cout << "Road is empty" << endl;
        return;
      }
      Queue temp = road;
      cout << "Trucks on road: ";
      while (!temp.isEmpty()) {
        cout << temp.getFront() << " ";
        temp.dequeue();
      }
      cout << endl;
    }
  }
};

int main() {
  GarageManagement gm;
  gm.onRoad(1);
  gm.onRoad(2);
  gm.onRoad(3);

  gm.showTruck("road");

  gm.enterGarage(2);
  gm.enterGarage(3);

  gm.showTruck("garage");
  gm.showTruck("road");

  gm.exitGarage(3);

  gm.exitGarage(2);

  gm.showTruck("garage");
  gm.showTruck("road");

  return 0;
}
