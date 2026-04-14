#include <bits/stdc++.h>
using namespace std;

// Recursive function
void findMinMax(int arr[], int index, int n, int &min_val, int &max_val) {
    
    // Base case: if index reaches end
    if (index == n) {
        return;
    }

    // Update min and max
    if (arr[index] < min_val) {
        min_val = arr[index];
    }
    if (arr[index] > max_val) {
        max_val = arr[index];
    }

    // Recursive call for next element
    findMinMax(arr, index + 1, n, min_val, max_val);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min_val = arr[0];
    int max_val = arr[0];

    // Call recursive function starting from index 0
    findMinMax(arr, 0, n, min_val, max_val);

    cout << "Minimum value: " << min_val << endl;
    cout << "Maximum value: " << max_val << endl;

    return 0;
}