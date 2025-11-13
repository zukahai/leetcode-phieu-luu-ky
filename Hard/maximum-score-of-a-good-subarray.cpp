#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k - 1, right = k + 1;
        int score = nums[k];
        int minNums = nums[k];
        while (left >= 0 || right <= n - 1) {
            bool isLeft = true;
            if (left < 0) isLeft = false;
            else if (right <= n - 1 && nums[right] > nums[left]) isLeft = false;
            if (isLeft) {
                minNums = min(minNums, nums[left]);
                left--;
            } else {
                minNums = min(minNums, nums[right]);
                right++;
            }
            score = max(score, minNums * (right - left - 1));
        }
        return score;
    }
};

int main() {
    Solution sol;
    vector <int> nums = {5,5,4,5,4,1,1,9};
    int k = 7;
    cout << sol.maximumScore(nums, k);
}