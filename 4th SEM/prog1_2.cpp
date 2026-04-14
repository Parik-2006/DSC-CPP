// Linear Search 
// ITERATIVE APPROACH 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, n, key;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    bool found = false;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Element found at index: " << i << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}