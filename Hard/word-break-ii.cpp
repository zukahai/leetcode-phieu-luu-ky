#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<string> res;
    string s;
    unordered_map <string, bool> mp;
    string p;
public:
    void solve(int index) {
        if (index == s.size() - 1) {
            string str = "";
            for (int i = 0; i < s.size() - 1; i++) {
                str += s[i];
                if (p[i] == '1')
                    str += " ";
            }
            str += s.back();
            bool flag = true;
            stringstream ss(str);
            string k;
            while (ss >> k) {
                if (mp.find(k) == mp.end()) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(str);
            return;
        }
        for (char ch = '0'; ch <= '1'; ch++) {
            p[index] = ch;
            solve(index + 1);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto x: wordDict) mp[x] = true;
        p = string(s.size(), ' ');
        this->s = s;
        solve(0);
        return res;
    }
};

int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    vector<string> res = sol.wordBreak(s, wordDict);
    for (auto x: res)
        cout << x << endl;
}
