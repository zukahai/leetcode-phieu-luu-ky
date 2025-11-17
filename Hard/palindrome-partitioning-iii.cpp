#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int left = i, right = j;
                int cnt = 0;
                while (left < right) {
                    cnt += (s[left] != s[right]);
                    left++;
                    right--;
                }
                cost[i][j] = cnt;
            }
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, 1e9));
        for (int i = 0; i < n; i++)
            dp[i][1] = cost[0][i];
        for (int p = 2; p <= k; p++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    dp[i][p] = min(dp[i][p] , dp[j][p - 1] + cost[j + 1][i]);
                }
            }
        }
        return dp[n - 1][k];
    }
};

int main() {
    Solution sol;
    string s = "abc";
    int k = 2;
    cout << sol.palindromePartition(s, k);
}