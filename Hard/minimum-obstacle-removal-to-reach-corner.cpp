#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m + 1, vector<int>(n, INT_MAX));
        deque<vector<int>> dq;
        dist[0][0] = 0;
        dq.push_front({0, 0});
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!dq.empty()) {
            int x = dq.front()[0];
            int y = dq.front()[1];
            dq.pop_front();
            for (auto elm: dir) {
                int dx = elm[0];
                int dy = elm[1];
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newDist = dist[x][y] + grid[nx][ny];
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        if (grid[nx][ny] == 0) 
                            dq.push_front({nx, ny});
                        else 
                            dq.push_back({nx, ny});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,1,1},{1,1,0},{1,1,0}};
    cout << sol.minimumObstacles(grid);
}