#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int leffBound = -1;
        int lastMin = -1;
        int lastMax = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxK || nums[i] < minK)
                leffBound = i;
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;
            int checkLeft = min(lastMax, lastMin);
            if (checkLeft > leffBound)
                ans += checkLeft - leffBound;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,5,2,7,5};
    int minK = 1, maxK = 5;
    cout << sol.countSubarrays(nums, minK, maxK);
}