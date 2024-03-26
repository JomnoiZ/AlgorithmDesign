#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void testcase() {
    int R, C, n, T, r, c;
    cin >> R >> C >> n >> T >> r >> c;

    vector <vector <int>> distG(R, vector <int> (C, INF));
    priority_queue <tuple <int, int, int>> pq;
    while (n--) {
        int ti, ri, ci;
        cin >> ti >> ri >> ci;

        if (ti < distG[ri][ci]) {
            distG[ri][ci] = ti;
            pq.emplace(-ti, ri, ci);
        }
    }

    vector <vector <char>> table(R, vector <char> (C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> table[i][j];
        }
    }

    while (!pq.empty()) {
        auto [di, ux, uy] = pq.top();
        pq.pop();

        if (distG[ux][uy] > -di) continue;
        for (int i = 0; i < 4; i++) {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (vx < 0 or vx >= R or vy < 0 or vy >= C or table[vx][vy] == '#') continue;

            if (distG[ux][uy] + 1 < distG[vx][vy]) {
                distG[vx][vy] = distG[ux][uy] + 1;
                pq.emplace(-distG[vx][vy], vx, vy);
            }
        }
    }

    queue <pair <int, int>> q;
    vector <vector <int>> distP(R, vector <int> (C, INF));
    distP[r][c] = 0;
    q.emplace(r, c);
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (vx < 0 or vx >= R or vy < 0 or vy >= C or table[vx][vy] == '#') continue;

            if (distP[vx][vy] == INF and distP[ux][uy] + 1 < distG[vx][vy]) {
                distP[vx][vy] = distP[ux][uy] + 1;
                q.emplace(vx, vy);
            }
        }
    }

    bool ok = false;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (distP[i][j] <= T and T < distG[i][j]) ok = true;
        }
    }

    if (ok == true) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int K;
    cin >> K;

    while (K--) testcase();
    return 0;
}