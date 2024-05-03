#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 505;
const int INF = 1e9 + 7;

int dist[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) dist[i][j] = INF;
        }
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = dist[b][a] = c;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
    return 0;
}