#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int pre = 0;
        vector <int> cnt;
        for (auto &str: bank) {
            int cnt = 0;
            for (auto ch: str) 
                cnt += (ch - '0');
            if (cnt == 0)
                continue;
            ans += pre * cnt;
            pre = cnt;
        }
        return ans;
    }
};

int main() {
    vector <string> a = {"011001","000000","010100","001000"};
    Solution so;
    cout << so.numberOfBeams(a);

}