#include <bits/stdc++.h>
using namespace std;

void smtg(int num){
    cout << num << endl;
    num+=5;
    cout << num << endl;
    num+=5;
    cout << num << endl;
}

int main(){
    int number = 5;
    cout << "Before function: \n";
    smtg(number);
    cout << "After function: \n";
    cout << number << endl;
    return 0;
}

#if 0
In the pass-by-value scenario, when a function like smtg(int num) is called, a 
separate stack frame is created for smtg() and pushed onto the main stack. Within this new frame,
the parameter num is allocated its own unique memory location, and it receives a copy of the 
original variables value (e.g., 5). The original variable (number in main()) and the 
copy (num in smtg()) are completely independent. Any changes made to num only affect this local 
copy within the smtg() stack frame. When smtg() finishes, its entire frame is popped off the 
stack, and the modified copy of num is destroyed, leaving the original number in the main() 
frame untouched.
#endif