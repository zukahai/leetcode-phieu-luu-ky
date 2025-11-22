#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> &a, vector<int>&b) {
    if (a[1] != b[1])
        return a[1] < b[1];
    return a[0] < b[0]; 
}


class Solution {
public:
    void add(vector<int> &nums, int x) {
        if (x > nums.back())
            nums.push_back(x);
        else {
            nums.pop_back();
            nums.push_back(x - 1);
            nums.push_back(x);
        }
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> nums = {intervals[0][1] - 1, intervals[0][1]};
        for (vector<int> interval: intervals) {
            int n = nums.size();
            int start = interval[0];
            int end = interval[1];
            if (start > nums[n - 1]) {
                add(nums, end - 1);
                add(nums, end);
            } else if (start > nums[n - 2]) {
                add(nums, end);
            }
        }

        // for (int x: nums)
        //     cout << x << " ";
        // cout << endl;

        return nums.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{3,7},{5,7},{7,8}};
    cout << sol.intersectionSizeTwo(intervals);
}