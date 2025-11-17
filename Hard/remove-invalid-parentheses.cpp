#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> x;
    int n;
    vector<set<string>> setstr;
public:
    bool check(string &p) {
        int cnt = 0;
        bool check = true;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == '(')
                cnt++;
            if (p[i] == ')')
                cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
    void solve(int index, string &s) {
        if (index >= n) {
            string p = "";
            for (int i = 0; i < n; i++) {
                if (x[i] == 1)
                    p += s[i];
            }
            if (check(p))
                setstr[s.size() - p.size()].insert(p);
            return;
        }
        if (s[index] != '(' && s[index] != ')') {
            solve(index + 1, s);
        } else {
            for (int i = 0; i <= 1; i++) {
                x[index] = i;
                solve(index + 1, s);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        x.resize(n, 1);
        setstr.resize(n + 1);
        solve(0, s);
        for (int i = 0; i <= n; i++) {
            if (setstr[i].size() > 0)  {
                return vector<string>(setstr[i].begin(), setstr[i].end());
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    string s = "(a()";
    vector<string> res = sol.removeInvalidParentheses(s);
    for (string s: res)
        cout << s << endl;
}