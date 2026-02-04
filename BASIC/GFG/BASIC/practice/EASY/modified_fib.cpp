// to find Nth fibonacci series from given a, b 
#include <iostream>
using namespace std;
int findNthNumber(int A, int B, int N){
    int sum = 0;
    for (int i = 2; i < N; i++) {
        sum = A + B;
        A = B;
        B = sum;
    }
    return sum;
}

int main(){
    int A = 5, B = 7, N = 10;
    cout << findNthNumber(A, B, N);
    return 0;
}

#if 0
Given two integers A and B which are the first two terms of the series and another integer N. The task is to find the Nth number using Fibonacci rule i.e. fib(i) = fib(i - 1) + fib(i - 2)
Example: 
Input: A = 2, B = 3, N = 4 
Output: 8 
The series will be 2, 3, 5, 8, 13, 21, ... 
And the 4th element is 8.
Input: A = 5, B = 7, N = 10 
Output: 343 
#endif