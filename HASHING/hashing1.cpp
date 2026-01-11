#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " array elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // pre compute 
    int hash[13] = {0};
    for(int i = 0; i<n;i++){
        hash[arr[i]] += 1; 
    }

    cout << "Enter no of terms u want to check frequency for: ";
    int q;
    cin >> q;
    cout << "Enter the Numbers u want to check Frequency for: ";
    while(q--){
        int number;
        cin >> number;
        // fetch
        cout << hash[number] << endl;
    }
}

/*
10^6 is not a strict rule but a safe practical limit. Arrays created inside main() are stored 
on the stack, and the stack size on most systems is limited to around 8 MB. Since an int takes 
4 bytes, an array of size 10^6 requires about 4 MB of memory, which comfortably fits within the 
stack along with space for other local variables and function calls. However, an array of size 
10^7 would require about 40 MB, which exceeds the stack limit and causes stack overflow. Global 
arrays or heap allocations do not have this limitation because they are stored in static or 
heap memory, which is much larger. Therefore, programmers commonly use 10^6 as a safe rule of 
thumb for local arrays.
*/

/*
Using a frequency array is important because it avoids repeatedly scanning the original array 
for every query. Without a frequency array, each query requires traversing the entire array, 
which takes O(n) time per query and becomes very slow when the number of queries is large. With a
frequency array, we first count the occurrences of each element once in O(n) time 
(precomputation). After that, the frequency of any element can be obtained directly using its 
value as an index in O(1) time. This reduces the overall time complexity drastically and makes 
the program efficient for large inputs.
*/
