// MERGE SORT
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    int i = 0, j = 0, k = low;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    vector<int> v = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(v, 0, v.size() - 1);
    for (int x : v) cout << x << " ";
    cout << "\n";
    return 0;
}