#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tilingRectangle(int n, int m) {
        vector <vector<int>> ans = {
            {},
            {0, 1},
            {0, 2, 1},
            {0, 3, 3, 1},
            {0, 4, 2, 4, 1},
            {0, 5, 4, 4, 5, 1},
            {0, 6, 3, 2, 3, 5, 1},
            {0, 7, 5, 5, 5, 5, 5, 1},
            {0, 8, 4, 5, 2, 5, 4, 7, 1},
            {0, 9, 6, 3, 6, 6, 3, 6, 7, 1},
            {0, 10, 5, 6, 4, 2, 4, 6, 5, 6, 1},
            {0, 11, 7, 6, 6, 6, 6, 6, 6, 7, 6, 1},
            {0, 12, 6, 4, 3, 6, 2, 6, 3, 4, 5, 7, 1},
            {0, 13, 8, 7, 7, 6, 6, 6, 6, 7, 7, 6, 7, 1},
        };
        if (n > m) swap(n, m);
        return ans[m][n];
    }
};

int main() {
    for (int m = 1; m <= 13; m++) {
        cout << "m = " << m << endl;
        for (int n = 1; n <= m; n++) {
            Solution sol;
            cout << sol.tilingRectangle(n, m) << ", ";
        }
        cout << endl;
    }
}