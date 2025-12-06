#include <bits/stdc++.h>
using namespace std;

int sum(int i){
    if(i == 1)
        return 1;
    return i + sum(i-1);
}
int main(){
    int num;
    cout << "Enter any number: ";
    cin >> num;
    int result = sum(num);
    cout << "Sum of " << num << " is " << result << endl;
    return 0;
}

#if 0
Parameterized recursion and functional recursion differ mainly in how they compute and 
return results. In **parameterized recursion**, the answer is carried forward through 
parameters in each recursive call. The function keeps updating a variable (like `sum`, `count`, 
etc.) and passes it to the next call, and when the base condition is reached, that parameter 
holds the final result. It’s like carrying a bag that gets fuller at each step until you stop. 
In **functional recursion**, the function does not carry the result in its parameters; instead, 
each recursive call returns a value, and the final result is formed by combining these returned 
values. It’s like waiting for each deeper call to finish its work and then using its returned 
value to build the final answer. Parameterized recursion focuses on *passing the result 
downward*, while functional recursion focuses on *building the result upward* as calls return.
#endif