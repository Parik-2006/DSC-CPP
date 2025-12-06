#include <bits/stdc++.h>
using namespace std;

void func(int i, int n){
    if(i<1)
        return;
    func(i-1,n);
    cout << i << endl;
}

int main(){
    int num;
    cout << "Enter any number: ";
    cin >> num;
    func(num,num);
    return 0;
}


#if 0
The function `func(i, n)` keeps calling itself with a smaller value of `i` until `i` becomes 
less than 1. This means the function goes **deep down** into recursive calls first, without 
printing anything. Imagine going down a staircase: `func(5)` calls `func(4)`, which calls 
`func(3)`, then `func(2)`, then `func(1)`, and finally `func(0)` where the recursion stops. 
Once it reaches this stopping point, the function starts **backtracking**, meaning it begins 
returning from the deepest call back to the earlier ones. During this return journey, each 
function prints the value of `i` that it was holding. So the print happens **after** the 
recursive call, which is why the numbers appear in increasing order. Backtracking simply means: 
go all the way down first, then while coming back up, do the work (here, printing the number).

#endif