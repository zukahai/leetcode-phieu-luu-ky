#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long costX(vector<int>& nums, vector<int>& cost, int x) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += 1LL * abs(nums[i] - x) * cost[i];
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        long long ans = LLONG_MAX;
        while (left <= right) {
            // cout << left << " @ " << right << endl;
            int mid = (left + right) / 2;
            long long r1 = costX(nums, cost, mid);
            long long r2 = costX(nums, cost, mid + 1);
            // cout << r1 << " " << r2 << endl;
            if (r1 < r2) {
                ans = min(ans, r1);
                right = mid - 1;
            } else {
                ans = min(ans, r2);
                left = mid + 1 + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,5,2};
    vector<int> cost = {2,3,1,14};
    cout << sol.minCost(nums, cost);
}