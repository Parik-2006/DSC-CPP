#include <bits/stdc++.h>
using namespace std;
int summ(int i, int sum){
    if(i<1)
        return sum;
    return summ(i-1, sum + i);
}

int main(){
    int num;
    cout << "Enter any number: ";
    cin >> num;
    int result = summ(num,0);
    cout << "Sum of " << num << " is " << result << endl;
    return 0;
}

// This program calculates the sum of numbers from 1 to a given number using recursion. 
// When the user enters a number, the `summ` function is called with two parameters: the current 
// number `i` and an accumulated `sum` that starts at 0. The function keeps calling itself while 
// decreasing `i` by 1 each time, adding the current value of `i` to `sum`. This continues until 
// `i` becomes less than 1, at which point the function returns the accumulated sum. As the 
// recursive calls return back up the stack, the final computed value is passed back to `main`, 
// where it is stored in `result`. Finally, the program prints the total sum in a readable format. 
// This approach demonstrates how recursion can replace loops to perform cumulative calculations.
