#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        long long ans = target[0];
        for (int i = 1; i < target.size(); i++)
            if (target[i] > target[i - 1])
                ans += (target[i] - target[i - 1]);
        return ans;
    }
};

int main() {
    vector <int> target = {10, 1, 1, 10};
    Solution sol;
    cout << sol.minNumberOperations(target);
}