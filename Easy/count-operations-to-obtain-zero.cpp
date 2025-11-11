#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        while (num1 > 0 && num2 > 0) {
            cnt += num1 / num2;
            int d = num1 % num2;
            num1 = num2;
            num2 = d;
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    int num1 = 3;
    int num2 = 2;
    cout << sol.countOperations(num1, num2);
}