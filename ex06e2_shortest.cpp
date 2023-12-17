#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, s;
    cin >> N >> M >> s;

    vector <vector <int>> dist(N, vector <int> (N, INF));
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = c;
    }

    dist[s][s] = 0;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < N; i++) if (dist[i][i] < 0) ok = false;

    if (ok == true) {
        for (int i = 0; i < N; i++) cout << dist[s][i] << ' ';
    }
    else cout << "-1";
    return 0;
}