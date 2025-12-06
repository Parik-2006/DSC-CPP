// Count the number of digits in a number using recursion.

#include <bits/stdc++.h>
using namespace std;

int no_digits(int n, int count){
    if (n==0)
        return count;
    return no_digits(n/10, count+1);
}

int main(){
    int n = 1004;
    int result = no_digits(n,0);
    cout << result;
    return 0;
}

// 100, 0 -> 10,1 -> 1,2 -> 0,3 -> 3