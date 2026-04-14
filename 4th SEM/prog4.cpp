/*
SIMPLE QUICK SORT (Pivot = Starting Element)

#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low + 1, j = high;
        while (i <= j) {
            while (i <= high && arr[i] <= pivot) i++;
            while (arr[j] > pivot) j--;
            if (i < j) swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
*/
// QUICK SORT
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];   // last element as pivot
    int i = low - 1;         // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);    // left of pivot
        quickSort(arr, pi + 1, high);   // right of pivot
    }
}

int main() {
    vector<int> v = {10, 7, 8, 9, 1, 5};
    quickSort(v, 0, v.size() - 1);
    for (int x : v) cout << x << " ";
    cout << "\n";
    return 0;
}