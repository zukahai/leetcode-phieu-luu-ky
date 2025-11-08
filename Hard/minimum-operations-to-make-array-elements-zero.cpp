#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long cost(int n) {
        long long ans = 0;
        long long pow4 = 1;
        while (pow4 <= n) {
            ans += (n - pow4 + 1);
            pow4 *= 4;
        }
        return ans;
    }
    long long cost(int l, int r) {
        return cost(r) - cost(l - 1);
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long sum = 0;
        for (auto query: queries) {
            int l = query[0], r = query[1];
            long long c = cost(l, r);
            sum += (c + 1) / 2;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> queries = {{1, 2}, {2, 4}};
    cout << sol.minOperations(queries);
}