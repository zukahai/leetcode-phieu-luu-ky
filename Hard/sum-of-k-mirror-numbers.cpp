#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<long long> s;
public:
    void gen() {
        vector<long long> temp;
        for (int i = 1; i <= 6e5; i++) {
            string s1 = to_string(i);
            string p = s1;
            reverse(p.begin(), p.end());
            s.push_back(stoll(s1 + p));
            s.push_back(stoll(s1 + p.substr(1, p.size() - 1)));
        }
        sort(s.begin(), s.end());
    }

    string baseK(long long n, int k) {
        string ans = "";
        while (n != 0) {
            ans += char(n % k + '0');
            n /= k;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool check(long long n, int k) {
        string base = baseK(n, k);
        string rebase = base;
        reverse(rebase.begin(), rebase.end());
        return rebase == base;
    }


    long long kMirror(int k, int n) {
        gen();
        int index = 0;
        long long sum = 0;
        for (long long x: s) {
            if (check(x, k)) {
                sum += x;
                if (++index == n) 
                    break;
            }
        }
        return sum;
    }
};

int main() {
    for (int k = 2; k <= 9; k++) {
        cout << "K = " << k << endl; 
        cout << "{0";
        for (int n = 1; n <= 30; n++) {
            Solution sol;
            cout << ", " << sol.kMirror(k, n);
        }
        cout << "}";
        cout << endl;
    }
}