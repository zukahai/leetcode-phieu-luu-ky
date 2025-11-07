#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int m, n, N;
    vector<string> bin;
    string s;
public:
    void solve(int index) {
        if (index == N) {
            bin.push_back(s);
            return;
        }
        for (char ch = '0'; ch <= '1'; ch++) {
            s[index] = ch;
            solve(index + 1);
        }
    }
    bool check(string str, vector<vector<int>> mat, vector<vector<int>> a) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1') {
                int row = a[i][0];
                int col = a[i][1];
                mat[row][col] = 1 - mat[row][col];
                if (row - 1 >= 0) mat[row - 1][col] = 1 - mat[row - 1][col];
                if (row + 1 < m) mat[row + 1][col] = 1 - mat[row + 1][col];
                if (col - 1 >= 0) mat[row][col - 1] = 1 - mat[row][col - 1];
                if (col + 1 < n) mat[row][col + 1] = 1 - mat[row][col + 1];
            }
        }
        for (int row = 0; row < m; row++)
            for (int col = 0; col < n; col++)
                if (mat[row][col] == 1) return false;
        return true;
    }
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        N = m * n;
        s = string(N, ' ');
        solve(0);
        vector<vector<int>> a;
        for (int row = 0; row < m; row++)
            for (int col = 0; col < n; col++) {
                a.push_back({row, col});
            }
        int res = INT_MAX;
        for (string str: bin) {
            if (check(str, mat, a)) {
                int cnt = 0;
                for (char ch: str)
                    cnt += (ch == '1');
                res = min(cnt, res);
            }
        }
        return (res == INT_MAX) ? -1 : res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{0,0},{0,1}};
    cout << sol.minFlips(mat);
}