#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int MOD = 1000000007;
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            long long num = 0;
            long long sum = 0;
            for (int j = i; j < n; j++) {
                num = num * 10 + (s[j] - '0');
                if (num > k) break;
                sum += dp[j + 1];
                sum %= MOD;
            }
            dp[i] = sum;
        }
        return dp[0];
    }
};

int main() {
    Solution sol;
    string s = "1317";
    int k = 13;
    cout << sol.numberOfArrays(s, k);
}