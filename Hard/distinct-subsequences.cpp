#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[i][n] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j];
                if (s[i] == t[j])
                    dp[i][j] += dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution sol;
    string s = "rabbbit";
    string p = "rabbit";
    cout << sol.numDistinct(s, p);
}