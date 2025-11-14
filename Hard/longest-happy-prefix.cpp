#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        string ans = "";
        string prefix = "";
        string suff = "";
        for (int i = 0, j = s.size() - 1; i < s.size() - 1; i++, j--) {
            prefix += s[i];
            suff = s[j] + suff;
            if (prefix == suff)
                ans = prefix;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "";
    cout << sol.longestPrefix(s);
}