/*
 * Write a program to calculate sum of two arrays. Prompt the user for the size
 * of the array and then prompt them for each value. Calculate the sum and print
 * the final array.
 */

#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  unsigned size;

  cout << "Enter size: ";
  cin >> size;

  int part_a[size];
  for (int i = 0; i < size; i++) {
    cout << "Array A:" << i << " ";
    cin >> part_a[i];
  }

  int part_b[size];
  for (int i = 0; i < size; i++) {
    cout << "Array B:" << i << " ";
    cin >> part_b[i];
  }

  int sum[size];
  for (int i = 0; i < size; i++) {
    sum[i] = part_a[i] + part_b[i];
  }

  for (int i = 0; i < size; i++) {
    cout << sum[i] << " ";
  }

  return 0;
}
