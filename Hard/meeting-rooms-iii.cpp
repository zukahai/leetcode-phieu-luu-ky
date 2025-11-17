#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> cnt(n, 0);
        vector<long long> endRoom(n, 0);
        for (auto meeting: meetings) {
            int start = meeting[0];
            int end = meeting[1];
            int indexRoom = -1;
            for (int i = 0; i < n; i++) {
                if (start >= endRoom[i]) {
                    indexRoom = i;
                    break;
                }
            }
            if (indexRoom != -1) {
                cnt[indexRoom]++;
                endRoom[indexRoom] = end;
            } else {
                indexRoom = -1;
                long long minEnd = LLONG_MAX;
                for (int i = 0; i < n; i++) {
                    if (endRoom[i] < minEnd) {
                        minEnd = endRoom[i];
                        indexRoom = i;
                    }
                }
                cnt[indexRoom]++;
                endRoom[indexRoom] = endRoom[indexRoom] + (end - start);
            }
        }

        
        int res = 0;
        int maxCnt = cnt[0];
        for (int i = 1; i < n; i++) {
            if (maxCnt < cnt[i]) {
                maxCnt = cnt[i];
                res = i;
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> meetings = {{1,20},{2,10},{3,5},{4,9},{6,8}};
    cout << sol.mostBooked(n, meetings);
}