#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int parent[MAX_N];

int find_parent(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_parent(parent[u]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <tuple <int, int, int>> edges;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int x;
            cin >> x;

            edges.emplace_back(x, i, j);
        }
    }

    iota(parent, parent + N, 0);
    sort(edges.begin(), edges.end());

    int ans = 0;
    for (auto [w, a, b] : edges) {
        int u = find_parent(a), v = find_parent(b);
        if (u != v) {
            ans += w;
            parent[v] = u;
        }
    }
    cout << ans;
    return 0;
}