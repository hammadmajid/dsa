#include <iomanip>
#include <iostream>
using namespace std;

void print_matrix(int m[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << setw(3) << m[i][j];
    }
    cout << endl;
  }
}

int main(int argc, char **argv) {
  int matrix_a[3][3];

  cout << "Enter Matrix A: " << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> matrix_a[i][j];
    }
  }

  cout << "Matrix A:" << endl;
  print_matrix(matrix_a);

  int matrix_b[3][3];

  cout << endl << "Enter Matrix B: " << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> matrix_b[i][j];
    }
  }

  cout << endl << "Matrix B:" << endl;
  print_matrix(matrix_b);

  int result_matrix[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      result_matrix[i][j] = matrix_a[i][j] * matrix_b[i][j];
    }
  }

  cout << endl << "Result Matrix:" << endl;
  print_matrix(result_matrix);

  return 0;
}
