#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
  int low = 0, high = size - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 7;
  int index = binarySearch(arr, size, target);
  cout << "Index: " << index << endl;
  return 0;
}
