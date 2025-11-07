#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int ans = 0;
        int sumArr = 0, sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum = sum + sumArr + satisfaction[i];
            sumArr += satisfaction[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector <int> satisfaction = {-1,-8,0,5,-9};
    cout << sol.maxSatisfaction(satisfaction);
}

// class Solution {
// public:
//     int maxSatisfaction(vector<int>& satisfaction) {
//         sort(satisfaction.begin(), satisfaction.end());
//         int n = satisfaction.size();
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             int time = 1;
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += satisfaction[j] * time;
//                 time++; 
//             }
//             ans = max(ans, sum);
//         }
//         return ans;
//     }
// };