#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector <vector<int>> arr;
        for (int i = 0; i < plantTime.size(); i++) {
            arr.push_back({growTime[i], plantTime[i]});
        }
        sort(arr.begin(), arr.end(), greater<vector<int>>());

        int time = INT_MIN;
        int sumPlantTime = 0;

        for (auto x: arr) {
            sumPlantTime += x[1];
            time = max(time, sumPlantTime + x[0]);
        }
        return time;
    }
};

int main() {
    Solution sol;
    vector <int> plantTime = {40,1,3};
    vector <int> growTime = {3,2,100};
    cout << sol.earliestFullBloom(plantTime, growTime);
}