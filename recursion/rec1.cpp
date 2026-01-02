#include <iostream>
using namespace std;

void f(int n) {
    
    cout << "F(" << n << ")'s Stack Frame Pushed\n";
    if (n > 1) {
        f(n - 1);
        f(n - 1);
    }
    cout << "F(" << n << ")'s Stack Frame Removed\n";
}

int main() {
    f(3);
    return 0;
}

#if 0
f(3)
3 stack frame pushed
f(2)
2 stack frame pushed
f(1)
1 stack frame pushed
1 stack frame removed
f(2) returned
f(1)
1 stack frame pushed
1 stack frame removed
f(2) returned
2 stack frame removed 
f(3) returned
f(2)
2 stack frame pushed 
f(1)
1 stack frame pushed
and goes on .... till f(3) is completely returned
#endif