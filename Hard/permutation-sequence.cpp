#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector <int> list;
        string ans = "";
        for (int i = 0; i <= n; i++)
            list.push_back(i);
        vector <int> fac(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i;
        for (int index = n; index >= 1; index--) {
            // cout << "Index ---------- " << index << endl;
            int t = (k - 1) / fac[index - 1] + 1;
            // cout << "T = " << t << endl; 
            ans += char(list[t] + '0');
            // cout << ans << endl;
            list.erase(list.begin() + t);
            // for (auto x: list)
            //     cout << x << " ";
            // cout << endl;
            
            k -= ((t - 1) * fac[index - 1]);
            // cout << "K = " << k << endl;
            // cout << "Ket thuc index " << index << endl;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.getPermutation(5, 70);
}


// class Solution {
// private:
//     vector <bool> check;
//     string str;
//     vector <string> ans;
// public:
//     void solve(int index, int n) {
//         if (index == n) {
//             string t = "";
//             for (int i = 0; i < n; i++)
//                 t += str[i];
//             ans.push_back(t);
//             return;
//         }
//         for (int i = 1; i <= n; i++) {
//             if (check[i]) {
//                 check[i] = false;
//                 str[index] = (char)(i + 48);
//                 solve(index + 1, n);
//                 check[i] = true;
//             }
//         }
//     }
//     string getPermutation(int n, int k) {
//         check.resize(n + 1, true);
//         str = string(n, ' ');
//         solve(0, n);
//         for (auto x: ans)
//             cout << x << endl;
//         return ans[k - 1];
//     }
// };