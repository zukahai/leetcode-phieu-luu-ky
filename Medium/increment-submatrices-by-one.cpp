#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> prefix(n, vector<int> (n, 0));
        for (auto query: queries) {
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];
            for (int row = row1; row <= row2; row++) {
                prefix[row][col1] += 1;
                if (col2 + 1 < n)
                    prefix[row][col2 + 1] -= 1;
            }
        }
        for (int row = 0; row < n; row++) {
            for (int col = 1; col < n; col++) {
                prefix[row][col] += prefix[row][col - 1];
            }
        }
        return prefix;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> queries = {{0, 1, 1, 3}, {1, 2, 2, 3}};
    vector<vector<int>> res = sol.rangeAddQueries(n, queries);
    for (auto row: res) {
        for (auto x: row) 
            cout << x << " ";
        cout << endl;
    }
}