#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while (n != 0) {
            ans *= 2;
            n /= 2;
        }
        return ans - 1;
    }
};

int main() {
    Solution sol;
    cout << sol.smallestNumber(1000000000);
}