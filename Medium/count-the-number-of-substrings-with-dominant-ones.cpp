#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> ones(n + 1, 0);
        for (int i = 0; i < n; i++)
            ones[i + 1] = ones[i] + (s[i] == '1');

        vector<int> zero;
        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                zero.push_back(i);

        long long ans = 0;
        int z = zero.size();
        int K = sqrt(n) + 2;

        for (int l = 0; l < n; l++) {
            int idx = lower_bound(zero.begin(), zero.end(), l) - zero.begin();

            int until = (idx < z ? zero[idx] : n);
            ans += (until - l);

            for (int k = 1; k <= K; k++) {
                if (idx + k - 1 >= z) break;

                int r_zero = zero[idx + k - 1];
                int r_low = r_zero;
                int r_high = (idx + k < z ? zero[idx + k] - 1 : n - 1);

                int need = k * k;
                int have_max = ones[r_high + 1] - ones[l];
                if (have_max < need) continue;

                int left = r_low, right = r_high, best = r_high + 1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    int cur1 = ones[mid + 1] - ones[l];
                    if (cur1 >= need) {
                        best = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }

                if (best <= r_high)
                    ans += (r_high - best + 1);
            }
        }

        return ans;
    }
};


int main() {
    Solution sol;
    string s = "00011";
    cout << sol.numberOfSubstrings(s);
}