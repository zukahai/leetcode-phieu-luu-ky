#include <bits/stdc++.h>

using namespace std;

int n;
int x[100];
void loop(int index) {
    for (int i = 1; i <= 4; i++) {
        x[index] = i;
        if (index < n)
            loop(index + 1);
        else {
            for (int j = 1; j <= n; j++)
                cout << x[j] << " ";
            cout << endl;
        }
    }
}

int main() {
    cin >> n;
    loop(1);
}