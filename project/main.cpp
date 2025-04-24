#include <iomanip>
#include <iostream>

#define WIDTH 10

using namespace std;

// handle input/output operations
class IO {
public:
  static bool confirm(string prompt) { return false; }
};

int main() {
  char option;
  do {
    system("clear");
    cout << "Music Player" << endl;
    cout << string(2 * WIDTH, '=') << endl << endl;

    cout << "Menu" << endl << "0: Exit" << endl << "Enter (0-n): ";
    cin >> option;
  } while (option != '0');
  return 0;
}
