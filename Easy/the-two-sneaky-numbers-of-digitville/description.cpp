#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        vector <int> cnt(n, 0);
        vector <int> res;
        for (auto x: nums) {
            if (cnt[x] == 1)
                res.push_back(x);
            cnt[x]++;
            if (res.size() == 2)
                return res;
        }
        return res;
    }
};

int main() {
    vector <int> nums = {7,1,5,4,3,4,6,0,9,5,8,2};
    Solution sol;
    vector <int> res = sol.getSneakyNumbers(nums);
    cout << res[0] << " " << res[1];
}