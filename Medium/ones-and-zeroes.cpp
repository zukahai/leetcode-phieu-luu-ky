#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector <vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (string str: strs) {
            int zereos = count(str.begin(), str.end(), '0');
            int ones = str.size() - zereos;
            for (int i = m; i >= zereos; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zereos][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    vector <string> strs = {"10","0001","111001","1","0"};
    int m = 20;
    int n = 20;
    cout << sol.findMaxForm(strs, m, n);
}