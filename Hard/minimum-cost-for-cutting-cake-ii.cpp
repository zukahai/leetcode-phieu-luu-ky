#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        long long cntRow = 1, cntCol = 1;
        int index1 = 0, index2 = 0;
        long long cost = 0;
        while (index1 < m - 1 && index2 < n - 1) {
            if (horizontalCut[index1] > verticalCut[index2]) {
                cost += 1LL * horizontalCut[index1] * cntCol;
                cntRow++;
                index1++;
            } else {
                cost += 1LL* verticalCut[index2] * cntRow;
                cntCol++;
                index2++;
            }
        }

        while (index1 < m - 1) {
            cost += 1LL * horizontalCut[index1] * cntCol;
            cntRow++;
            index1++;
        }

        while (index2 < n - 1) {
            cost += 1LL* verticalCut[index2] * cntRow;
            cntCol++;
            index2++;
        }
        return cost;
    }
};

int main() {
    Solution sol;
    int m = 3, n = 2;
    vector<int> horizontalCut = {1,3};
    vector<int> verticalCut = {5};
    cout << sol.minimumCost(m, n, horizontalCut, verticalCut);
}