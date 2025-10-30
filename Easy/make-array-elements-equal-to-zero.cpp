#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sumArr = accumulate(nums.begin(), nums.end(), 0);
        int sumL = 0, sumR;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                sumR = sumArr - sumL;
                ans += (sumL == sumR) ? 2 : 0;
                ans += (abs(sumL - sumR) == 1) ? 1 : 0;
            }
            sumL += nums[i];
        }
        return ans;
    }
};

int main() {
    vector <int> nums = {1, 0, 2, 0, 3};
    Solution sol;
    cout << sol.countValidSelections(nums);
}