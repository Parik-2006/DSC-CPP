// to check if an integer array is palindrome or not
#include <bits/stdc++.h>
using namespace std;

void reverse(int i, int arr[], int n){
    if(i >= n/2) return;
    swap(arr[i], arr[n-i-1]);
    reverse(i+1, arr, n);
}

bool palindrome(int arr[], int result[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] != result[i])
            return false;
    }
    return true;
}


int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    int result[n];
    cout << "Enter the contents to the array: ";
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
        result[i] = arr[i];
    }
    reverse(0, arr, n);
    cout << "Contents to the array after reversing: ";
    for(int i = 0; i<n; i++) cout << arr[i] << " ";

    if(palindrome(arr, result, n)) cout << endl << "Palindrome array!!" << endl;
    else cout << endl << "Not a Palindrome array!!" << endl;
    return 0;
}