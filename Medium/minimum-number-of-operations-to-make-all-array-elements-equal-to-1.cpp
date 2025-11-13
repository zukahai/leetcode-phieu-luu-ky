#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        for (int x: nums) {
            cnt1 += (x == 1);
        }
        if (cnt1 > 0) return n - cnt1;
        int len = INT_MAX;
        for (int i = 0; i < n; i++) {
            int t = nums[i];
            for (int j = i + 1; j < n; j++) {
                t = __gcd(t, nums[j]);
                if (t == 1) {
                    len = min(len, j - i + 1);
                    break;
                }
            }
        }
        if (len == INT_MAX) return -1;
        return len - 1 + n - 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << sol.minOperations(nums);
}