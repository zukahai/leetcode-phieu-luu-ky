#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1000000007;
        vector<int> dp(k + 1, 0);
        vector<int> prefix(k + 1, 0);
        dp[0] = 1;
        for (int num = 2; num <= n; num++) {
            prefix[0] = dp[0];
            for (int j = 1; j <= k; j++) {
                prefix[j] = (prefix[j - 1] + dp[j]) % MOD;
            }
            vector<int> newDp(k + 1, 0);
            for (int j = 0; j <= k; j++) {
                int left = j - min(j, num - 1);
                if (left == 0)
                    newDp[j] = prefix[j];
                else 
                    newDp[j] = (prefix[j] - prefix[left - 1] + MOD) % MOD;
            }
            dp = newDp;
        }
        return dp[k];
    }
};

int main() {
    Solution sol;
    int n = 3;
    int k = 1;
    cout << sol.kInversePairs(n, k);
}