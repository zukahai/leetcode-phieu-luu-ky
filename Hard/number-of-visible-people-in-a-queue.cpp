#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 0;
            while (!st.empty() && st.top() < heights[i]) {
                st.pop();
                cnt++;
            }
            if (!st.empty()) cnt++;
            ans[i] = cnt;
            st.push(heights[i]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {10,6,8,5,11,9};
    vector<int> ans = sol.canSeePersonsCount(heights);
    for (int x: ans)
        cout << x << " ";
}