class Solution {
  public:
  
    long long gcd(long long a, long long b, long long &x, long long &y){
        if(b == 0){
            x = 1;
            y = 0;
            return a;
        }
        long long x1, x2;
        long long gcd1 = gcd(b, a%b, x1, x2);
        
        x = x2;
        y = x1 - (a/b) * x2;
        return gcd1;
    }
    int modInverse(int n, int m) {
        // code here
        long long x,y;
        long long gcd2 = gcd(n,m,x,y);
        
        if(gcd2 != 1)
            return -1;
        return (x%m+m)%m;
        
    }
};