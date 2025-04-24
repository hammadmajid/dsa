#include <iostream>
using namespace std;

int binarySearch(int arr[], int nsize, int target) {
    int low = 0;
    int high = nsize - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    const int n = 10;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target;
    cout << "Enter target: ";
    cin >> target;
    cout << binarySearch(arr, n, target) << endl;
    return 0;
}
