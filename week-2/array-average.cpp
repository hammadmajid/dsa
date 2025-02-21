#include <iostream>

int main(int argc, char *argv[]) {
  unsigned size;

  std::cout << "Enter array size: ";
  std::cin >> size;

  int arr[size];
  int sum;

  for (int i = 0; i < size; i++) {
    std::cout << "Enter element " << i << ": ";
    std::cin >> arr[i];
  }

  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  std::cout << "Sum of all elements: " << sum << std::endl;

  return 0;
}
