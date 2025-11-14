#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count(int m, int n, int x) {
        int cnt = 0;
        for (int row = 1; row <= m; row ++) {
            if (row > x) break;
            int col = x / row;
            if (row * n <= x)
                col = n;
            cnt += col;
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        int res = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = count(m, n, mid);
            if (cnt >= k) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int m = 3;
    int n = 3;
    cout << sol.findKthNumber(m, n, 1);
}