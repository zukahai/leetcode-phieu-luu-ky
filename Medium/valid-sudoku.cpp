#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool drow[9][10], dcol[9][10], dbox[30][30][10];
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char x = board[row][col];
                if (x == '.') continue;
                if (drow[row][x - '0'])
                    return false;
                if (dcol[col][x - '0'])
                    return false;
                int rowB = row / 3;
                int colB = col / 3;
                for (int i = rowB * 3; i <= rowB * 3 + 2; i++) {
                    for (int j = colB * 3; j <= colB * 3 + 2; j++) {
                        if (dbox[rowB][colB][x - '0'])
                            return false;
                    }
                }
                drow[row][x - '0'] = true;
                dcol[col][x - '0'] = true;
                dbox[rowB][colB][x - '0'] = true;
            }
        }
        return true;
    }
};

int main() {
    vector <vector<char>> board = {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
    };
    Solution sol;
    cout << sol.isValidSudoku(board);
}