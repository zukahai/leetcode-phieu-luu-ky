#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestDecomposition(string text) {
        string pre = "", suff = "";
        int cnt = 0;
        for (int i = 0, j = text.size() - 1; i < text.size(); i++, j--) {
            pre = pre + text[i];
            suff = text[j] + suff;
            if (pre == suff) {
                cnt++;
                pre = suff = "";
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    string text = "ghiabcdefhelloadamhelloabcdefghi";
    cout << sol.longestDecomposition(text);
}