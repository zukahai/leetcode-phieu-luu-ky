#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        const int MOD = 1000000007;
        int n = nums.size();
        unordered_map <int, int> cnt, mp;
        for (int x: nums) cnt[x]++;
        int k = 0, d = 0;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == 1) d++;
            if (mp[nums[i]] == cnt[nums[i]]) d--;
            if (d == 0) k++;
        }
        int res = 1;
        for (int i = 1; i <= k - 1; i++)
            res = (res * 2) % MOD;
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    cout << sol.numberOfGoodPartitions(nums);
}