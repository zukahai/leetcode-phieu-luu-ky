#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double dist(double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    }

    int numPoints(vector<vector<int>>& points, int r) {
        int n = points.size();
        if (n <= 1) return n;

        int ans = 1;
        double rr = r * 1.0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {

                double d = dist(points[i][0], points[i][1],
                                points[j][0], points[j][1]);

                if (d > 2.0 * rr) continue; // không thể tạo đường tròn chứa cả 2 điểm

                // trung điểm
                double mx = (points[i][0] + points[j][0]) / 2.0;
                double my = (points[i][1] + points[j][1]) / 2.0;

                // tính khoảng cách từ trung điểm đến tâm
                double h = sqrt(rr * rr - (d / 2.0) * (d / 2.0));

                // vector AB
                double vx = points[j][0] - points[i][0];
                double vy = points[j][1] - points[i][1];

                // vector vuông góc, chuẩn hóa
                double len = sqrt(vx * vx + vy * vy);
                double px = -vy / len;
                double py = vx / len;

                // hai tâm đường tròn
                double cx1 = mx + px * h;
                double cy1 = my + py * h;
                double cx2 = mx - px * h;
                double cy2 = my - py * h;

                // đếm điểm trong tâm 1
                int cnt1 = 0, cnt2 = 0;
                for (auto &p : points) {
                    if (dist(cx1, cy1, p[0], p[1]) <= rr + 1e-7) cnt1++;
                    if (dist(cx2, cy2, p[0], p[1]) <= rr + 1e-7) cnt2++;
                }

                ans = max(ans, max(cnt1, cnt2));
            }
        }

        return ans;
    }
};
