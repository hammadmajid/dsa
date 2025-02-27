#include <iomanip>
#include <iostream>
using namespace std; // make definations in std namespace availbe

int main() {
  int n[10]; // initalize array of 10 integers

  for (int i = 0; i < 10; i++) {
    n[i] = i + 100; // declare array with i + 100 value
  }

  cout << "Element" << setw(13) << "Value" << endl;

  for (int i = 0; i < 10; i++) {
    // output each element with its value
    cout << setw(7) << i << setw(13) << n[i] << endl;
  }

  return 0; // return with exit code 0
}
