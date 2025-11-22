#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(string &s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string rev(words[i].rbegin(), words[i].rend());
            mp[rev] = i;
        }
        for (int i = 0; i < n; i++) {
            string w = words[i];
            int len = w.size();
            for (int cut = 0; cut <= len; cut++) {
                string prefix = w.substr(0, cut);
                string suffix = w.substr(cut);

                if (check(prefix) && mp.count(suffix) && mp[suffix] != i) {
                    ans.push_back({mp[suffix], i});
                }

                if (cut != len && check(suffix) && mp.count(prefix) && mp[prefix] != i) {
                    ans.push_back({i, mp[prefix]});
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    vector<vector<int>> ans = sol.palindromePairs(words);

    for (auto x: ans) 
        cout << x[0] << " " << x[1] << endl;
}