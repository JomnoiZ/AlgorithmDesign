#include <bits/stdc++.h>
using namespace std;

int n, K[8];
vector <pair <int, int>> graph[20];
bool visited[20];

bool solve(const int &u, const int &tw, const int &K) {
    if (tw == K) return true;
    if (tw > K) return false;

    int maxw = tw;
    for (int i = 0; i < n; i++) {
        if (visited[i] == true) continue;

        int opt = 0;
        for (auto &[v, w] : graph[i]) {
            if (opt < w and (visited[v] == false or v == u)) opt = w;
        }
        maxw += opt;
    }
    if (maxw < K) return false;

    for (auto &[v, w] : graph[u]) {
        if (visited[v] == true) continue;

        visited[u] = true;
        bool ok = solve(v, tw + w, K);
        visited[u] = false;

        if (ok == true) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int m;
    cin >> n >> m;

    for (int i = 0; i < 8; i++) cin >> K[i];

    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    for (int i = 0; i < 8; i++) {
        bool ok = false;
        for (int j = 0; j < n; j++) {
            visited[j] = true;
            ok |= solve(j, 0, K[i]);
            visited[j] = false;

            if (ok == true) break;
        }
        if (ok == true) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}