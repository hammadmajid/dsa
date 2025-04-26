#include <iostream>
using namespace std;

int main() {
    int n, num;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];

    cout << "Enter sorted numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter number to find: ";
    cin >> num;

    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    if (first != -1)
        cout << "First occurrence at " << first << ", Last occurrence at " << last << endl;
    else
        cout << "Number not found.\n";

    return 0;
}
