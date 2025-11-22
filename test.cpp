#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i != j && j != k && i != k) {
                    string combined = a[i] + a[j] + a[k];
                    if (checkPalindrome(combined)) {
                        cout << i << " " << j << " " << k << endl;
                    }
                }
            }
        }
    }
    
}

