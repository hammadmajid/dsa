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

int recursiveLinearSearch(int arr[], int size, int target, int indices[],
                          int current = 0, int count = 0) {
  if (current == size) {
    return count; // base case: end of array
  }

  if (arr[current] == target) {
    indices[count++] = current; // store index if target found
  }

  return recursiveLinearSearch(arr, size, target, indices, current + 1, count);
}

int main() {
  int arr[] = {3, 5, 3, 7, 3, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 3;

  int indices[100]; // assuming max 100 occurrences
  int count = linearSearch(arr, size, target, indices);

  cout << "Linear Search" << endl;
  cout << "Element " << target << " occurs " << count << " times at indices: ";
  for (int i = 0; i < count; ++i) {
    cout << indices[i] << " ";
  }
  cout << endl << "Recursive search" << endl;

  int rcount = recursiveLinearSearch(arr, size, target, indices);
  cout << "Element " << target << " occurs " << count << " times at indices: ";
  for (int i = 0; i < count; ++i) {
    cout << indices[i] << " ";
  }

  cout << endl;

  return 0;
}
