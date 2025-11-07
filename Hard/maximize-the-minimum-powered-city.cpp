#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int>& stations, int r, long long minPower, int k) {
        int n = stations.size();
        long long windowPower = accumulate(stations.begin(), stations.begin() + r, 0LL);
        vector <int> additions(n, 0);

        for (int i = 0; i < n; i++) {
            if (i + r < n) {
                windowPower += stations[i + r];
            }
            if (windowPower < minPower) {
                long long needed = minPower - windowPower;
                if (needed > k) return false;
                additions[min(n - 1, i + r)] += needed;
                windowPower = minPower;
                k -= needed;
            }
            if (i - r >= 0) {
                windowPower -= stations[i - r] + additions[i - r];
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long long left = 0;
        long long right = 2e10;
        long long ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (check(stations, r, mid, k)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector <int> stations = {1,2,4,5,0};
    int r = 1;
    int k = 2;
    cout << sol.maxPower(stations, r, k);
}