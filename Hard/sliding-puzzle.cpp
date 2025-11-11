#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string targer = "123450";
        string start = "";
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                start += (char)(board[i][j] + '0');
        vector<vector<int>> moves = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        queue<pair<string, int>> q;
        unordered_map<string, bool> check;
        q.push({start, 0});
        while (!q.empty()) {
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (curr == targer)
                return steps;
            int index = curr.find("0");
            for (int x: moves[index]) {
                string next = curr;
                swap(next[x], next[index]);
                if (check.find(next) == check.end()) {
                    q.push({next, steps + 1});
                    check[next] = true;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> board = {{4,1,2},{5,0,3}};
    cout << sol.slidingPuzzle(board);
}