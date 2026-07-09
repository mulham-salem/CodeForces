#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> moves(n);
    for (int i = 0; i < n; i++) {
        cin >> moves[i];
    }

    // Track min and max for x, y, x+y, x-y
    int minX = 0, maxX = 0;
    int minY = 0, maxY = 0;
    int minSum = 0, maxSum = 0;
    int minDiff = 0, maxDiff = 0;

    for (string s : moves) {
        int dxMin, dxMax, dyMin, dyMax;
        int sumMin, sumMax, diffMin, diffMax;

        if (s == "UL") {
            // (0,1) or (-1,0)
            dxMin = -1; dxMax = 0;
            dyMin = 0; dyMax = 1;
            sumMin = -1; sumMax = 1; // -1+0=-1, 0+1=1
            diffMin = -1; diffMax = 0; // -1-0=-1, 0-1=-1? Actually: (0,1): diff=-1, (-1,0): diff=-1
            // Let me compute properly
            vector<pair<int,int>> opts = {{0,1}, {-1,0}};
            sumMin = INT_MAX; sumMax = INT_MIN;
            diffMin = INT_MAX; diffMax = INT_MIN;
            for (auto p : opts) {
                sumMin = min(sumMin, p.first + p.second);
                sumMax = max(sumMax, p.first + p.second);
                diffMin = min(diffMin, p.first - p.second);
                diffMax = max(diffMax, p.first - p.second);
            }
        } else if (s == "UR") {
            vector<pair<int,int>> opts = {{0,1}, {1,0}};
            sumMin = INT_MAX; sumMax = INT_MIN;
            diffMin = INT_MAX; diffMax = INT_MIN;
            for (auto p : opts) {
                sumMin = min(sumMin, p.first + p.second);
                sumMax = max(sumMax, p.first + p.second);
                diffMin = min(diffMin, p.first - p.second);
                diffMax = max(diffMax, p.first - p.second);
            }
            dxMin = 0; dxMax = 1;
            dyMin = 0; dyMax = 1;
        } else if (s == "DL") {
            vector<pair<int,int>> opts = {{0,-1}, {-1,0}};
            sumMin = INT_MAX; sumMax = INT_MIN;
            diffMin = INT_MAX; diffMax = INT_MIN;
            for (auto p : opts) {
                sumMin = min(sumMin, p.first + p.second);
                sumMax = max(sumMax, p.first + p.second);
                diffMin = min(diffMin, p.first - p.second);
                diffMax = max(diffMax, p.first - p.second);
            }
            dxMin = -1; dxMax = 0;
            dyMin = -1; dyMax = 0;
        } else if (s == "DR") {
            vector<pair<int,int>> opts = {{0,-1}, {1,0}};
            sumMin = INT_MAX; sumMax = INT_MIN;
            diffMin = INT_MAX; diffMax = INT_MIN;
            for (auto p : opts) {
                sumMin = min(sumMin, p.first + p.second);
                sumMax = max(sumMax, p.first + p.second);
                diffMin = min(diffMin, p.first - p.second);
                diffMax = max(diffMax, p.first - p.second);
            }
            dxMin = 0; dxMax = 1;
            dyMin = -1; dyMax = 0;
        } else { // ULDR
            vector<pair<int,int>> opts = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            sumMin = INT_MAX; sumMax = INT_MIN;
            diffMin = INT_MAX; diffMax = INT_MIN;
            for (auto p : opts) {
                sumMin = min(sumMin, p.first + p.second);
                sumMax = max(sumMax, p.first + p.second);
                diffMin = min(diffMin, p.first - p.second);
                diffMax = max(diffMax, p.first - p.second);
            }
            dxMin = -1; dxMax = 1;
            dyMin = -1; dyMax = 1;
        }

        minX += dxMin;
        maxX += dxMax;
        minY += dyMin;
        maxY += dyMax;
        minSum += sumMin;
        maxSum += sumMax;
        minDiff += diffMin;
        maxDiff += diffMax;
    }

    // Starting point = -displacement
    // sx in [-maxX, -minX]
    // sy in [-maxY, -minY]
    // sx+sy in [-maxSum, -minSum]
    // sx-sy in [-maxDiff, -minDiff]

    int lowX = -maxX, highX = -minX;
    int lowY = -maxY, highY = -minY;
    int lowSum = -maxSum, highSum = -minSum;
    int lowDiff = -maxDiff, highDiff = -minDiff;

    long long ans = 0;
    for (int x = lowX; x <= highX; x++) {
        int yLow = max({lowY, lowSum - x, x - highDiff});
        int yHigh = min({highY, highSum - x, x - lowDiff});

        if (yLow > yHigh) continue;

        int needParity = (n % 2 - (x % 2) + 2) % 2;
        while (yLow <= yHigh && ((yLow % 2 + 2) % 2 != needParity)) yLow++;
        if (yLow > yHigh) continue;

        ans += (yHigh - yLow) / 2 + 1;
    }

    cout << ans << "\n";

    return 0;
}
