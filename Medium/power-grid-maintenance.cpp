#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void bfs(int t, vector<vector<int>> &conn, vector<int> &check, int index) {
        queue<int> q;
        q.push(t);
        while (!q.empty()) {
            int curr = q.front();
            check[curr] = index;
            for (auto x: conn[curr]) {
                if (check[x] == -1) {
                    q.push(x);
                }
            }
            q.pop();
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<set<int>> group;
        vector<vector<int>> conn(c + 1);
        vector<int> check(c + 1, -1);
        int index = -1;

        for (auto x: connections) {
            conn[x[0]].push_back(x[1]);
            conn[x[1]].push_back(x[0]);
        }

        for (int i = 1; i <= c; i++) {
            if (check[i] == -1) {
                index++;
                bfs(i, conn, check, index);
            }
        }

        group.resize(index + 1);
        for (int i = 1; i <= c; i++) {
            int g = check[i];
            group[g].insert(i);
        }

        vector<int> ans;

        for (auto query: queries) {
            int x = query[1];
            int g = check[x];
            auto it = group[g].find(x);
            if (query[0] == 1) {
                if (it != group[g].end())
                    ans.push_back(x);
                else {
                    if (group[g].size() > 0)
                        ans.push_back(*group[g].begin());
                    else
                        ans.push_back(-1);
                }
            } else {
                if (it != group[g].end())
                    group[g].erase(it);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int c = 5;
    vector<vector<int>> connections = {{1,2},{2,3},{3,4},{4,5}};
    vector<vector<int>> queries = {{1,3},{2,1},{1,1},{2,2},{1,2}};

    // vector<vector<int>> connections = {{1,3},{1,5},{2,4}};
    // vector<vector<int>> queries = {{1,1}, {1, 5}, {2, 1}, {2, 3}, {2, 5}, {1, 1}, {2, 2},{1, 2}};
    vector<int> ans = sol.processQueries(c, connections, queries);
    for (auto x: ans)
        cout << x << " ";
}