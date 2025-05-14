#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// Heapify for Max-Heap
void maxHeapify(int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;
  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    maxHeapify(arr, n, largest);
  }
}

// Heap sort using Max-Heap (descending)
void heapSortMax(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    maxHeapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    maxHeapify(arr, i, 0);
  }
}

// Heapify for Min-Heap
void minHeapify(int arr[], int n, int i) {
  int smallest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] < arr[smallest])
    smallest = l;
  if (r < n && arr[r] < arr[smallest])
    smallest = r;

  if (smallest != i) {
    swap(arr[i], arr[smallest]);
    minHeapify(arr, n, smallest);
  }
}

// Heap sort using Min-Heap (ascending)
void heapSortMin(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    minHeapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    minHeapify(arr, i, 0);
  }
}

// Utility to print array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Example usage
int main() {
  int arr1[] = {4, 10, 3, 5, 1};
  int n1 = 5;
  heapSortMax(arr1, n1); // descending
  printArray(arr1, n1);

  int arr2[] = {4, 10, 3, 5, 1};
  int n2 = 5;
  heapSortMin(arr2, n2); // ascending
  printArray(arr2, n2);

  return 0;
}
