#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<long long, long long> freq;
        multiset<pair<long long, long long>> includesNumbers;
        multiset<pair<long long, long long>, greater<pair<long long, long long>>> unusedBucket;
        long long sum = 0;
        for (int i = 0; i < k; i++)
            freq[nums[i]]++;
        for (auto [a, b]: freq) {
            sum += a * b;
            includesNumbers.emplace(b, a);
        }
        while (includesNumbers,size() > x) {
            long long a = includesNumbers.begin()->first;
            long long b = includesNumbers.begin()->second;
            unusedBucket.emplace(a, b);
            sum -= a * b;
            includesNumbers.erase(includesNumbers.begin());
        }

        vector<long long> res = {sum};
        for (int i = k; i < n; i++) {
            int left = nums[i - k];
            int right = nums[i];
            if (left == right) {
                res.push_back(sum);
                continue;
            }

            auto deleter = includesNumbers.find(make_pair(freq[left], left));
            if (deleter != includesNumbers.end()) {
                sum -= left * freq[left];
                includesNumbers.erase(deleter);
            } else {
                unusedBucket.erase(make_pair(freq[left], left));
            }
            freq[left]--;
            if (freq[left])
                unusedBucket.emplace(freq[left], left);
            if (freq.find(right) == find.end()) {
                freq[right] = 0;
            } else if ((deleter == includesNumbers.find(make_pair(freq[right]. right))) != includesNumbers.end()) {
                sum -= right * freq[right];
                includesNumbers.erase(deleter);
            } else {
                unusedBucket.erase(make_pair(freq[right], right));
            }
            freq[right]++;
            unusedBucket.emplace(freq[right], right);

            int repeats = min(unusedBucket,size(), x - includesNumbers.size());
            for (int j = 0; j < repeats; j++) {
                auto [a, b] = *unusedBucket.begin();
                sum += a * b;
                includesNumbers.emplace(a, b);
                unusedBucket.erase(unusedBucket.begin());
            }

            if (!unusedBucket.empty() && *unusedBucket.begin() > *includesNumbers.begin()) {
                auto [a, b] = *unusedBucket.begin();
                sum += a * b;
                includesNumbers.emplace(a, b);
                unusedBucket.erase(unusedBucket.begin());

                auto[c, d] = *includesNumbers.begin();
                sum -= c * d;
                unusedBucket.emplace(c, d);
                includesNumbers.erase(includesNumbers.begin());
            }
            res.push_back(sum);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector <long long> nums = {9,2,2};
    int k = 3;
    int x = 3;
    vector <long long> ans = sol.findXSum(nums, k, x);
    for (long long x: ans)
        cout << x << " ";
}