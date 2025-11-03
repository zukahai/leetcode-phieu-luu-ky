#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        str1 = "#" + str1; str2 = "#" + str2;
        int m = str1.size();
        int n = str2.size();
        vector <vector<int>> dp(m + 1, vector <int> (n + 1, 0));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (str1[i] == str2[j]) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string str = "";
        int index1 = m - 1, index2 = n - 1;
        while (dp[index1][index2] != 0) {
            if (str1[index1] == str2[index2]) {
                str += str1[index1];
                index1--;
                index2--;
            } else {
                if (dp[index1][index2] == dp[index1 - 1][index2]) {
                    index1--;
                } else {
                    index2--;
                }
            }
        }
        reverse(str.begin(), str.end());
        string ans = "";
        index1 = 1, index2 = 1;
        str += '#';
        for (auto ch: str) {
            while (index1 < str1.size() && str1[index1] != ch) {
                ans += str1[index1] ;
                index1++;
            }
            while (index2 < str2.size() && str2[index2] != ch) {
                ans += str2[index2];
                index2++;
            }
            if (ch != '#')
                ans += ch;
            index1++; index2++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.shortestCommonSupersequence("HaiPhan", "XahiPax");
}