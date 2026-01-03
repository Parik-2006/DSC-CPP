// best time to bu and sell stock
// array du most chikku element togondu next biggest element jothege minus maadbejku .. adhe highest profit .. sikkila andre 0 return
// descending array elements ittu andre no profit

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0; // slow pointer
        int max_p = 0;
        for(int sell = 1; sell < prices.size(); sell++){ // fast p
            if(prices[buy] < prices[sell]){
                int profit = prices[sell] - prices[buy];
                max_p = max(profit, max_p); 
            } else {
                buy = sell;
            }
        }
        return max_p;
    }
};

int main(){

}

// --- TEST CASE 1: Fluctuating Market ---
    // Buy at 1, Sell at 6
    // Expected: 5
    // vector<int> prices1 = {7, 1, 5, 3, 6, 4};

// --- TEST CASE 2: Always Falling (Bear Market) ---
    // No profit can be made
    // Expected: 0
    // vector<int> prices2 = {7, 6, 4, 3, 1};

// --- TEST CASE 3: Always Rising (Bull Market) ---
    // Buy at 1, Sell at 10
    // Expected: 9
    // vector<int> prices3 = {1, 2, 4, 7, 10};
