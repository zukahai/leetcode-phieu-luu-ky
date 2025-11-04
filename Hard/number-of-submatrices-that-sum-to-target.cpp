#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> prefix;
public:
    int getSum(int col, int row1, int row2) {
        if (row1 == 0)
            return prefix[col][row2];
        return prefix[col][row2] - prefix[col][row1 - 1];
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix.resize(n, vector<int>(m, 0));
        for (int col = 0; col < n; col++) {
            prefix[col][0] = matrix[0][col];
            for (int row = 1; row < m; row++)
                prefix[col][row] = prefix[col][row - 1] + matrix[row][col];
        }

        int res = 0;

        
        for (int row1 = 0; row1 < m; row1++) {
            for (int row2 = row1; row2 < m; row2++) {
                int sum = 0;
                vector <int> cnt(2e8 + 100, 0);
                cnt[1e8] = 1;
                for (int col = 0; col < n; col++) {
                    sum += getSum(col, row1, row2);
                    res += cnt[sum - target + 1e8];
                    cnt[sum + 1e8]++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector <vector<int>> matrix = {{0,1,1,1,0,1},{0,0,0,0,0,1},{0,0,1,0,0,1},{1,1,0,1,1,0},{1,0,0,1,0,0}};
    int target = 0;
    cout << sol.numSubmatrixSumTarget(matrix, target);
}