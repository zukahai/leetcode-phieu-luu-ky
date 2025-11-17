#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + stones[i];

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int>(k + 1, 1e9)));

        for (int i = 0; i < n; i++)
            dp[i][i][1] = 0;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int m = 2; m <= k; m++) {
                    for (int t = i; t < j; t++) {
                        dp[i][j][m] = min(dp[i][j][m], dp[i][t][m - 1] + dp[t+1][j][1]);
                    }
                }
                dp[i][j][1] = dp[i][j][k] + (pre[j + 1] - pre[i]);
            }
        }
        return dp[0][n - 1][1];
    }
};


int main() {
    Solution sol;
    vector<int> stones = {3,5,1,2,6};
    int k = 3;
    cout << sol.mergeStones(stones, k);
}