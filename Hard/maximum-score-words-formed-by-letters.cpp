#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<string> bin;
    string s;
    int n;
public:
    void solve(int index) {
        if (index >= n) {
            bin.push_back(s);
            return;
        }
        for (char ch = '0'; ch <= '1'; ch++) {
            s[index] = ch;
            solve(index + 1);
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        vector <int> val(n);
        s = string(n, '0');
        solve(0);
        for (int i = 0; i < words.size(); i++) {
            val[i] = 0;
            for (auto ch: words[i]) {
                val[i] += score[ch - 'a'];
            }
        }

        unordered_map<char, int> cntAll;
        for (char ch: letters)
            cntAll[ch]++;
        int res = 0;
        for (string s: bin) {
            unordered_map<char, int> cnt;
            int sumVal = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '1') {
                    sumVal += val[i];
                    for (char ch: words[i])
                        cnt[ch]++;
                }
            }
            bool flag = true;
            for (auto x: cnt) {
                char ch = x.first;
                int cntCh = x.second;
                if (cntAll[ch] < cntCh) {
                    flag = false;
                    break;
                }
            }
            if (flag && sumVal > res)
                res = sumVal;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'}; 
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    cout << sol.maxScoreWords(words, letters, score);
}