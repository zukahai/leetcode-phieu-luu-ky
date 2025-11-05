#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<long long, long long> freq;
    freq[10] = -3;
    freq[20] = 5;
    for (auto [a, b]: freq)
        cout << a << " " << b << endl;
}