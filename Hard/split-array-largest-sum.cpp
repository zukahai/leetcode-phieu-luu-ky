#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count(vector<int>& nums, int x) {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > x) {
                cnt++;
                sum = nums[i];
            }
        }
        cnt++;
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int res = 0;
        while (left <= right) {
            int x = (left + right) / 2;
            if (count(nums, x) <= k) {
                res = x;
                right = x - 1;
            } else {
                left = x + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector <int> nums = {7,2,5,10,8};
    int k = 1;
    cout << sol.splitArray(nums, k);
}