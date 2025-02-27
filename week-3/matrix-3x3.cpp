#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  int rows = 3, cols = 3;

  int matrix_a[rows][cols];
  cout << "Matrix A\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << "[" << i + 1 << ":" << j + 1 << "]: ";
      cin >> matrix_a[i][j];
    }
  }

  int matrix_b[rows][cols];
  cout << "Matrix B\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << "[" << i + 1 << ":" << j + 1 << "]: ";
      cin >> matrix_b[i][j];
    }
  }

  int result_matrix[rows][cols];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result_matrix[i][j] = matrix_a[i][j] * matrix_b[i][j];
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << result_matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
