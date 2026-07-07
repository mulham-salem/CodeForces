#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>

using namespace std;

const double INF = 1e18;

struct Point {
    double x, y;
};

struct Trench {
    Point p1, p2;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double distToSegment(Point p, Point s1, Point s2) {
    double l2 = (s1.x - s2.x) * (s1.x - s2.x) + (s1.y - s2.y) * (s1.y - s2.y);
    if (l2 == 0) return dist(p, s1);
    double t = ((p.x - s1.x) * (s2.x - s1.x) + (p.y - s1.y) * (s2.y - s1.y)) / l2;
    t = max(0.0, min(1.0, t));
    Point projection = {s1.x + t * (s2.x - s1.x), s1.y + t * (s2.y - s1.y)};
    return dist(p, projection);
}

double distBetweenSegments(Point a1, Point a2, Point b1, Point b2) {
    double d = distToSegment(a1, b1, b2);
    d = min(d, distToSegment(a2, b1, b2));
    d = min(d, distToSegment(b1, a1, a2));
    d = min(d, distToSegment(b2, a1, a2));
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    if (!(cin >> a >> b)) return 0;

    Point A, B;
    cin >> A.x >> A.y >> B.x >> B.y;

    int n;
    cin >> n;

    vector<Trench> trenches(n);
    for (int i = 0; i < n; ++i) {
        cin >> trenches[i].p1.x >> trenches[i].p1.y >> trenches[i].p2.x >> trenches[i].p2.y;
    }

    int total_nodes = n + 2;
    int src = 0, dst = n + 1;

    vector<vector<double>> g_dist(total_nodes, vector<double>(total_nodes, 0));

    g_dist[src][dst] = g_dist[dst][src] = dist(A, B);

    for (int i = 0; i < n; ++i) {
        g_dist[src][i + 1] = g_dist[i + 1][src] = distToSegment(A, trenches[i].p1, trenches[i].p2);
        g_dist[dst][i + 1] = g_dist[i + 1][dst] = distToSegment(B, trenches[i].p1, trenches[i].p2);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double d = distBetweenSegments(trenches[i].p1, trenches[i].p2, trenches[j].p1, trenches[j].p2);
            g_dist[i + 1][j + 1] = g_dist[j + 1][i + 1] = d;
        }
    }

    vector<double> min_time(total_nodes, INF);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    min_time[src] = 0;
    pq.push({0.0, src});

    while (!pq.empty()) {
        auto [curr_time, u] = pq.top();
        pq.pop();

        if (curr_time > min_time[u]) continue;
        if (u == dst) break;

        for (int v = 0; v < total_nodes; ++v) {
            if (u == v) continue;

            double d = g_dist[u][v];
            if (d > a) continue;

            double next_time = curr_time;


            double cycle_len = a + b;
            double time_in_cycle = fmod(next_time, cycle_len);


            if (time_in_cycle > a) {
                next_time += (cycle_len - time_in_cycle);
                time_in_cycle = 0;
            }

            if (a - time_in_cycle < d) {
                next_time += (cycle_len - time_in_cycle);
            }

            next_time += d;

            if (v != dst && v != src) {
                double trench_len = dist(trenches[v - 1].p1, trenches[v - 1].p2);
                next_time += trench_len;
            }

            if (next_time < min_time[v]) {
                min_time[v] = next_time;
                pq.push({next_time, v});
            }
        }
    }

    if (min_time[dst] >= INF) {
        cout << -1 << "\n";
    } else {
        cout << fixed << setprecision(10) << min_time[dst] << "\n";
    }

    return 0;
}
