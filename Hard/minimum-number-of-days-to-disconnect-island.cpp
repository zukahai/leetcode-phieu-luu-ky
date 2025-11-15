#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>> &grid) { // khong ket noi: true
        int m = grid.size();
        int n = grid[0].size();
        vector <vector<bool>> bc(m, vector<bool>(n, true));
        int row1 = -1, col1 = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 1) {
                    row1 = i;
                    col1 = j;
                    break;
                }
            if (row1 != -1)
                break;
        }
        if (row1 == -1) return true;
        queue <vector<int>> q;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        q.push({row1, col1});
        while (!q.empty()) {
            vector<int> t = q.front();
            q.pop();
            int row = t[0];
            int col = t[1];

            bc[row][col] = false;
            for (auto d: dir) {
                int dx = d[0];
                int dy = d[1];
                int nx = row + dx;
                int ny = col + dy;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1 && bc[nx][ny]) {
                    q.push({nx, ny});
                }
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1 && bc[i][j])
                    return true;
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (check(grid)) return 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (check(grid)) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid =  {{0,1,0,0},{0,1,1,0},{0,0,0,0}};
    cout << sol.minDays(grid);
}