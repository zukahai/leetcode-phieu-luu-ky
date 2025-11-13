#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        s = s + "1";
        int cntOnes = s[0] - '0';
        int res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') {
                if (s[i - 1] == '0')
                    res += cntOnes;
                cntOnes++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.maxOperations("0001111");
}