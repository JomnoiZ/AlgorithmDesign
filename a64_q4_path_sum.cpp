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
        if (visited[i] == false and !graph[i].empty()) maxw += graph[i][0].first;
    }
    if (maxw < K) return false;

    for (auto &[w, v] : graph[u]) {
        if (visited[v] == true) continue;

        visited[v] = true;
        bool ok = solve(v, tw + w, K);
        visited[v] = false;

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

        graph[a].emplace_back(w, b);
        graph[b].emplace_back(w, a);
    }

    for (int i = 0; i < n; i++) sort(graph[i].rbegin(), graph[i].rend());

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