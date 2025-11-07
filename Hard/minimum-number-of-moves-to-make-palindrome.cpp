#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int res = 0;
        while (s.size() > 0) {
            int index = s.find(s.back());
            if (index == s.size() - 1)
                res += s.size() / 2;
            else {
                res += index;
                s.erase(index, 1);
            }
            s.pop_back();
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.minMovesToMakePalindrome("aabbc");
}