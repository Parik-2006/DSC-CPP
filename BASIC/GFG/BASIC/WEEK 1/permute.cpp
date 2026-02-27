#include <iostream>
using namespace std;

void permute(int* a, int l, int r)
{
    // Base case: one permutation formed
    if (l == r) {
        for (int i = 0; i <= r; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    // Try all possibilities for position l
    for (int i = l; i <= r; i++) {
        swap(a[l], a[i]);        // choose
        permute(a, l + 1, r);    // explore
        swap(a[l], a[i]);        // un-choose (backtrack)
    }
}

int main()
{
    int a[] = {5, 6, 8};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Permutations are:\n";
    permute(a, 0, n - 1);

    return 0;
}
