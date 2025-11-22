#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int index = 0; 
        while (index < n - 1) 
            index += (bits[index] + 1);
        return index == n - 1;
    }
};

int main() {
    Solution sol;
    vector<int> bits = {1, 1, 0};
    cout << sol.isOneBitCharacter(bits);
}