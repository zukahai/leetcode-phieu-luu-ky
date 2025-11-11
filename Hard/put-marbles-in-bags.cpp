#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) return 0;
        vector <int> sum;
        for (int i = 1; i < weights.size(); i++)
            sum.push_back(weights[i] + weights[i - 1]);
        sort(sum.begin(), sum.end());
        long long minScore = weights[0] + weights.back();
        for (int i = 0; i < k - 1; i++) 
            minScore += sum[i];
        long long maxScore = weights[0] + weights.back();
        for (int i = sum.size() - (k - 1); i < sum.size(); i++)
            maxScore += sum[i];
        return maxScore - minScore;
    }
};

int main() {
    Solution sol;
    vector<int> weights = {1,3,5,1};
    int k = 2;
    cout << sol.putMarbles(weights, k); 
}