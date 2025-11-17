#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        int x = 0;
        s = s + "0";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                x++;
            else {
                ans += 1LL * x * (x + 1) / 2;
                x = 0;
            }
        }
        return ans % 1000000007;
    }
};

int main() {
    Solution sol;
    string s = "00000";
    cout << sol.numSub(s);
}