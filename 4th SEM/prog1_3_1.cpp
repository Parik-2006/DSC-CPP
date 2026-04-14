#include <iostream>
using namespace std;

// Recursive function
int binarySearch(int arr[], int low, int high, int key) {
    
    // Base case: element not found
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    // If found
    if (arr[mid] == key) {
        return mid;
    }
    // Search right half
    else if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, high, key);
    }
    // Search left half
    else {
        return binarySearch(arr, low, mid - 1, key);
    }
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter key: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}