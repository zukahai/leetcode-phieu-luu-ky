#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        int max = neededTime[0];
        int sum = neededTime[0];
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                if (max < neededTime[i])
                    max = neededTime[i];
                sum += neededTime[i];
            } else {
                ans += (sum - max);
                max = sum = neededTime[i];
            }
        }
        ans += (sum - max);
        return ans;
    }
};

int main() {
    Solution sol;
    string colors = "a";
    vector <int> neededTime = {1};
    cout << sol.minCost(colors, neededTime);
}