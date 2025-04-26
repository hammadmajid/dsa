#include <iostream>
using namespace std;

int main() {
    int n, num, found = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100]; // assuming max 100 elements

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter number to search: ";
    cin >> num;

    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            cout << "Number found at position " << i << endl;
            found = 1;
            break;
        }
    }

    if (!found)
        cout << "Number not found.\n";

    return 0;
}
