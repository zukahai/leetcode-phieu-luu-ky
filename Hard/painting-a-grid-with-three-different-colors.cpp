#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int m, n;
    string s;
    vector<string> strs;
public:
    void solve(int index) {
        if (index > m) {
            string p = "";
            bool flag = true;
            for (int i = 2; i <= m; i++)
                if (s[i] == s[i - 1]) {
                    flag = false;
                    break;
                }
            if (flag) {
                for (int i = 1; i <= m; i++)
                    p += s[i];
                strs.push_back(p);
            }
            return;
        }
        for (char i = '1'; i <= '3'; i++) {
            s[index] = i;
            solve(index + 1);
        }
    }

    bool check(string p, string s) {
        for (int i = 0; i < p.size(); i++)
            if (s[i] == p[i]) return false;
        return true;
    }
    int colorTheGrid(int m, int n) {
        const int mod = 1000000007;
        this->m = m;
        this->n = n;
        s = string(m + 1, ' ');
        solve(1);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < strs.size(); i++)
            for (int j = 0; j < strs.size(); j++) {
                if (check(strs[i], strs[j]))
                    mp[i].push_back(j);
            }
        
        vector <vector<int>> dp(n + 1, vector<int>(strs.size()));
        for (int i = 0; i < strs.size(); i++)
            dp[1][i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < strs.size(); j++) {
                int sum = 0;
                for (int x: mp[j]) {
                    sum += dp[i - 1][x];
                    sum %= mod;
                }
                dp[i][j] = sum;
            }
        }
        int res = 0;
        for (int j = 0; j < strs.size(); j++) {
            res += dp[n][j];
            res %= mod; 
        }
        return res;
    }
};

int main() {
    Solution sol;
    int m = 1;
    int n = 2;
    cout << sol.colorTheGrid(m, n);
}