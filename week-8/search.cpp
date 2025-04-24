#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target, int indices[]) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == target) {
      indices[count++] = i;
    }
  }
  return count;
}

int main() {
  int arr[] = {3, 5, 3, 7, 3, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target;
  int occurrence;

  cout << "Enter the number to search for: ";
  cin >> target;

  cout << "Which occurrence do you want to print? (1 for first, 2 for second, ...): ";
  cin >> occurrence;

  int indices[100]; // max 100 occurrences

  int count = linearSearch(arr, size, target, indices);

  cout << "\nLinear Search:\n";
  if (occurrence <= count && occurrence > 0) {
    cout << "The " << occurrence << " occurrence of " << target
         << " is at index: " << indices[occurrence - 1] << endl;
  } else {
    cout << "The " << occurrence << " occurrence of " << target << " was not found.\n";
  }

  return 0;
}
