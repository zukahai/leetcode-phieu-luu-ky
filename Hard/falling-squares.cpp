#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int> &pos1, vector<int> &pos2) {
        int left1 = pos1[0];
        int size1 = pos1[1];
        int right1 = left1 + size1;
        int left2 = pos2[0];
        int size2 = pos2[1];
        int right2 = left2 + size2;
        if (left1 >= right2) return false;
        if (right1 <= left2) return false;
        return true;
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> height(n);
        height[0] = positions[0][1];
        for (int i = 1; i < n; i++) {
            int maxHeight = 0;
            for (int j = 0; j < i; j++) {
                if (check(positions[i], positions[j])) {
                    maxHeight = max(maxHeight, height[j]);
                }
            }
            height[i] = maxHeight + positions[i][1];
        }
        for (int i = 1; i < n; i++)
            height[i] = max(height[i - 1], height[i]);
        return height;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> positions = {{1,2},{2,3},{6,1},{5, 2},{4, 2}};
    vector<int> ans = sol.fallingSquares(positions);
    for (int x: ans)
        cout << x << " ";
}