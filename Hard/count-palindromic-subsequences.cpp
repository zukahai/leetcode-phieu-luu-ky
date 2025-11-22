#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1000000007;
        int n = s.size();
        vector<vector<vector<int>>> prefix(n, vector<vector<int>>(10, vector<int>(10, 0)));
        vector<vector<vector<int>>> suff(n, vector<vector<int>>(10, vector<int>(10, 0)));
        vector<int> cnt(10, 0);
        cnt[s[0] - '0']++;
        for (int i = 1; i < n; i++) {
            for (int x = 0; x <= 9; x++) {
                for (int y = 0; y <= 9; y++) {
                    prefix[i][x][y] = prefix[i - 1][x][y];
                    prefix[i][x][y] %= MOD;
                }
            }
            int x = s[i] - '0';
            for (int y = 0; y <= 9; y++) {
                prefix[i][x][y] += cnt[y];
                prefix[i][x][y] %= MOD;
            }
            cnt[s[i] - '0']++;
        }

        cnt = vector<int>(10, 0);
        cnt[s.back() - '0']++;
        for (int i = n - 2; i >= 0; i--) {
            for (int x = 0; x <= 9; x++) {
                for (int y = 0; y <= 9; y++) {
                    suff[i][x][y] = suff[i + 1][x][y];
                    suff[i][x][y] %= MOD;
                }
            }
            int x = s[i] - '0';
            for (int y = 0; y <= 9; y++) {
                suff[i][x][y] += cnt[y];
                suff[i][x][y] %= MOD;
            }
            cnt[s[i] - '0']++;
        }

        int res = 0;
        for (int i = 2; i <= n - 3; i++) {
            for (int x = 0; x <= 9; x++) {
                for (int y = 0; y <= 9; y++) {
                    res += (1LL * prefix[i - 1][x][y] * suff[i + 1][x][y]) % MOD;
                    res %= MOD;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "103301";
    cout << sol.countPalindromes(s);
}