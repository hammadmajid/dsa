#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, sum = 0;
    cout << "Enter number of terms: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        sum += fibonacci(i);
    }

    cout << "Sum of Fibonacci series = " << sum << endl;
    return 0;
}
