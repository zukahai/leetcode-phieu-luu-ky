#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        long long odd1, odd2, even1, even2;
        odd1 = odd2 = even1 = even2 = 0;
        const int MOD = 1000000007;
        for (int x: nums) {
            if (x % 2 == 1) {
                odd2 += odd1;
                odd1 += (even1 + even2);
                odd1++;
            } else {
                even2 += even1;
                even1 += (odd1 + odd2);
                even1++;
            }
            odd1 %= MOD;
            odd2 %= MOD;
            even1 %= MOD;
            even2 %= MOD;
        }
        return (odd1 + odd2 + even1 + even2) % MOD;
    }
};

int main() {
    vector<int> nums = {2, 3, 4, 2};
    Solution sol;
    cout << sol.countStableSubsequences(nums);
}