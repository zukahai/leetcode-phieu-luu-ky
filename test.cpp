#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxLen = 0;
        int pre = 0;
        bool con = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                if (!st.empty()) {
                    int len = i - st.top() + 1;
                    maxLen = max(maxLen, i - st.top() + 1);
                    st.pop();
                    if (st.empty()) {
                        if (con) {
                            pre += len;
                            maxLen = max(maxLen, pre);
                        } else {
                            pre = len;
                        }
                        con = true;
                    }
                } else {
                    con = false;
                    pre = 0;
                }
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    string s = ")()())";
    cout << sol.longestValidParentheses(s);
}