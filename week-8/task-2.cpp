#include <iostream>
using namespace std;

int main() {
    int n, num;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];

    cout << "Enter " << n << " sorted numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter number to search: ";
    cin >> num;

    int low = 0, high = n - 1, mid, found = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == num) {
            cout << "Number found at position " << mid << endl;
            found = 1;
            break;
        } else if (arr[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (!found)
        cout << "Number not found.\n";

    return 0;
}
