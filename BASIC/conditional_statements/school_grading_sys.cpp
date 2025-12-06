#include <bits/stdc++.h>
using namespace std;

int main(){
    int st_marks;
    cin >> st_marks;
    if(st_marks < 40)
        cout << "You are Failed!!";
    else if(st_marks <= 60)
        cout << "Grade D";
    else if(st_marks <= 80)
        cout << "Grade C";
    else if(st_marks <= 90)
        cout << "Grade B";
    else if(st_marks <= 100)
        cout << "Grade A";
    return 0;
}