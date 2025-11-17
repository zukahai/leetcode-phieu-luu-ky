#include <bits/stdc++.h>

using namespace std;

int dem[1000005];
int a[1000005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        dem[a[i]]++;
    }
    int maxDem = dem[0];
    int indexMax = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (maxDem < dem[i]) {
            maxDem = dem[i];
            indexMax = i;
        }
    }
    cout << indexMax;
}

