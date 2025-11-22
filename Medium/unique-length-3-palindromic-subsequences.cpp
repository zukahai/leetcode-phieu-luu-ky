#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<bool>> prefix(n, vector<bool> (123, false)), suff(n, vector<bool> (123, false));
        prefix[0][s[0]] = true;
        for (int i = 1; i < n; i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                prefix[i][ch] = prefix[i - 1][ch];
            }
            prefix[i][s[i]] = true;
        }

        suff[n - 1][s[n - 1]] = true;
        for (int i = n - 2; i >= 0; i--) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                suff[i][ch] = suff[i + 1][ch];
            }
            suff[i][s[i]] = true;
        }

        unordered_set<string> res;

        for (int i = 1; i <= n - 2; i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (prefix[i - 1][ch] && suff[i + 1][ch]) {
                    string t = "";
                    t = t + ch + s[i] + ch;
                    res.insert(t);
                }
            }
        }
        return res.size();
    }
};

int main() {
    Solution sol;
    string s = "aabca";
    cout << sol.countPalindromicSubsequence(s);
}