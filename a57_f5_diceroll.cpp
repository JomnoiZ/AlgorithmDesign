#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C, P, Q;
    cin >> R >> C >> P >> Q;

    vector <int> cost(6);
    for (int i = 0; i < 6; i++) cin >> cost[i];

    vector <vector <map <vector <int>, int>>> dist(R, vector <map <vector <int>, int>> (C));
    vector <vector <map <vector <int>, int>>> cnt(R, vector <map <vector <int>, int>> (C));
    vector <int> p(6);
    iota(p.begin(), p.end(), 0);
    do {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                dist[i][j][p] = INF;
            }
        }
    } while (next_permutation(p.begin(), p.end()));
    
    queue <tuple <int, int, vector <int>>> q;
    vector <int> st({0, 1, 2, 3, 4, 5});
    dist[0][0][st] = 0;
    q.emplace(0, 0, st);
    while (!q.empty()) {
        auto [x, y, u] = q.front();
        q.pop();

        if (++cnt[x][y][u] > R * C * 720) {
            cout << -1;
            return 0;
        }

        if (y - 1 >= 0) {
            vector <int> v(u);
            swap(v[0], v[2]);
            swap(v[1], v[3]);
            swap(v[0], v[1]);
            if (dist[x][y][u] + cost[v[0]] < dist[x][y - 1][v]) {
                dist[x][y - 1][v] = dist[x][y][u] + cost[v[0]];
                q.emplace(x, y - 1, v);
            }
        }
        if (y + 1 < C) {
            vector <int> v(u);
            swap(v[0], v[2]);
            swap(v[1], v[3]);
            swap(v[2], v[3]);
            if (dist[x][y][u] + cost[v[0]] < dist[x][y + 1][v]) {
                dist[x][y + 1][v] = dist[x][y][u] + cost[v[0]];
                q.emplace(x, y + 1, v);
            }
        }
        if (x - 1 >= 0) {
            vector <int> v(u);
            swap(v[0], v[4]);
            swap(v[1], v[5]);
            swap(v[4], v[5]);
            if (dist[x][y][u] + cost[v[0]] < dist[x - 1][y][v]) {
                dist[x - 1][y][v] = dist[x][y][u] + cost[v[0]];
                q.emplace(x - 1, y, v);
            }
        }
        if (x + 1 < R) {
            vector <int> v(u);
            swap(v[0], v[4]);
            swap(v[1], v[5]);
            swap(v[0], v[1]);
            if (dist[x][y][u] + cost[v[0]] < dist[x + 1][y][v]) {
                dist[x + 1][y][v] = dist[x][y][u] + cost[v[0]];
                q.emplace(x + 1, y, v);
            }
        }
    }

    iota(p.begin(), p.end(), 0);
    int ans = INF;
    do {
        ans = min(ans, dist[P][Q][p]);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans;
    return 0;
}