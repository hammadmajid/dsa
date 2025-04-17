#include <iostream>
using namespace std;

const int INT_MIN = 10;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Stack class implemented using linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = top;
        top = temp;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return value;
        }
    }

    int peek() {
        if (isEmpty())
            return -1;
        return top->data;
    }

    void display(const string& name) {
        cout << "Stack " << name << ": ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Move a disk between two poles using the rules
void moveDisk(Stack& src, Stack& dest, const string& s, const string& d) {
    int pole1TopDisk = src.isEmpty() ? INT_MIN : src.peek();
    int pole2TopDisk = dest.isEmpty() ? INT_MIN : dest.peek();

    if (pole1TopDisk == INT_MIN) {
        src.push(dest.pop());
        cout << "Move disk " << src.peek() << " from " << d << " to " << s << endl;
    } else if (pole2TopDisk == INT_MIN) {
        dest.push(src.pop());
        cout << "Move disk " << dest.peek() << " from " << s << " to " << d << endl;
    } else if (pole1TopDisk > pole2TopDisk) {
        src.push(dest.pop());
        cout << "Move disk " << src.peek() << " from " << d << " to " << s << endl;
    } else {
        dest.push(src.pop());
        cout << "Move disk " << dest.peek() << " from " << s << " to " << d << endl;
    }
}

// Iterative Tower of Hanoi using stacks
void towerOfHanoi(int n, Stack& src, Stack& aux, Stack& dest) {
    string s = "A", a = "B", d = "C";

    int totalMoves = (1 << n) - 1;

    // Larger disks pushed first
    for (int i = n; i >= 1; i--)
        src.push(i);

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1)
            moveDisk(src, dest, s, d);
        else if (i % 3 == 2)
            moveDisk(src, aux, s, a);
        else if (i % 3 == 3)
            moveDisk(aux, dest, a, d);
    }
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    Stack src, aux, dest;

    towerOfHanoi(n, src, aux, dest);

    return 0;
}

