#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min1 = INT_MAX;
        int max1 = 0;
        int min2 = INT_MAX;
        int max2 = 0; 

        for (int price: prices) {
            min1 = min(min1, price);
            max1 = max(max1, price - min1);
            min2 = min(min2, price - max1);
            max2 = max(max2, price - min2);
        }
        return max2;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << sol.maxProfit(prices);
}