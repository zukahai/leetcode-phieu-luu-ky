#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<bool> cnt(1009, false);
        for (int i = 0; i< nums.size(); i++)
            cnt[nums[i]] = true;
        while (cnt[original] == true)
            original *= 2;
        return original;
    }
};

int main() {
    Solution sol;
    vector <int> nums = {5,3,6,1,12};
    int original = 3;
    cout << sol.findFinalValue(nums, original);
}