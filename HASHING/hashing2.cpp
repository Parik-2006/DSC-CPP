#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "SIZE: ";
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    map <int, int> mpp;
    for(int i =0; i<n; i++)
        mpp[arr[i]]++;

    // ITERATE IN THE MAP
    for(auto it: mpp){
        cout << it.first << "->" << it.second << endl;
    }
}