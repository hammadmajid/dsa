#include <iostream>

int main(int argc, char *argv[]) {
  int size;

  std::cout << "Enter array size: ";
  std::cin >> size;

  int arr[size];
  int sum = 0;

  for (int i = 0; i < size; i++) {
    std::cout << "Enter element " << i << ": ";
    std::cin >> arr[i];
  }

  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  std::cout << "Average: " << float(sum) / size << std::endl;

  return 0;
}
