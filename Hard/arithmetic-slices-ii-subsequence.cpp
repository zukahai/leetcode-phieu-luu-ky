#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, long long>> dp(n);
        int res = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = 1LL * nums[i] - nums[j];
                if (d > INT_MAX || d < INT_MIN) continue;
                dp[i][d] += 1;
                if (dp[j].count(d) > 0) {
                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 5, 7};
    cout << sol.numberOfArithmeticSlices(nums);
}