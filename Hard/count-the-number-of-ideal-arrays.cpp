#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int MOD = 1000000007;
        vector<vector<int>> div(maxValue + 1, vector<int>(1, 1));
        for (int i = 2; i <= maxValue; i++) {
            for (int j = i; j <= maxValue; j += i) {
                div[j].push_back(i);
            }
        }

        // for (int i = 1; i <= maxValue; i++) {
        //     cout << i << endl;
        //     for (auto x: div[i])
        //         cout << x << " ";
        //     cout << endl;
        // }
        vector<vector<int>> dp(n + 1, vector<int> (maxValue + 1, 1));
        for (int i = 2; i <= n; i++) {
            for (int value = 1; value <= maxValue; value++) {
                dp[i][value] = 0;
                for (int x: div[value])
                    dp[i][value] = (dp[i][value] + dp[i - 1][x]) % MOD;
            }
        }
        int res = 0;
        for (int value = 1; value <= maxValue; value++)
            res = (res + dp[n][value]) % MOD;
        return res;
    }
};

int main() {
    Solution sol;
    int n = 5;
    int maxValue = 3;
    cout << sol.idealArrays(n, maxValue);
}