#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        const int MOD = 1000000007;
        int maxValue = 0;
        for (auto v: mat)
            maxValue = max(maxValue, *max_element(v.begin(), v.end()));
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(maxValue + 1, 0));
        for (int x: mat[0]) 
            dp[0][x] += 1;
        for (int row = 1; row < m; row++) {
            for (int x: mat[row]) {
                for (int g = 1; g <= maxValue; g++) {
                    if (dp[row - 1][g] > 0) {
                        int gcd = __gcd(x, g);
                        dp[row][gcd] += dp[row - 1][g];
                        dp[row][gcd] %= MOD;
                    }
                }
            }
        }
        return dp[m - 1][1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{6, 2}, {3, 4}, {3, 6}};
    cout << sol.countCoprime(mat);
}