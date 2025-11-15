#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++)
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        return *max_element(dp.begin(), dp.end());
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> h12(n), h21(n);
        for (int i = 0; i < n; i++) {
            h12[i] = nums1[i] - nums2[i];
            h21[i] = -h12[i];
        }

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        return max(sum1 + maxSum(h21), sum2 + maxSum(h12));
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {60,60,60};
    vector<int> nums2 = {10, 90, 10};
    cout << sol.maximumsSplicedArray(nums1, nums2);
}