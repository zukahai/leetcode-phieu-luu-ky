#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int res = 0;
        for (int num: nums) {
            while (!st.empty() && st.top() > num)
                st.pop();
            if (num == 0)
                continue;
            if (st.empty() || st.top() < num) {
                res ++;
                st.push(num);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector <int> nums =  {2,2,2,2, 1, 2, 2, 2};
    cout << sol.minOperations(nums);
}