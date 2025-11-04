#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool check(int row, int col, int n) {
        if (row < 0 || col < 0) return false;
        if (row >= n || col >= n) return false;
        return true;
    }
public:
    bool bfs(vector<vector<int>>& grid, int t) {
        int n = grid.size();
        vector <vector<int>> val(n, vector<int>(n, -1));
        if (grid[0][0] > t || grid[n - 1][n - 1] > t) return false;
        queue <vector<int>> q;
        q.push({0, 0});
        val[0][0] = 0;
        vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            vector <int> x = q.front();
            int row = x[0], col = x[1];
            for (auto dr: d) {
                int newRow = row + dr[0];
                int newCol = col + dr[1];
                if (check(newRow, newCol, n) && val[newRow][newCol] == -1 && grid[newRow][newCol] <= t) {
                    val[newRow][newCol] = val[row][newCol] + 1;
                    q.push({newRow, newCol});
                }
            }
            q.pop();
        }
        return val[n - 1][n - 1] != -1;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0, right = n * n - 1;
        int ans = -1;
        while (left <= right) {
            int t = (left + right) / 2;
            if (bfs(grid, t)) {
                ans = t;
                right = t - 1;
            } else {
                left = t + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}
    };
    cout << sol.swimInWater(grid);
}