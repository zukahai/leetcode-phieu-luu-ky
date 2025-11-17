#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int minD = INT_MAX;
        int index1 = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                minD = min(minD, i - index1 - 1);
                index1 = i;
            }
        }
        return minD >= k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,0,0,0,1,1,0,1};
    int k = 2;
    cout << sol.kLengthApart(nums, k);
}