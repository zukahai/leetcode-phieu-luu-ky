#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int nMiss = 1;
        int dem = 0;
        int range = 0;
        int index = 0;
        while (range < n) {
            if (index < nums.size() && (range >= nums[index] || nums[index] == nMiss)) {
                range += nums[index];
                index++;
            } else {
                dem++;
                range += nMiss;
            }
            nMiss = range + 1;
        }
        return dem;
    }
};

int main() {
    vector <int> nums = {1, 5, 10};
    int n = 20;
    Solution sol;
    cout << sol.minPatches(nums, n);
}