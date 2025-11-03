#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector <vector<int>> dp(n, vector<int>(n, 1));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                int temp = INT_MAX;
                for (int k = i; k <= j - 1; k++) {
                    temp = min(temp, dp[i][k] + dp[k + 1][j]);
                }
                if (s[i] == s[j])
                    temp--;
                dp[i][j] = temp;
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;
    cout << sol.strangePrinter("abcbaa");
}