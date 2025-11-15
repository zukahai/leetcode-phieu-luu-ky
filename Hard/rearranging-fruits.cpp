#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> cnt, cnt1;
        vector<int> move12, move21;
        for (auto x: basket1){
            cnt[x]++;
            cnt1[x]++;
        } 
        for (auto x: basket2) cnt[x]++;
        int minNum = INT_MAX;
        for (auto x: cnt) {
            if (x.second % 2 != 0)
                return -1;
            minNum = min(minNum, x.first);
        }
            
        for (auto x: cnt) {
            if (cnt1[x.first] < cnt[x.first] / 2) 
                for (int i = 1; i <= cnt[x.first] / 2 - cnt1[x.first]; i++)
                    move21.push_back(x.first);
            if (cnt1[x.first] > cnt[x.first] / 2) 
                for (int i = 1; i <= cnt1[x.first]- cnt[x.first] / 2; i++)
                    move12.push_back(x.first);
        }

        sort(move12.begin(), move12.end());
        sort(move21.rbegin(), move21.rend());

        long long cost = 0;
        for (int i = 0; i < move12.size(); i++) {
            cost += min(min(move12[i], move21[i]), 2 * minNum);
        }
        return cost;
    }
};

int main() {
    Solution sol;
    vector<int> basket1 = {84,80,43,8,80,88,43,14,100,88};
    vector<int> basket2 = {32,32,42,68,68,100,42,84,14,8};
    cout << sol.minCost(basket1, basket2);
}