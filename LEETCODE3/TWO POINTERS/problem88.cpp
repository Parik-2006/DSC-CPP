// merge sorted array
// erd array iratte .. erdu non decreasing order du ... adna merge maadi one final sorted array store madadhu return alla
// first array alli final elements 0 iratte .. enke andre second array du elements store madbekala .. adke

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(j>=0){
            if(i>=0 && nums1[i] > nums2[j]){
                nums1[k] = nums1[i--];
            } else {
                nums1[k] = nums2[j--];
            }
            k--;
        }
    }
};

// time complexity = 0(m+n)
int main(){

}

