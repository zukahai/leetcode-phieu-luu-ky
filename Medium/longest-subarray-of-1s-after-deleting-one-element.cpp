#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        vector<int> dp(n, 0), dp2(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
            if (nums[i] == 1)
                dp[i] = dp[i - 1] + 1;
        
        dp2[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            if (nums[i] == 1)
                dp2[i] = dp2[i + 1] + 1;
        int res = max(dp2[1], dp[n - 2]);
        for (int i = 1; i <= n - 2; i++)
            res = max(res, dp[i - 1] + dp2[i + 1]);
        return res;
    }
};

int main() {
    Solution sol;
    vector <int> nums = {1, 0, 1};
    cout << sol.longestSubarray(nums);
}