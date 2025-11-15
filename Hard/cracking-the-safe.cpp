#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int total;
    int n, k;
public:
    bool solve(string &ans, unordered_set<string> &visited) {
        if (visited.size() == total)  {
            return true;
        }
        for (char ch = '0'; ch <= k + '0' - 1; ch++) {
            ans += ch;
            string cur = ans.substr(ans.size() - n);
            if (visited.find(cur) == visited.end()) {
                visited.insert(cur);
                if (solve(ans, visited))
                    return true;
                visited.erase(cur);
            }
            ans.pop_back();
        }
        return false;
    }
    string crackSafe(int n, int k) {
        this->k = k;
        this->n = n;
        total = pow(k, n);
        string ans = string(n, '0');
        unordered_set<string> visited = {ans};
        solve(ans, visited);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 2;
    int k = 3;
    cout << sol.crackSafe(n, k);
}