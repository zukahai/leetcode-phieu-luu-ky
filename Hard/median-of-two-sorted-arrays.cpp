#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>&nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 > len2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0, r = len1;
        while (l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = (len1 + len2 + 1) / 2 - mid1;
            int maxL1 = (mid1 == 0) ? INT_MIN: nums1[mid1 - 1];
            int minR1 = (mid1 == len1) ? INT_MAX : nums1[mid1];
            int maxL2 = (mid2 == 0) ? INT_MIN: nums2[mid2 - 1];
            int minR2 = (mid2 == len2) ? INT_MAX : nums2[mid2];

            if (maxL1 <= minR2 && maxL2 <= minR1) {
                if ((len1 + len2) % 2 == 0)
                    return (max(maxL1, maxL2) + min(minR1, minR2)) / 2.0;
                else 
                    return max(maxL1, maxL2);
            } else if (maxL1 > minR2) {
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    Solution sol;
    vector <int> nums2 = {1,2,3,5,6};
    vector <int> nums1 = {4};
    cout << sol.findMedianSortedArrays(nums1, nums2);
}