#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1);
        dp[n] = 0;
        dp[n - 1] = stoneValue[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int val = stoneValue[i] - dp[i + 1];
            val = max(val, stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            if (i <= n - 3) {
                val = max(val, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
            }
            dp[i] = val;
        }

        if (dp[0] == 0)
            return "Tie";
        if (dp[0] > 0)
            return "Alice";
        return "Bob";
    }
};

int main() {
    Solution sol;
    vector<int> stoneValue = {1, 2, 3, 7};
    cout << sol.stoneGameIII(stoneValue);
}