#include <bits/stdc++.h>
using namespace std;


// ITERATIVE
int factorial(int n){
    int fact = 1;
    for(int i = 1; i<=n; i++){
        fact *= i;
    }
    return fact;
}
// TC - 0(n), SC - 0(1)

// RECURSION
int rec_factorial(int n){
    if(n == 0 || n == 1)
        return 1;
    return n * rec_factorial(n-1);
}
// TC - 0(n), SC - 0(n)

int sum(int n){
    int sum = 0;
    for(int i = 0; i<=n; i++){
        sum += i;
    }
    return sum;
}

int main(){
    int num = 4;
    cout << "Factorial of the Given Number: " << factorial(num) << endl;
    cout << "Sum of the Given Number: " << sum(num) << endl; 
}