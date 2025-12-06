#include <bits/stdc++.h>
using namespace std;

void smtg(int &num){
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
Conversely, in the pass-by-reference scenario, where the function signature is smtg(int &num),
the behavior is different. When the function is called, the parameter num becomes an alias or 
a reference to the original variable (number). Instead of copying the value, the functions 
stack frame stores the memory address of the original variable in main()s stack frame. 
This means that num does not have its own separate memory for the data; it simply provides a 
different name to access the same memory location as number. Consequently, any operation 
performed on num (e.g., num += 5) is a direct modification of the original number variable 
in the main() stack frame. When smtg() returns, although its stack frame is popped, the changes 
made to the variables value persist because the value was modified in the location owned by 
main(). The stacks primary role remains managing the distinct function frames, but the 
reference mechanism bypasses data duplication and enables the called function to directly 
manipulate the memory of the calling function.

#endif