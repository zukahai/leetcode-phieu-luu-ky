#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map <int, bool> colum, diag1, diag2;
    int indexCol[10];
    vector<vector<string>> res;
public:
    void solve(int row, int n) {
        if (row >= n) {
            vector <string> temp(n, string(n, '.'));
            for (int row = 0; row < n; row++) {
                int col = indexCol[row];
                temp[row][col] = 'Q';
            }
            res.push_back(temp);
        }
        for (int col = 0; col < n; col ++) {
            if (colum[col] != true && diag1[row - col] != true && diag2[row + col] != true) {
                indexCol[row] = col;
                colum[col] = true;
                diag1[row - col] = true;
                diag2[row + col] = true;
                solve(row + 1, n);
                colum[col] = false;
                diag1[row - col] = false;
                diag2[row + col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        solve(0, n);
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(5);

    for (auto r: res) {
        for (auto row: r) {
            cout << row << endl;
        }
        cout << " ------------- " << endl;
    }
}