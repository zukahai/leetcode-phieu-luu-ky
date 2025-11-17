#include <bits/stdc++.h>

using namespace std;

bool compare(string &a, string &b) {
    return a.size() < b.size();
}

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_set<string> dict;
        vector<string> ans;
        for (auto word: words) {
            if (word.empty()) continue;
            int n = word.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (!dp[j]) continue;
                    if (dict.count(word.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[n])
                ans.push_back(word);
            dict.insert(word);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    vector<string>  ans = sol.findAllConcatenatedWordsInADict(words);
    cout << ans.size() << endl;
    for (string x: ans)
        cout << x << endl;
}