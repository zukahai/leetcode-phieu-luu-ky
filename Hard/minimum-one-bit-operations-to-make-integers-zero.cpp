#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decToBin(int n) {
        if (n == 0) return "0";
        string ans = "";
        while (n != 0) {
            ans += (char)(n % 2 + '0');
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int minimumOneBitOperations(int n) {
        string bin = decToBin(n);
        vector <int> val(bin.size());
        val[bin.size() - 1] = 1;
        for (int i = (int)bin.size() - 2; i >= 0; i--) {
            val[i] = val[i + 1] * 2 + 1;
        }
        int sum = 0;
        int d = 1;
        for (int i = 0; i < bin.size(); i++) {
            if (bin[i] == '1') {
                sum += val[i] * d;
                d *= (-1);
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    cout << sol.minimumOneBitOperations(6); 
}