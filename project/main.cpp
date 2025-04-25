#include <iomanip>
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
  Song s;
  cout << "Enter Song ID: ";
  cin >> s.id;
  cin.ignore();
  cout << "Enter Song Name: ";
  getline(cin, s.name);
  cout << "Enter Artist: ";
  getline(cin, s.artist);
  cout << "Enter Album: ";
  getline(cin, s.album);
  cout << "Enter Playtime (in seconds): ";
  cin >> s.playtime;
  return s;
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

  void push(Song s) {
    Node *newNode = new Node(s);
    newNode->next = top;
    top = newNode;
  }

  void pop() {
    if (top == NULL)
      return;
    Node *tmp = top;
    top = top->next;
    delete tmp;
  }

  Song peak() {
    if (top == NULL)
      return Song();
    return top->song;
  }

  unsigned size() {
    unsigned count = 0;
    Node *tmp = top;
    while (tmp != NULL) {
      count++;
      tmp = tmp->next;
    }
    return count;
  }

  void clear() {
    while (top != NULL) {
      pop();
    }
  }

  void display() {
    if (top == NULL) {
      cout << "Stack is empty" << endl;
    } else {
      Node *tmp = top;
      while (tmp != NULL) {
        Song s = tmp->song;
        cout << left << setw(WIDTH) << s.id << setw(WIDTH) << s.name
             << setw(WIDTH) << s.artist << setw(WIDTH) << s.album << setw(WIDTH)
             << s.playtime << endl;
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

  void enqueue(Song s) {
    Node *newNode = new Node(s);
    if (rear == NULL) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  void dequeue() {
    if (front == NULL)
      return;
    Node *tmp = front;
    front = front->next;
    if (front == NULL)
      rear = NULL;
    delete tmp;
  }

  Song peak() {
    if (front == NULL)
      return Song();
    return front->song;
  }

  unsigned size() {
    unsigned count = 0;
    Node *tmp = front;
    while (tmp != NULL) {
      count++;
      tmp = tmp->next;
    }
    return count;
  }

  void display() {
    if (front == NULL) {
      cout << "Queue is empty" << endl;
    } else {
      Node *tmp = front;
      while (tmp != NULL) {
        Song s = tmp->song;
        cout << left << setw(WIDTH) << s.id << setw(WIDTH) << s.name
             << setw(WIDTH) << s.artist << setw(WIDTH) << s.album << setw(WIDTH)
             << s.playtime << endl;
        tmp = tmp->next;
      }
    }
  }
};

class List {
  Node *head;

public:
  List() : head(NULL) {}

  void insertAtHead(Song s) {
    Node *newNode = new Node(s);
    newNode->next = head;
    head = newNode;
  }

  void insertAtMiddle(Song s, unsigned position) {
    if (position == 0 || head == NULL) {
      insertAtHead(s);
      return;
    }
    Node *tmp = head;
    for (unsigned i = 1; i < position && tmp->next != NULL; i++) {
      tmp = tmp->next;
    }
    Node *newNode = new Node(s);
    newNode->next = tmp->next;
    tmp->next = newNode;
  }

  void insertAtTail(Song s) {
    Node *newNode = new Node(s);
    if (head == NULL) {
      head = newNode;
      return;
    }
    Node *tmp = head;
    while (tmp->next != NULL)
      tmp = tmp->next;
    tmp->next = newNode;
  }

  void deleteAtHead() {
    if (head == NULL)
      return;
    Node *tmp = head;
    head = head->next;
    delete tmp;
  }

  void deleteAtMiddle(unsigned position) {
    if (head == NULL || position == 0) {
      deleteAtHead();
      return;
    }
    Node *tmp = head;
    for (unsigned i = 1; i < position && tmp->next->next != NULL; i++) {
      tmp = tmp->next;
    }
    Node *toDelete = tmp->next;
    tmp->next = toDelete->next;
    delete toDelete;
  }

  void deleteAtTail() {
    if (head == NULL || head->next == NULL) {
      deleteAtHead();
      return;
    }
    Node *tmp = head;
    while (tmp->next->next != NULL)
      tmp = tmp->next;
    delete tmp->next;
    tmp->next = NULL;
  }

  unsigned size() {
    unsigned count = 0;
    Node *tmp = head;
    while (tmp != NULL) {
      count++;
      tmp = tmp->next;
    }
    return count;
  }

  void display() {
    if (head == NULL) {
      cout << "List is empty" << endl;
      return;
    }
    Node *tmp = head;
    while (tmp != NULL) {
      Song s = tmp->song;
      cout << left << setw(WIDTH) << s.id << setw(WIDTH) << s.name
           << setw(WIDTH) << s.artist << setw(WIDTH) << s.album << setw(WIDTH)
           << s.playtime << endl;
      tmp = tmp->next;
    }
  }
};

int main() {
  List playlist;
  Stack history;
  Queue queue;

  // Sample songs
  playlist.insertAtTail({1, "Ride", "Twenty One Pilots", "Blurryface", 215});
  playlist.insertAtTail({2, "R U Mine?", "Arctic Monkeys", "AM", 210});
  playlist.insertAtTail(
      {3, "Get Lucky", "Daft Punk", "Random Access Memories", 246});
  playlist.insertAtTail(
      {4, "Stressed Out", "Twenty One Pilots", "Blurryface", 202});
  playlist.insertAtTail({5, "Do I Wanna Know?", "Arctic Monkeys", "AM", 272});

  char option;
  do {
    system("clear");
    cout << "Music Player" << endl;
    cout << string(2 * WIDTH, '=') << endl << endl;

    cout << "Menu" << endl;
    cout << "1: Display Playlist\n2: Add Song to Playlist\n3: Delete Song from "
            "Playlist\n";
    cout << "4: Display History\n5: Add to History\n6: Clear History\n";
    cout << "7: Display Queue\n8: Add to Queue\n9: Dequeue\n";
    cout << "0: Exit" << endl;
    cout << "Enter option: ";
    cin >> option;
    unsigned pos;
    Song s;

    switch (option) {
    case '1':
      playlist.display();
      break;
    case '2':
      s = getSongInfo();
      cout << "Enter position to insert (0 for head): ";
      cin >> pos;
      playlist.insertAtMiddle(s, pos);
      break;
    case '3':
      cout << "Enter position to delete: ";
      cin >> pos;
      playlist.deleteAtMiddle(pos);
      break;
    case '4':
      history.display();
      break;
    case '5':
      s = getSongInfo();
      history.push(s);
      break;
    case '6':
      history.clear();
      break;
    case '7':
      queue.display();
      break;
    case '8':
      s = getSongInfo();
      queue.enqueue(s);
      break;
    case '9':
      queue.dequeue();
      break;
    }
    if (option != '0') {
      cout << "\nPress Enter to continue...";
      cin.ignore();
      cin.get();
    }
  } while (option != '0');
  return 0;
}
