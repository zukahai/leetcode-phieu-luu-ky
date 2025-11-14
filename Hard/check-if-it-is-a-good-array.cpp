#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
            res = __gcd(res, nums[i]);
        return res == 1;
    }
};