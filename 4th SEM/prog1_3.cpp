// Binary Search 
// Iterative 
#include <iostream>
using namespace std;

int main() {
    int i, n, key;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements (sorted): ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            found = true;
            cout << "Element found at index: " << mid << endl;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}