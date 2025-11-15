#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> x;
    vector<bool> check;
    unordered_map<vector<int>, bool> s;
    int n;
public:
    bool isSquare(int n) {
        int sq = sqrt(n);
        return sq * sq == n;
    }
    void solve(int index, vector<int>& nums) {
        if (index > n) {
            s[x] = true;;
            // for (int i = 1; i <= n; i++) {
            //     cout << x[i] << " ";
            // }
            // cout << endl;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check[i] && (isSquare(x[index - 1] + nums[i]) || index == 1)) {
                x[index] = nums[i];
                check[i] = false;
                solve(index + 1, nums);
                check[i] = true;
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        n = nums.size();
        x.resize(n + 1, 0);
        check.resize(n, true);
        solve(1, nums);
        return (int)s.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 2};
    cout << sol.numSquarefulPerms(nums);
}