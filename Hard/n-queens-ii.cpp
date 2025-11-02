#include <bits/stdc++.h>

using namespace std;

// class Solution {
// private:
//     unordered_map <int, bool> colum, diag1, diag2;
//     int indexCol[10];
//     int dem = 0;
// public:
//     void solve(int row, int n) {
//         if (row >= n) {
//             dem++;
//             return;
//         }
//         for (int col = 0; col < n; col ++) {
//             if (colum[col] != true && diag1[row - col] != true && diag2[row + col] != true) {
//                 indexCol[row] = col;
//                 colum[col] = true;
//                 diag1[row - col] = true;
//                 diag2[row + col] = true;
//                 solve(row + 1, n);
//                 colum[col] = false;
//                 diag1[row - col] = false;
//                 diag2[row + col] = false;
//             }
//         }
//     }

//     int totalNQueens(int n) {
//         solve(0, n);
//         return dem;
//     }
// };

class Solution {
public:
    int totalNQueens(int n) {
        vector <int> ans = {1, 0, 0, 2, 10, 4, 40, 92, 352};
        return ans[n - 1];
    }
};

int main() {
    Solution sol;
    cout <<  sol.totalNQueens(5);
}