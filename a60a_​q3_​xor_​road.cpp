#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2005;

int x[MAX_N], parent[MAX_N];

int find_parent(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_parent(parent[u]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> x[i];

    vector <tuple <int, int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.emplace_back(x[i] ^ x[j], i, j);
        }
    }

    iota(parent, parent + n, 0);
    sort(edges.rbegin(), edges.rend());

    long long ans = 0;
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