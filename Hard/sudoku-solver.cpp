#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool drow[9][10], dcol[9][10], dbox[28][28][10];
public:
    bool check(vector<vector<char>>& board, int row, int col, char x) {
        if (drow[row][x - '0']) return false;
        if (dcol[col][x - '0']) return false;
        if (dbox[row / 3][col / 3][x - '0']) return false;
        return true;
    }

    void setup(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    char x = board[row][col];
                    drow[row][x - '0'] = true;
                    dcol[col][x - '0'] = true;
                    dbox[row / 3][col / 3][x - '0'] = true;
                }
            }
        }
    }
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (int x = '1'; x <= '9'; x++) {
                        if (check(board, row, col, x)) {
                            board[row][col] = x;
                            drow[row][x - '0'] = true;
                            dcol[col][x - '0'] = true;
                            dbox[row / 3][col / 3][x - '0'] = true;
                            if (solve(board)) {
                                return true;
                            }
                            board[row][col] = '.';
                            drow[row][x - '0'] = false;
                            dcol[col][x - '0'] = false;
                            dbox[row / 3][col / 3][x - '0'] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void printBoard(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        setup(board);
        solve(board);
        printBoard(board);
    }
};

int main() {
    vector <vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    sol.solveSudoku(board);
}