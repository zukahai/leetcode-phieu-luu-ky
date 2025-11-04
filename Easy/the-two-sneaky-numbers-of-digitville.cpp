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