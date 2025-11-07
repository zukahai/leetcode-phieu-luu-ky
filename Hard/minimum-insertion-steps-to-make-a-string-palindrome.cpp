#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        string p = s;
        reverse(p.begin(), p.end());
        s = "@" + s; 
        p = "@" + p;
        int n = s.size();
        vector <vector<int>> dp(n, vector<int>(n));
        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
                if (s[i] == p[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return n - dp[n - 1][n - 1] - 1;
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    cout << sol.minInsertions(s); 
}