#include <iostream>
using namespace std;

int countOnes(int n) {
    if (n == 0)
        return 0;
    return (n % 2) + countOnes(n / 2);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Number of 1s in binary: " << countOnes(n) << endl;

    return 0;
}
