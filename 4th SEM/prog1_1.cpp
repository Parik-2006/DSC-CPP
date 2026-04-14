// Find Minimum and Maximum of the array
#include <bits/stdc++.h>
using namespace std;

// ITERATIVE APPROACH
int main() {
    int i, n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min_val = arr[0];
    int max_val = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }


    cout << "Minimum value: " << min_val << endl;
    cout << "Maximum value: " << max_val << endl;

    return 0;
}


