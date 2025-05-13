#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;

    // Find the index of the minimum element in the remaining array
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }

    // Swap the found minimum element with the first element
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
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

  // Perform Selection Sort
  selectionSort(arr1, n);
  cout << "\nArray after Selection Sort:\n";
  printArray(arr1, n);

  return 0;
}
