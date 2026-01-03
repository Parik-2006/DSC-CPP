// number of ways to print n*3 grid

class Solution {
public:
    static const int MOD = 1000000007;
    int numOfWays(int n) {
        long long sameColorPattern = 6; // Type 1
        long long diffColorPattern = 6; // Type 2
        for(int row = 2; row<=n; row++){
            long long newdiff = (diffColorPattern * 2 +             sameColorPattern * 2) % MOD;
            long long newSame = (diffColorPattern * 2 +             sameColorPattern * 3) % MOD;
            diffColorPattern = newdiff;
            sameColorPattern = newSame;
        }
        return (int)((sameColorPattern + diffColorPattern) % MOD);
    }
};

// Input: n = 1
// Output: 12

// Input: n = 2
// Output: 54

// Input: n = 3
// Output: 246

// Input: n = 4
// Output: 1122

// Input: n = 5
// Output: 5106

// Input: n = 10
// Output: 10107954

// Input: n = 5000
// Output: 30228214
