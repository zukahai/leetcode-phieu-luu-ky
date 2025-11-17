#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, 5e8);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            vector<int> newDp = dp;
            for (int x = 0; x <= n; x++) {
                int index = min(x + 1 + time[i], n);
                newDp[index] = max(newDp[index], dp[x] + cost[i]);
            }
            dp = newDp;
        }
        return dp[n];
    }
};