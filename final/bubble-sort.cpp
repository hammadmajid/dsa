#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    // Last i elements are already sorted
    for (int j = 0; j < n - i - 1; j++) {
      // Swap if the current element is greater than the next
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Function to print the array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr1[] = {64, 25, 12, 22, 11};
  int arr2[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr1) / sizeof(arr1[0]);

  cout << "Original array:\n";
  printArray(arr1, n);

  // Perform Bubble Sort
  bubbleSort(arr2, n);
  cout << "\nArray after Bubble Sort:\n";
  printArray(arr2, n);

  return 0;
}
