#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];

    cout << "Enter circularly sorted numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min_index])
            min_index = i;
    }

    cout << "The array is rotated " << min_index << " times." << endl;

    return 0;
}
