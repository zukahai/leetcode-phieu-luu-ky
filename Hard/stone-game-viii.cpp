
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + stones[i];
        
        vector<int> dp(n);
        dp[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            dp[i] = max(dp[i + 1], prefix[i] - dp[i + 1]);
        }
        return dp[1];
    }
};

int main() {
    Solution sol;
    vector<int> stones = {-1,2,-3,4,-5};
    cout << sol.stoneGameVIII(stones);
}