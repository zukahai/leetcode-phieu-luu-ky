#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
    if (a[1] != b[1])
        return a[1] > b[1];
    return a[0] > b[0];
}

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        for (int start = 0; start <= n - k; start++) {
            int end = start + k - 1;
            unordered_map<int, int> cnt;
            for (int i = start; i <= end; i++) {
                cnt[nums[i]]++;
            }
            vector <vector<int>> a;
            for (auto x: cnt)
                a.push_back({x.first, x.second});
            sort(a.begin(), a.end(), compare);

            int sum = 0;
            for (int i = 0; i < x && i < a.size(); i++)
                sum += a[i][0] * a[i][1];
            ans.push_back(sum);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector <int> nums = {9,2,2};
    int k = 3;
    int x = 3;
    vector <int> ans = sol.findXSum(nums, k, x);
    for (int x: ans)
        cout << x << " ";
}