#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int getDistance(pair <int, int> a, pair <int ,int> b) {
    int diffX = a.first - b.first;
    int diffY = a.second - b.second;
    return diffX * diffX + diffY * diffY;
}

int solve(vector <pair <int, int>> &sortedX, vector <pair <int, int>> &sortedY) {
    int N = sortedX.size();
    if (N == 1) return INF;
    if (N == 2) return getDistance(sortedX[0], sortedX[1]);

    int mid = (N - 1) / 2;
    vector <pair <int, int>> XL, XR, YL, YR;
    for (int i = 0; i <= mid; i++) XL.push_back(sortedX[i]);
    for (int i = mid + 1; i < N; i++) XR.push_back(sortedX[i]);
    for (auto [x, y] : sortedY) {
        if (x <= XL.back().first) YL.emplace_back(x, y);
        else YR.emplace_back(x, y);
    }

    int minDist = min(solve(XL, YL), solve(XR, YR));
    vector <pair <int, int>> strip;
    for (auto [x, y] : sortedY) {
        if ((x - XL.back().first) * (x - XL.back().first) < minDist) strip.emplace_back(x, y);
    }

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size(); j++) {
            if ((strip[j].second - strip[i].second) * (strip[j].second - strip[i].second) >= minDist) break;

            minDist = min(minDist, getDistance(strip[i], strip[j]));
        }
    }
    return minDist;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <pair <int, int>> sortedX, sortedY;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        sortedX.emplace_back(x, y);
        sortedY.emplace_back(y, x);
    }

    sort(sortedX.begin(), sortedX.end());
    sort(sortedY.begin(), sortedY.end());
    for (auto &[y, x] : sortedY) swap(x, y);

    cout << solve(sortedX, sortedY);
    return 0;
}