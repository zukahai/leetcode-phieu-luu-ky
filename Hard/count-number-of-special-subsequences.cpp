#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        const int MOD = 1000000007;
        int cnt0, cnt1, cnt2;
        cnt0 = cnt1 = cnt2 = 0;
        for (int num: nums) {
            if (num == 0) cnt0 += (cnt0 + 1);
            if (num == 1) cnt1 += (cnt1 + cnt0);
            if (num == 2) cnt2 += (cnt2 + cnt1);
            cnt0 %= MOD; 
            cnt1 %= MOD; 
            cnt2 %= MOD;
        }
        return cnt2;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,2,0,1,2};
    cout << sol.countSpecialSubsequences(nums);
}