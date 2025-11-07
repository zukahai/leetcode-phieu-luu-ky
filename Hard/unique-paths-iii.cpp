#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int nums, cnt, res;
    int rowS, colS;
    int m, n;
    vector <vector<bool>> check;
public:
    void setup(vector<vector<int>>& grid) {
        nums = cnt = res = 0;
        m = grid.size();
        n = grid[0].size();
        check.resize(m, vector<bool> (n, true));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1)
                    nums++;
                if (grid[i][j] == 1) {
                    rowS = i;
                    colS = j;
                } 
            }
        }
    }

    bool valid(int row, int col) {
        if (row < 0 || col < 0) return false;
        if (row >= m || col >= n) return false;
        return true;
    }

    void dfs(int row, int col, vector<vector<int>>& grid) {
        // cout << row <<  " " << col << endl;
        check[row][col] = false;
        cnt++;
        if (grid[row][col] == 2 && cnt == nums) {
            res++;
            check[row][col] = true;
            cnt--;
            return;
        }
        vector <vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (auto x: dir) {
            int newRow = row + x[0];
            int newCol = col + x[1];
            if (valid(newRow, newCol) && check[newRow][newCol] && grid[newRow][newCol] != -1) {
                dfs(newRow, newCol, grid);
            }
        }
        check[row][col] = true;
        cnt--;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        setup(grid);
        dfs(rowS, colS, grid);
        return res;
    }
};
int main() {
    Solution sol;
    vector <vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    // vector <vector<int>> grid = {{1,2}};
    cout << sol.uniquePathsIII(grid);
}