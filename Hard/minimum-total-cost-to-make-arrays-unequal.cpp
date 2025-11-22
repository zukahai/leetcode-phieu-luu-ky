#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> bad;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            if (nums1[i] == nums2[i]) {
                bad.push_back(i);
                cnt[nums1[i]]++;
            }
        }
        if (bad.size() == 0) return 0;
        int maxVal = -1;
        int maxFreq = 0;
        for (auto x: cnt) {
            if (x.second > maxFreq) {
                maxFreq = x.second;
                maxVal = x.first;
            }
        }
        long long cost = 0;
        int toltalBad = bad.size();
        cost = accumulate(bad.begin(), bad.end(), 0LL);
        int need = 2 * maxFreq - toltalBad;
        if (need <= 0) return cost;
        for (int i = 0; i < n && need > 0; i++) {
            if (nums1[i] != nums2[i] && nums1[i] != maxVal && nums2[i] != maxVal) {
                cost += i;
                need--;
            }
        }
        if (need > 0) return -1;
        return cost;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << sol.minimumTotalCost(nums1, nums2);
}