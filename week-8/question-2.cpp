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

    cout << "Enter number: ";
    cin >> num;

    int floor = -1, ceil = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= num)
            floor = arr[i];
        if (arr[i] >= num && ceil == -1)
            ceil = arr[i];
    }

    cout << "Floor: " << (floor == -1 ? -1 : floor) << endl;
    cout << "Ceil: " << (ceil == -1 ? -1 : ceil) << endl;

    return 0;
}
