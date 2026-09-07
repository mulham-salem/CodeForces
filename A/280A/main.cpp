#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-10;

double polygon_area(vector<pair<double, double>>& pts) {
    double area = 0;
    int n = pts.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += pts[i].first * pts[j].second;
        area -= pts[j].first * pts[i].second;
    }
    return fabs(area) / 2.0;
}

pair<double, double> intersect_lines(double x1, double y1, double x2, double y2,
                                      double x3, double y3, double x4, double y4) {
    double d = (x2-x1)*(y4-y3) - (y2-y1)*(x4-x3);
    if (fabs(d) < eps) return {1e100, 1e100};
    double t = ((x3-x1)*(y4-y3) - (y3-y1)*(x4-x3)) / d;
    return {x1 + t*(x2-x1), y1 + t*(y2-y1)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double w, h, alpha;
    cin >> w >> h >> alpha;

    alpha = alpha * PI / 180.0;

    // Rectangle 1 (axis-aligned)
    vector<pair<double, double>> rect1 = {
        {-w/2, -h/2}, {w/2, -h/2}, {w/2, h/2}, {-w/2, h/2}
    };

    // Rectangle 2 (rotated)
    vector<pair<double, double>> rect2;
    for (auto p : rect1) {
        double x = p.first * cos(alpha) - p.second * sin(alpha);
        double y = p.first * sin(alpha) + p.second * cos(alpha);
        rect2.push_back({x, y});
    }

    // Clip rect1 by rect2 (Sutherland-Hodgman)
    vector<pair<double, double>> poly = rect1;
    for (int edge = 0; edge < 4; edge++) {
        vector<pair<double, double>> new_poly;
        int j = (edge + 1) % 4;
        double ax = rect2[edge].first, ay = rect2[edge].second;
        double bx = rect2[j].first, by = rect2[j].second;

        for (int i = 0; i < poly.size(); i++) {
            int k = (i + 1) % poly.size();
            double px = poly[i].first, py = poly[i].second;
            double qx = poly[k].first, qy = poly[k].second;

            // Check if point is inside (left of edge)
            double cross1 = (bx - ax) * (py - ay) - (by - ay) * (px - ax);
            double cross2 = (bx - ax) * (qy - ay) - (by - ay) * (qx - ax);

            if (cross1 >= -eps) new_poly.push_back({px, py});
            if ((cross1 > eps && cross2 < -eps) || (cross1 < -eps && cross2 > eps)) {
                // Intersection point
                auto inter = intersect_lines(px, py, qx, qy, ax, ay, bx, by);
                if (inter.first != 1e100) new_poly.push_back(inter);
            }
        }
        poly = new_poly;
    }

    double ans = polygon_area(poly);
    cout << fixed << setprecision(12) << ans << "\n";

    return 0;
}
