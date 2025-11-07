#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string res = s;
        for (int i = 0; i < s.size(); i++) {
            s = s + s[0];
            s.erase(s.begin());
            res = min(res, s);
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.orderlyQueue("abdea", 2); 
}