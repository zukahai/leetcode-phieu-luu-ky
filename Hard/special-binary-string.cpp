#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector <string> gr;
        string p = "";
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            p += s[i];
            if (s[i] == '1')
                cnt++;
            else
                cnt--;
            if (cnt == 0) {
                gr.push_back("1" + makeLargestSpecial(p.substr(1, p.size() - 2)) + "0");
                p = "";
            }
        }
        string ans = "";
        sort(gr.begin(), gr.end(), greater<string>());
        for (string x: gr)
            ans += x;
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.makeLargestSpecial("11011000");
}