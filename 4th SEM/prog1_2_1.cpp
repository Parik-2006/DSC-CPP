#include <bits/stdc++.h>
using namespace std;

// Recursive function
int linearSearch(int arr[], int n, int index, int key) {
    
    // Base case: reached end → not found
    if (index == n) {
        return -1;
    }

    // If element found
    if (arr[index] == key) {
        return index;
    }

    // Recursive call for next index
    return linearSearch(arr, n, index + 1, key);
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter key to search: ";
    cin >> key;

    int result = linearSearch(arr, n, 0, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}