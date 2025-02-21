#include <iostream>
using namespace std;

int main() {
  unsigned rows, cols;

  cout << "Rows: ";
  cin >> rows;
  cout << "Columns: ";
  cin >> cols;

  int first_matrix[rows][cols];
  cout << "Matrix A\n";
  for (unsigned i = 0; i < rows; i++) {
    for (unsigned j = 0; j < cols; j++) {
      cout << "[" << i + 1 << ":" << j << "]: ";
      cin >> first_matrix[i][j];
    }
  }

  int second_matrix[rows][cols];
  cout << "Matrix B\n";
  for (unsigned i = 0; i < rows; i++) {
    for (unsigned j = 0; j < cols; j++) {
      cout << "[" << i + 1 << ":" << j << "]: ";
      cin >> second_matrix[i][j];
    }
  }

  int result_matrix[rows][cols];
  for (unsigned i = 0; i < rows; i++) {
    for (unsigned j = 0; j < cols; j++) {
      result_matrix[i][j] = first_matrix[i][j] + second_matrix[i][j];
    }
  }

  for (unsigned i = 0; i < rows; i++) {
    for (unsigned j = 0; j < cols; j++) {
      cout << result_matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
