#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> maxSell(k + 1, 0);
        int preMin = INT_MAX;
        int preMax = 0;
        for (int price: prices) {
            for (int j = 1; j <= k; j++) {
                preMin = min(preMin, price - maxSell[j - 1]);
                maxSell[j] = max(maxSell[j], price - preMin);
            }
        }
        return maxSell[k];
    }
};



// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         vector<int> minBuy(k + 1, INT_MAX);
//         vector<int> maxSell(k + 1, 0);
//         for (int price: prices) {
//             for (int j = 1; j <= k; j++) {
//                 minBuy[j] = min(minBuy[j], price - maxSell[j - 1]);
//                 maxSell[j] = max(maxSell[j], price - minBuy[j]);
//             }
//         }
//         return maxSell[k];
//     }
// };