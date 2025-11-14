#include <bits/stdc++.h>

using namespace std;

bool check[209][209][209];

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int col = 0; col < n; col++) {
            for (int rowS = 0; rowS < m; rowS++) {
                for (int rowE = rowS; rowE < m; rowE++) {
                    check[col][rowS][rowE] = false;
                }
            }
        }
        for (int col = 0; col < n; col++) {
            for (int rowS = 0; rowS < m; rowS++) {
                for (int rowE = rowS; rowE < m; rowE++) {
                    if (matrix[rowE][col] == '1') {
                        check[col][rowS][rowE] = true;
                    } else {
                        break;
                    }
                }
            }
        }
        int res = 0;
        for (int rowS = 0; rowS < m; rowS++) {
            for (int rowE = rowS; rowE < m; rowE++) {
                int len = 0, cnt = 0;
                for (int col = 0; col < n; col++) {
                    if (check[col][rowS][rowE])
                        cnt++;
                    else    
                        cnt = 0;
                    len = max(cnt, len);
                }
                res = max(res, len * (rowE - rowS + 1));
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> matrix = {{'0'}};
    // vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << sol.maximalRectangle(matrix);
}