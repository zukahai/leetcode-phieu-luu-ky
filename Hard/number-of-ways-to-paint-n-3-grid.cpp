#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const int mod = 1000000007;
        vector<string> strs;
        string temp = "RGY";
        for (char x: temp)
            for (char y: temp)
                for (char z: temp)
                    if (x != y && y != z) {
                        string t = "";
                        t = t + x + y + z;
                        strs.push_back(t);
                    }
        unordered_map <string, int> convert;
        for (int i = 0; i < strs.size(); i++)
            convert[strs[i]] = i;
        unordered_map<string, vector<string>> mp;
        for (string s: strs)
            for (string p: strs) {
                if (s[0] != p[0] && s[1] != p[1] && s[2] != p[2]) {
                    mp[s].push_back(p);
                }
            }

        vector <vector<int>> dp(n + 1, vector<int>(strs.size(), 0));
        for (string s: strs)
            dp[1][convert[s]] = 1;
        for (int i = 2; i <= n; i++) {
            for (string s: strs) {
                int sum = 0;
                for (string p: mp[s]) {
                    sum += dp[i - 1][convert[p]];
                    sum %= mod;
                }
                dp[i][convert[s]] = sum;
            }
        }
        int res = 0;
        for (string s: strs) {
            res += dp[n][convert[s]];
            res %= mod;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 5000;
    cout << sol.numOfWays(n);
}