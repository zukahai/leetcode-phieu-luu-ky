#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int max = *max_element(height.begin(), height.end());
        int fmax = 0, lmax = height.size() - 1;;
        for (int i = 1; i < height.size(); i++)
            if (height[i] == max) {
                fmax = i;
                break;
            }
        for (int i = height.size() - 1; i >= 0; i--)
            if (height[i] == max) {
                lmax = i;
                break;
            }
        for (int i = fmax; i <= lmax; i++) {
            if (height[i] < max) {
                res += (max - height[i]);
            }
        }

        for (int i = 1; i < fmax; i++) {
            if (height[i] < height[i - 1]) {
                res += (height[i - 1] - height[i]);
                height[i] = height[i - 1];
            }
        }

        for (int i = (int)height.size() - 2; i >= lmax; i--) {
            if (height[i] < height[i + 1]) {
                res += (height[i + 1] - height[i]);
                height[i] = height[i + 1];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector <int> height = {4,2,0,3,2,5};
    cout << sol.trap(height);
}