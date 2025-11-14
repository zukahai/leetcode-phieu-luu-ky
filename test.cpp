#include <bits/stdc++.h>

using namespace std;

int b[1000005];

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    long long sumAll = accumulate(b + 1, b + n + 1, 0LL);
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sum[a[i]] += b[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * b[i] * (sumAll - sum[a[i]]);
    }
    cout << ans / 2 << endl;
}

