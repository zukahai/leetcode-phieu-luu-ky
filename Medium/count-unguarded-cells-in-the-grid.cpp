#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> a(m, vector<char>(n, ' '));
        for (auto x: walls) {
            int row = x[0];
            int col = x[1];
            a[row][col] = 'W';
        }
        for (auto x: guards) {
            int row = x[0];
            int col = x[1];
            a[row][col] = 'G';
        }

        for (auto x: guards) {
            int row = x[0];
            int col = x[1];
            
            col--;
            while (col >= 0 && a[row][col] != 'G' && a[row][col] != 'W') {
                a[row][col] = 'X';
                col--;
            }
            col = x[1];

            col++;
            while (col < n && a[row][col] != 'G' && a[row][col] != 'W') {
                a[row][col] = 'X';
                col++;
            }
            col = x[1];

            row--;
            while (row >= 0 && a[row][col] != 'G' && a[row][col] != 'W') {
                a[row][col] = 'X';
                row--;
            }
            row = x[0];

            row++;
            while (row < m && a[row][col] != 'G' && a[row][col] != 'W') {
                a[row][col] = 'X';
                row++;
            }
        }
        int count = 0;
        for (auto row: a)
            for (auto x: row)
                count += (x == ' ');
        return count;
    }
};

int main() {
    int m = 4, n = 6;
    vector <vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector <vector<int>> walls = {{0,1},{2,2},{1,4}};
    Solution sol;
    cout << sol.countUnguarded(m, n, guards, walls);
}